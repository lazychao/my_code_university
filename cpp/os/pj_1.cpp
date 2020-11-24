#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include<fstream>
#include<iomanip>
using namespace std;
typedef struct Resource Resource;
class Process;
typedef Process *Process_ptr;
typedef enum Status
{
    ready,
    block,
    running
    //����Ҫ�ֺ�
} Status;
typedef enum RID
{
    R1,
    R2,
    R3,
    R4
    //����Ҫ�ֺ�
} RID;
//�������Ϊ����
typedef struct Resource
{
    RID rid;
    int All;
    int Available;
    list<Process_ptr> Waiting_List;
    Resource(RID _rid, int _All)
    {
        rid = _rid;
        All = _All;
        Available = _All;
    }
} Resource;

typedef struct PCB
{
    string PID; //����
    int hold[4]={0,0,0,0};//�Ѿ�ռ�е���Դ
    int need[4]={0,0,0,0};//ϣ���������Դ
    Status status;
    //ָ��ready LIst ����  Block List
    string PPID;                //����
    list<Process_ptr> Children; //����
    int Priority;
} PCB, *PCB_ptr;
list<Process_ptr> ready_list[3];//д���������ʽ ������list������Ƕ��list
//û�취  д������Ļ�  ��̬���������ʼ��  ���ֲ�֪����ô��ʼ����
list<Process_ptr> blocked_list;
Process_ptr cur_process=NULL;//��ǰ�������н���
Resource RS[4]={Resource(R1,1),Resource(R2,2),Resource(R3,3),Resource(R4,4)};//��ʼ����Դ
list<string> cur_processes;
class Process
{ 
public:
    PCB_ptr pcb;
    static void init();
    static void destroy(string pid);
    static void print_all_ready_process();
    static void print_all_blocked_process();
    static void print_all_process();
    static void kill_tree(Process_ptr p);
    static void time_out();
    static void Scheduler();
    static void remove_from_waiting_list_when_killed(Process_ptr p);
    static void release_resource_when_killed(Process_ptr p);
    void create(string pid, int priority);
    void request(RID rid,int num);
    void release(RID rid,int num);
    void print_this_process();
};
void Process::Scheduler(){
    //�ҵ����ȼ���ߵ�
    Process_ptr max_priority_process=NULL;
    for(int i=2;i>=0;i--){
        if(!ready_list[i].empty()){
            max_priority_process=ready_list[i].front();
            break;
        }
    }
    //�ҵ�������ȼ���֮��  ��ȥ�ҵ�ǰ���еĽ���
    //�л���������  1.��ǰû�����еĽ��� 2.�����ȼ����ߵĽ��� //ng״̬��
    if(cur_process==NULL )    {
        max_priority_process->pcb->status = running;
        cur_process = max_priority_process;
    }
    else if( cur_process->pcb->Priority <max_priority_process->pcb->Priority
    || cur_process->pcb->status!=running)
    {
        max_priority_process->pcb->status = running;
        cur_process->pcb->status = ready;
        //����ǰ���̷ŵ����ȼ�����֮�����
        //�ȳ��������
        ready_list[cur_process->pcb->Priority].pop_front();
        ready_list[cur_process->pcb->Priority].push_back(cur_process);
        cur_process = max_priority_process;
    }

    else{
        // cout<<"exception";
    }
    // cout<<"��ǰ���н��̣�";
    // cur_process->print_this_process();
    //cout<<cur_process->pcb->PID<<" ";
    cur_processes.push_back(cur_process->pcb->PID);
}

void Process::create(string pid, int priority)
{
    //�������̲��ҳ�ʼpcb
    Process_ptr new_process = new Process;
    PCB_ptr new_pcb = new PCB;
    new_pcb->PID = pid;
    new_pcb->Priority = priority;
    new_pcb->status = ready;
    new_pcb->PPID = (this->pcb)->PID;

    new_process->pcb = new_pcb;
    //�Ѵ����Ľ��̷ŵ������̵�creation tree
    this->pcb->Children.push_back(new_process);
    //���뵽��Ӧ���ȼ����е�β��
    ready_list[priority].push_back(new_process);
    Scheduler();
}


void Process::init(){
    Process_ptr new_process = new Process;
    PCB_ptr new_pcb = new PCB;
    new_pcb->PID = "init";
    new_pcb->Priority = 0;
    new_pcb->status = ready;
    new_pcb->PPID = "";//������Ϊ��

    new_process->pcb = new_pcb;
    //�Ѵ����Ľ��̷ŵ������̵�creation tree
    // this->pcb->Children.push_back(new_process);
    // //���뵽��Ӧ���ȼ����е�β��
    ready_list[0].push_back(new_process);

    Scheduler();
}
void Process::print_this_process(){
    cout<<"pid:"<<pcb->PID<<"   status:"<<pcb->status<<"   PPID:"<<pcb->PPID<<"   Priority:"<<pcb->Priority<<endl;
}
void Process::print_all_ready_process(){
    for (int i = 0; i < 3; i++)
    {
        if(!ready_list[i].empty()){
            cout<<"priority="<<i<<":"<<endl;
            list<Process_ptr>::iterator itor;
            for(itor = ready_list[i].begin();itor!=ready_list[i].end();itor++){
                cout<<"pid:"<<(*itor)->pcb->PID<<"   status:"<<(*itor)->pcb->status<<"   PPID:"<<(*itor)->pcb->PPID<<"   Priority:"<<(*itor)->pcb->Priority<<endl;
            } 
        }
    }
}
void Process::print_all_blocked_process(){
    if(!blocked_list.empty()){
            cout<<"blocked"<<": "<<endl;
            list<Process_ptr>::iterator itor;
            for(itor = blocked_list.begin();itor!=blocked_list.end();itor++){
                cout<<"pid:"<<(*itor)->pcb->PID<<"   status:"<<(*itor)->pcb->status<<"   PPID:"<<(*itor)->pcb->PPID<<"   Priority:"<<(*itor)->pcb->Priority<<endl;
            } 
        }
}
void Process::print_all_process(){
    cout<<"print---------------------------"<<endl;
    print_all_ready_process();
    print_all_blocked_process();
}
void Process::remove_from_waiting_list_when_killed(Process_ptr p){
    for (int i = 0; i < 4; i++)
    {
        if(p->pcb->need[i]!=0)
        {
            RS[i].Waiting_List.remove(p);
        }
    }
}
void Process::release_resource_when_killed(Process_ptr p){
    //ֻ��Ҫ���ѾͿ����˲���Ҫ�ͷ�
    for (int i = 0; i < 4; i++)
    {
        if(p->pcb->hold[i]!=0)
        {
            RS[i].Available+=p->pcb->hold[i];
            //Ҫ���������л���  ��֤˳��   ����������Դ����
           
        }
    }
    //  while(!RS[i].Waiting_List.empty()&&
    //         RS[i].Available>=RS[i].Waiting_List.front()->pcb->need[i]){
    //             //���ѽ���
    //             RS[i].Available-=RS[i].Waiting_List.front()->pcb->need[i];
    //             RS[i].Waiting_List.front()->pcb->hold[i]+=RS[i].Waiting_List.front()->pcb->need[i];
    //             RS[i].Waiting_List.front()->pcb->need[i]=0;
    //             RS[i].Waiting_List.front()->pcb->status=ready;
    //             //�޸�pcb���� ����������
    //             blocked_list.remove(RS[i].Waiting_List.front());
    //             ready_list[RS[i].Waiting_List.front()->pcb->Priority].push_back(RS[i].Waiting_List.front());
    //             RS[i].Waiting_List.pop_front();
    //         }
           
}
void Process::kill_tree(Process_ptr p){
    remove_from_waiting_list_when_killed(p);
    release_resource_when_killed(p);
    if(p==cur_process){
        cur_process=NULL;//������ִ�еĽ���ɱ����
    }
    if(p->pcb->Children.empty()){
        //����Ϊ�� ֱ�ӷ���
        return;
    }
    
    //���ѭ��ɾ��list�е�Ԫ��  ������仯
    list<Process_ptr>::iterator itor;
    //itor���üӼӣ�
    //����remove erase �᷵����һ��itor
    for(itor = p->pcb->Children.begin();itor!=p->pcb->Children.end();){
        //ɾ�������ڵ��������߾�������
        for(int i=0;i<3;i++){
            ready_list[i].remove(*itor);
        }
        blocked_list.remove(*itor);
        kill_tree(*itor);
        delete ((*itor)->pcb);
        delete (*itor);
        itor = p->pcb->Children.erase(itor);
    }
}
void Process::destroy(string pid){
    if(pid.compare("init")==0){
        cout << "����ɾ��init";
        exit(0);
    }
    Process_ptr temp_p=NULL;
    int flag = 0;
    list<Process_ptr>::iterator itor;
    if(!blocked_list.empty()){
        for(itor = blocked_list.begin();itor!=blocked_list.end();itor++){
            if((*itor)->pcb->PID.compare(pid)==0)
            {
                temp_p=(*itor);
                blocked_list.remove(temp_p);
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        for (int i = 0; i < 3; i++)
        {
            if(!ready_list[i].empty()){
                list<Process_ptr>::iterator itor;
                for(itor = ready_list[i].begin();itor!=ready_list[i].end();itor++){
                    if((*itor)->pcb->PID.compare(pid)==0)
                    {
                        temp_p=(*itor);
                        ready_list[i].remove(temp_p);
                        break;
                    }
            } 
            }
        }
    }
    //�ҵ�Ҫɾ���Ľ���ָ���� ɾ�����ھ��������������У�
    //�����������ڵľ�������
    //ɾ��������������У�ɾ�����ڸ����̵Ķ��Ӷ�����
    //ɾ�������ж��ӽڵ�

    //�ͷſռ�

    /*
        ɾ���������������
    */
    /*
        ɾ�����ڸ����̵Ķ��Ӷ�����
    */
   //����Ѱ�Ҹ�����
     int fflag=0;
     if(temp_p==cur_process){
        cur_process=NULL;//������ִ�еĽ���ɱ����
    }
    Process_ptr temp_f_p = NULL;
    string ppid = temp_p->pcb->PPID;
    for (itor = blocked_list.begin(); itor != blocked_list.end(); itor++)
    {
        if((*itor)->pcb->PID.compare(ppid)==0)
        {
            temp_f_p=(*itor);
           fflag=1;
            break;
        }
    }

   if(fflag==0){
        for (int i = 0; i < 3; i++)
        {
            if(!ready_list[i].empty()){
                list<Process_ptr>::iterator itor;
                for(itor = ready_list[i].begin();itor!=ready_list[i].end();itor++){
                    if((*itor)->pcb->PID.compare(ppid)==0)
                    {
                        temp_f_p=(*itor);
                        break;
                    }
            } 
            }
        }
    }



    //�ҵ�������  temp_f_p �ں�����ɾ��
    temp_f_p->pcb->Children.remove(temp_p);

    //ɾ�����ӽ���
    //�ݹ�ɾ������
    kill_tree(temp_p);
    //���ѽ���
    for(itor = blocked_list.begin();itor!=blocked_list.end();){
                int flag = 0;
           // cout <<"�����ģ�"<< (*itor)->pcb->PID<<endl;
                for (int i = 0; i < 4; i++)
                {
                    if((*itor)->pcb->need[i]>0){//������Դ�Ƿ���Ҫ��
                        if( RS[i].Available>=(*itor)->pcb->need[i]){
                           // cout <<"���ѵģ�"<< (*itor)->pcb->PID<<"��Դ���"<<i<<endl;
                            (*itor)->pcb->hold[i] = (*itor)->pcb->need[i];         
                            RS[i].Available-=(*itor)->pcb->need[i];
                            (*itor)->pcb->need[i] =0 ;
                            //ɾ������waitinglist
                            RS[i].Waiting_List.pop_front();
                            //���뵽��������
                            ready_list[(*itor)->pcb->Priority].push_back((*itor));
                            //������������ɾ��
                            itor = blocked_list.erase(itor);
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==0){
                    itor++;
                }
                else{

                }
               
            }

    //���ɾ���Լ�
    delete temp_p->pcb;
    delete temp_p;

    Scheduler();
}
void Process::request(RID rid,int num){
    if(RS[rid].Available>=num){
        //���㹻�����Դ����
        RS[rid].Available = RS[rid].Available - num;
        pcb->hold[rid]+=num;//��ӵ�pcb��
        Scheduler();
        //cout<<pcb->PID<<":"<<"rid:"<<rid<< pcb->hold[rid]<<endl;
    }
    else{
        //��Դ���� ��Ҫ����  �ŵ�waiting_list  Ȼ��schedule
        RS[rid].Waiting_List.push_back(cur_process);
        pcb->status = block;
        pcb->need[rid]=num;
        for(int i=0;i<3;i++){
            ready_list[i].remove(cur_process);
        }
        blocked_list.push_back(cur_process);
        cur_process = NULL;
        Scheduler();
    }
}
void Process::release(RID rid,int num){
    if(pcb->hold[rid]<num){
        cout<<"release too much"<<endl;
        //cout<<pcb->PID<<":"<<"rid:"<<rid<< pcb->hold[rid]<<endl;
        return;
    }
    RS[rid].Available+=num;
    pcb->hold[rid] -= num;
    //���ѽ���
    if(!RS[rid].Waiting_List.empty()&&
    RS[rid].Available>=RS[rid].Waiting_List.front()->pcb->need[rid]){
        //���ѽ���
        RS[rid].Available-=RS[rid].Waiting_List.front()->pcb->need[rid];
        RS[rid].Waiting_List.front()->pcb->hold[rid]+=RS[rid].Waiting_List.front()->pcb->need[rid];
        RS[rid].Waiting_List.front()->pcb->need[rid]=0;
        RS[rid].Waiting_List.front()->pcb->status=ready;
        //�޸�pcb���� ����������
        blocked_list.remove(RS[rid].Waiting_List.front());
        ready_list[RS[rid].Waiting_List.front()->pcb->Priority].push_back(RS[rid].Waiting_List.front());
        RS[rid].Waiting_List.pop_front();
    }
    Scheduler();
}
void Process::time_out(){
    ready_list[cur_process->pcb->Priority].pop_front();
    ready_list[cur_process->pcb->Priority].push_back(cur_process);
    cur_process->pcb->status=ready;
    cur_process = NULL;
    Scheduler();
}
int main(int argc, char* argv[]){
    //��νṹ���������ù��캯����ʼ��
    Process::init();//������һ������
    ifstream ifile;   
    ifile.open(argv[1]);
    string c1,c2;
    int num;
    while (ifile>>c1)
    {
        if(c1.compare("to")==0){
            Process::time_out();
        }
        else if(c1.compare("cr")==0){
            ifile>> c2>>num ;
            cur_process->create(c2,num);
        }
        else if(c1.compare("de")==0){
            ifile>> c2;
            Process::destroy(c2);
        }
        else if(c1.compare("req")==0){ 
            ifile>>c2>>num;
            if (c2.compare("R1") == 0)
            {
                cur_process->request(R1, num);
            }
             if(c2.compare("R2")==0){
                cur_process->request(R2,num);             
            }
             if(c2.compare("R3")==0){
                cur_process->request(R3,num);
            }
             if(c2.compare("R4")==0){
                cur_process->request(R4,num);
            }
        }
        else if(c1.compare("rel")==0){
            ifile>>c2>>num;
              if(c2.compare("R1")==0){
                cur_process->release(R1,num);
            }
              if(c2.compare("R2")==0){
                cur_process->release(R2,num);
            }
              if(c2.compare("R3")==0){
                cur_process->release(R3,num);
            }
              if(c2.compare("R4")==0){
                cur_process->release(R4,num);
            }
        }
        else{   
            cout<<"????";
        }
    
    }

    list<string>::iterator itor;
    for(itor = cur_processes.begin();itor!=cur_processes.end();itor++){
        cout<<(*itor)<<" ";
    }
    return 0;
}