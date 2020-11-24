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
    //不需要分号
} Status;
typedef enum RID
{
    R1,
    R2,
    R3,
    R4
    //不需要分号
} RID;
//定义进程为对象
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
    string PID; //名字
    int hold[4]={0,0,0,0};//已经占有的资源
    int need[4]={0,0,0,0};//希望申请的资源
    Status status;
    //指向ready LIst 或者  Block List
    string PPID;                //父亲
    list<Process_ptr> Children; //孩子
    int Priority;
} PCB, *PCB_ptr;
list<Process_ptr> ready_list[3];//写成数组的形式 而不是list里面再嵌套list
//没办法  写在类里的话  静态变量必须初始化  但又不知道怎么初始化话
list<Process_ptr> blocked_list;
Process_ptr cur_process=NULL;//当前正在运行进程
Resource RS[4]={Resource(R1,1),Resource(R2,2),Resource(R3,3),Resource(R4,4)};//初始化资源
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
    //找到优先级最高的
    Process_ptr max_priority_process=NULL;
    for(int i=2;i>=0;i--){
        if(!ready_list[i].empty()){
            max_priority_process=ready_list[i].front();
            break;
        }
    }
    //找到最高优先级的之后  再去找当前运行的进程
    //切换的条件有  1.当前没有运行的进程 2.有优先级更高的进程 //ng状态了
    if(cur_process==NULL )    {
        max_priority_process->pcb->status = running;
        cur_process = max_priority_process;
    }
    else if( cur_process->pcb->Priority <max_priority_process->pcb->Priority
    || cur_process->pcb->status!=running)
    {
        max_priority_process->pcb->status = running;
        cur_process->pcb->status = ready;
        //将当前进程放到优先级队列之后最后
        //先出队再入队
        ready_list[cur_process->pcb->Priority].pop_front();
        ready_list[cur_process->pcb->Priority].push_back(cur_process);
        cur_process = max_priority_process;
    }

    else{
        // cout<<"exception";
    }
    // cout<<"当前运行进程：";
    // cur_process->print_this_process();
    //cout<<cur_process->pcb->PID<<" ";
    cur_processes.push_back(cur_process->pcb->PID);
}

void Process::create(string pid, int priority)
{
    //创建进程并且初始pcb
    Process_ptr new_process = new Process;
    PCB_ptr new_pcb = new PCB;
    new_pcb->PID = pid;
    new_pcb->Priority = priority;
    new_pcb->status = ready;
    new_pcb->PPID = (this->pcb)->PID;

    new_process->pcb = new_pcb;
    //把创建的进程放到父进程的creation tree
    this->pcb->Children.push_back(new_process);
    //插入到相应优先级队列的尾部
    ready_list[priority].push_back(new_process);
    Scheduler();
}


void Process::init(){
    Process_ptr new_process = new Process;
    PCB_ptr new_pcb = new PCB;
    new_pcb->PID = "init";
    new_pcb->Priority = 0;
    new_pcb->status = ready;
    new_pcb->PPID = "";//父进程为空

    new_process->pcb = new_pcb;
    //把创建的进程放到父进程的creation tree
    // this->pcb->Children.push_back(new_process);
    // //插入到相应优先级队列的尾部
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
    //只需要唤醒就可以了不需要释放
    for (int i = 0; i < 4; i++)
    {
        if(p->pcb->hold[i]!=0)
        {
            RS[i].Available+=p->pcb->hold[i];
            //要在阻塞队列唤醒  保证顺序   而不是在资源那里
           
        }
    }
    //  while(!RS[i].Waiting_List.empty()&&
    //         RS[i].Available>=RS[i].Waiting_List.front()->pcb->need[i]){
    //             //唤醒进程
    //             RS[i].Available-=RS[i].Waiting_List.front()->pcb->need[i];
    //             RS[i].Waiting_List.front()->pcb->hold[i]+=RS[i].Waiting_List.front()->pcb->need[i];
    //             RS[i].Waiting_List.front()->pcb->need[i]=0;
    //             RS[i].Waiting_List.front()->pcb->status=ready;
    //             //修改pcb后将其 从阻塞队列
    //             blocked_list.remove(RS[i].Waiting_List.front());
    //             ready_list[RS[i].Waiting_List.front()->pcb->Priority].push_back(RS[i].Waiting_List.front());
    //             RS[i].Waiting_List.pop_front();
    //         }
           
}
void Process::kill_tree(Process_ptr p){
    remove_from_waiting_list_when_killed(p);
    release_resource_when_killed(p);
    if(p==cur_process){
        cur_process=NULL;//把正在执行的进程杀死了
    }
    if(p->pcb->Children.empty()){
        //孩子为空 直接返回
        return;
    }
    
    //如何循环删除list中的元素  索引会变化
    list<Process_ptr>::iterator itor;
    //itor不用加加？
    //不用remove erase 会返回下一个itor
    for(itor = p->pcb->Children.begin();itor!=p->pcb->Children.end();){
        //删除其所在的阻塞或者就绪队列
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
        cout << "不能删除init";
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
    //找到要删除的进程指针了 删除其在就绪或阻塞队列中，
    //包括儿子所在的就绪队列
    //删除其在申请队列中，删除其在父进程的儿子队列中
    //删除其所有儿子节点

    //释放空间

    /*
        删除其在申请队列中
    */
    /*
        删除其在父进程的儿子队列中
    */
   //首先寻找父进程
     int fflag=0;
     if(temp_p==cur_process){
        cur_process=NULL;//把正在执行的进程杀死了
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



    //找到父进程  temp_f_p 在孩子中删除
    temp_f_p->pcb->Children.remove(temp_p);

    //删除孩子进程
    //递归删除孩子
    kill_tree(temp_p);
    //唤醒进程
    for(itor = blocked_list.begin();itor!=blocked_list.end();){
                int flag = 0;
           // cout <<"阻塞的："<< (*itor)->pcb->PID<<endl;
                for (int i = 0; i < 4; i++)
                {
                    if((*itor)->pcb->need[i]>0){//这类资源是否需要，
                        if( RS[i].Available>=(*itor)->pcb->need[i]){
                           // cout <<"唤醒的："<< (*itor)->pcb->PID<<"资源类别"<<i<<endl;
                            (*itor)->pcb->hold[i] = (*itor)->pcb->need[i];         
                            RS[i].Available-=(*itor)->pcb->need[i];
                            (*itor)->pcb->need[i] =0 ;
                            //删除其在waitinglist
                            RS[i].Waiting_List.pop_front();
                            //加入到就绪队列
                            ready_list[(*itor)->pcb->Priority].push_back((*itor));
                            //在阻塞队列中删除
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

    //最后删除自己
    delete temp_p->pcb;
    delete temp_p;

    Scheduler();
}
void Process::request(RID rid,int num){
    if(RS[rid].Available>=num){
        //有足够多的资源分配
        RS[rid].Available = RS[rid].Available - num;
        pcb->hold[rid]+=num;//添加到pcb里
        Scheduler();
        //cout<<pcb->PID<<":"<<"rid:"<<rid<< pcb->hold[rid]<<endl;
    }
    else{
        //资源不够 需要阻塞  放到waiting_list  然后schedule
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
    //唤醒进程
    if(!RS[rid].Waiting_List.empty()&&
    RS[rid].Available>=RS[rid].Waiting_List.front()->pcb->need[rid]){
        //唤醒进程
        RS[rid].Available-=RS[rid].Waiting_List.front()->pcb->need[rid];
        RS[rid].Waiting_List.front()->pcb->hold[rid]+=RS[rid].Waiting_List.front()->pcb->need[rid];
        RS[rid].Waiting_List.front()->pcb->need[rid]=0;
        RS[rid].Waiting_List.front()->pcb->status=ready;
        //修改pcb后将其 从阻塞队列
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
    //如何结构体数组利用构造函数初始化
    Process::init();//创建第一个进程
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