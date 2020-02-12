import pygame
import os
import time
from pygame.locals import *
from sys import exit
from random import randint
from GameMap import *
from MazeGenerator import *
#from AStarSearch import *

REC_SIZE = 20
REC_WIDTH = 31  # must be odd number
REC_HEIGHT = 31  # must be odd number
BUTTON_HEIGHT = 30
BUTTON_WIDTH = 120
SCREEN_WIDTH = REC_WIDTH * REC_SIZE
SCREEN_HEIGHT = REC_HEIGHT * REC_SIZE + BUTTON_HEIGHT


class Bullet():
    global hero
    global game

    def __init__(self, dir):
        self.curx, self.cury = hero.get_curpos()
        self.state = True
        self.dir = dir

    def fly(self):
        if self.state:
            if game.map.isenemy(self.curx + self.dir[0],
                                self.cury + self.dir[1]):
                if game.map.ishero(self.curx, self.cury) == 0:
                    game.map.setMap(self.curx, self.cury,
                                    MAP_ENTRY_TYPE.MAP_EMPTY)
                game.map.setMap(self.curx + self.dir[0],
                                self.cury + self.dir[1],
                                MAP_ENTRY_TYPE.MAP_EMPTY)
                self.state = False
            elif game.bullet_move(self.curx, self.cury, self.dir[0],
                                  self.dir[1]):  #state为True时子弹未消失
                self.curx += self.dir[0]
                self.cury += self.dir[1]
            else:
                self.state = False

    def get_state(self):
        return self.state


class Enemy_Bullet():
    global hero
    global game

    def __init__(self, curx, cury, dirx, diry):
        self.curx = curx
        self.cury = cury
        self.state = True
        self.dirx = dirx
        self.diry = diry
        self.count = 0  #目的是减慢速度

    def fly(self):
        if self.state:
            if self.count > 10:
                # if game.map.ishero(self.curx+self.dirx, self.cury+self.diry):
                #     game.map.setMap(self.curx, self.cury, MAP_ENTRY_TYPE.MAP_EMPTY)
                #     game.map.setMap(self.curx+self.dirx, self.cury+self.diry, MAP_ENTRY_TYPE.MAP_EMPTY)
                #     self.state = False
                # elif game.bullet_move(self.curx, self.cury,self.dir[0] ,self.dir[1]):#state为True时子弹未消失
                #     self.curx += self.dir[0]
                #     self.cury += self.dir[1]
                if game.draw_enemy_bullet(self.curx, self.cury, self.dirx,
                                          self.diry):
                    self.curx = self.curx + self.dirx
                    self.cury = self.cury + self.diry
                    self.count = 0
                else:
                    self.state = False
            self.count += 1

    def get_state(self):
        return self.state


class Enemy():
    global game

    def __init__(self):
        self.count = 0  #计数器  目的使其运动速度减缓
        self.curx = randint(1, REC_HEIGHT - 2)
        self.cury = randint(1, REC_HEIGHT - 2)
        self.dirx = 0
        self.diry = 0
        self.random_pos()
        self.state = True

    def random_pos(self):
        while game.map.isempty(self.curx, self.cury) == 0:
            self.curx = randint(1, 1000) % (REC_HEIGHT - 2) + 1
            self.cury = randint(1, 1000) % (REC_HEIGHT - 2) + 1
        game.map.setMap(self.curx, self.cury, MAP_ENTRY_TYPE.MAP_ENEMY)

    # def draw_enemy(self):
    #     self.count+=1
    #     if self.count>=60:
    #         self.random_dir()
    #         game.draw_enemy(self.curx, self.cury,self.dirx,self.diry)
    #         self.curx=self.curx+self.dirx
    #         self.cury=self.cury+self.diry
    #         self.count = 0
    def attack(self):
        self.count += 1
        if self.count >= 20:
            self.random_dir()
            bullet = Enemy_Bullet(self.curx, self.cury, self.dirx, self.diry)
            game.enenmy_bullets.append(bullet)
            self.count = 0

    def get_state(self):
        if game.map.isempty(self.curx, self.cury):
            return False
        else:
            return True

    def random_dir(self):  #随机生成一个方向
        i = randint(1, 4)
        if i == 1:
            self.dirx = 0
            self.diry = 1
        elif i == 2:
            self.dirx = 0
            self.diry = -1
        elif i == 3:
            self.dirx = 1
            self.diry = 0
        else:
            self.dirx = -1
            self.diry = 0
        while game.map.isMovable(self.curx + self.dirx,
                                 self.cury + self.diry) == 0:
            i = randint(1, 4)
            if i == 1:
                self.dirx = 0
                self.diry = 1
            elif i == 2:
                self.dirx = 0
                self.diry = -1
            elif i == 3:
                self.dirx = 1
                self.diry = 0
            else:
                self.dirx = -1
                self.diry = 0


class Hero():  #坐标要是横为x,竖为y 会有函数映射到数组中的
    global game

    def __init__(self, curx, cury):
        self.curx = curx  #当前位置
        self.cury = cury
        self.bullets = []  #已产生的子弹
        self.enemies = []  #已产生的敌人
    def del_enemies(self):
        self.enemies = []
        game.map.setMap(self.curx ,self.cury,MAP_ENTRY_TYPE.MAP_EMPTY)
    def react(self, react_type):
        if (react_type == K_s or react_type == K_d or react_type == K_a
                or react_type == K_w):
            time.sleep(0.1)
            self.move(react_type)
        else:
            time.sleep(0.1)
            self.attack(react_type)

    def move(self, movetype):
        if movetype == K_s:
            if (game.hero_move(self.curx, self.cury, 0, 1)):
                self.cury += 1
        elif movetype == K_w:
            if (game.hero_move(self.curx, self.cury, 0, -1)):
                self.cury -= 1
        elif movetype == K_a:
            if (game.hero_move(self.curx, self.cury, -1, 0)):
                self.curx -= 1
        else:
            if (game.hero_move(self.curx, self.cury, 1, 0)):
                self.curx += 1

    def attack(self, attack_dir):
        if attack_dir == K_DOWN:
            dir = [0, 1]
        elif attack_dir == K_UP:
            dir = [0, -1]
        elif attack_dir == K_LEFT:
            dir = [-1, 0]
        else:
            dir = [1, 0]
        bullet = Bullet(dir)
        self.bullets.append(bullet)

    def get_curpos(self):
        return self.curx, self.cury
    def set_curpos(self):
        self.curx=1
        self.cury=1

class Button():
    def __init__(self, screen, type, x, y):
        self.screen = screen
        self.width = BUTTON_WIDTH
        self.height = BUTTON_HEIGHT
        self.button_color = (128, 128, 128)
        self.text_color = [(0, 255, 0), (255, 0, 0)]
        self.font = pygame.font.SysFont(None, BUTTON_HEIGHT * 2 // 3)

        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.topleft = (x, y)
        self.type = type
        self.init_msg()

    def init_msg(self):
        self.msg_image = self.font.render(generator_types[self.type], True,
                                          self.text_color[0],
                                          self.button_color)
        self.msg_image_rect = self.msg_image.get_rect()
        self.msg_image_rect.center = self.rect.center

    def draw(self):
        self.screen.fill(self.button_color, self.rect)
        self.screen.blit(self.msg_image, self.msg_image_rect)

    def click(self, game):
        game.maze_type = self.type
        self.msg_image = self.font.render(generator_types[self.type], True,
                                          self.text_color[1],
                                          self.button_color)

    def unclick(self):
        self.msg_image = self.font.render(generator_types[self.type], True,
                                          self.text_color[0],
                                          self.button_color)


class Game():
    global hero

    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode([SCREEN_WIDTH, SCREEN_HEIGHT])
        self.clock = pygame.time.Clock()
        self.map = Map(REC_WIDTH, REC_HEIGHT)
        self.mode = 0
        self.maze_type = MAZE_GENERATOR_TYPE.RANDOM_PRIM
        self.buttons = []  #这里面放四个按钮对象
        self.buttons.append(
            Button(self.screen, MAZE_GENERATOR_TYPE.RECURSIVE_BACKTRACKER, 0,
                   0))
        self.buttons.append(
            Button(self.screen, MAZE_GENERATOR_TYPE.RANDOM_PRIM,
                   BUTTON_WIDTH + 10, 0))
        self.buttons.append(
            Button(self.screen, MAZE_GENERATOR_TYPE.RECURSIVE_DIVISION,
                   (BUTTON_WIDTH + 10) * 2, 0))
        self.buttons.append(
            Button(self.screen, MAZE_GENERATOR_TYPE.UNION_FIND_SET,
                   (BUTTON_WIDTH + 10) * 3, 0))
        self.buttons[0].click(self)
        self.enenmy_bullets = []

    def play(self):
        self.clock.tick(30)

        pygame.draw.rect(self.screen, (255, 255, 255),
                         pygame.Rect(0, 0, SCREEN_WIDTH, BUTTON_HEIGHT))
        for button in self.buttons:
            button.draw()
        #画图
        for y in range(self.map.height):
            for x in range(self.map.width):
                type = self.map.getType(x, y)
                if type == MAP_ENTRY_TYPE.MAP_EMPTY:  #route
                    color = (255, 255, 255)
                elif type == MAP_ENTRY_TYPE.MAP_BLOCK:  #wall
                    color = (0, 0, 0)
                    continue

                elif type == MAP_ENTRY_TYPE.MAP_TARGET:  #hero
                    color = (255, 0, 0)
                    self.ShowImage(he, REC_SIZE * x,
                                   REC_SIZE * y + BUTTON_HEIGHT)
                    continue
                elif type == MAP_ENTRY_TYPE.MAP_ENEMY:  #enemy
                    color = (0, 0, 255)
                    self.ShowImage(volcano, REC_SIZE * x,
                                   REC_SIZE * y + BUTTON_HEIGHT)
                    continue
                elif type == MAP_ENTRY_TYPE.MAP_DEST:
                    color = (0, 0, 0)
                elif type == MAP_ENTRY_TYPE.MAP_BULLET_ENEMY:
                    color = (255, 0, 255)
                else:  #bullet
                    color = (0, 255, 0)
                    self.ShowImage(fireball, REC_SIZE * x,
                                   REC_SIZE * y + BUTTON_HEIGHT)
                    continue
                pygame.draw.rect(
                    self.screen, color,
                    pygame.Rect(REC_SIZE * x, REC_SIZE * y + BUTTON_HEIGHT,
                                REC_SIZE, REC_SIZE))
    def del_bullet(self):
        self.enenmy_bullets = []
    def ShowImage(self, img, x, y):
        self.screen.blit(img, (x, y))
        pygame.display.update()

    def generateMaze(self):
        # if self.mode >= 4:
        #     self.mode = 0
        # if self.mode == 0:
        self.map.resetMap(MAP_ENTRY_TYPE.MAP_EMPTY)
        generateMap(self.map, self.maze_type)
        # elif self.mode == 1:
        # self.source = self.map.generatePos((1, 1), (1, self.map.height - 2))
        # self.dest = self.map.generatePos((self.map.width - 2, self.map.width - 2), (1, self.map.height - 2))
        self.source = (1, 1)
        self.dest = (self.map.width - 2, self.map.height - 2)
        self.map.setMap(self.source[0], self.source[1],
                        MAP_ENTRY_TYPE.MAP_TARGET)
        self.map.setMap(self.dest[0], self.dest[1], MAP_ENTRY_TYPE.MAP_DEST)
        # elif self.mode == 2:
        #     AStarSearch(self.map, self.source, self.dest)
        #     self.map.setMap(self.source[0], self.source[1], MAP_ENTRY_TYPE.MAP_TARGET)
        #     self.map.setMap(self.dest[0], self.dest[1], MAP_ENTRY_TYPE.MAP_TARGET)
        # else:
        #     self.map.resetMap(MAP_ENTRY_TYPE.MAP_EMPTY)
        # self.mode += 1

    def draw_enemy_bullet(self, posx, posy, dirx, diry):
        if self.map.ishero(posx + dirx, posy + diry):
            self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)
            self.del_bullet()
            hero.set_curpos()
            hero.del_enemies()
            game.generateMaze()
            wall_draw()
            self.map.setMap(posx + dirx,posy + diry, MAP_ENTRY_TYPE.MAP_EMPTY)

        elif self.map.isempty(posx + dirx, posy + diry):
            if game.map.isenemy(posx, posy) == 0 and game.map.ishero(
                    posx, posy) == 0:
                self.map.setMap(posx, posy,
                                MAP_ENTRY_TYPE.MAP_EMPTY)  # 将经过的路置为空白
            self.map.setMap(posx + dirx, posy + diry,
                            MAP_ENTRY_TYPE.MAP_BULLET_ENEMY)
            return True
        else:
            if game.map.isenemy(posx, posy) == 0 and game.map.ishero(
                    posx, posy) == 0:
                self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)
            return False

    def draw_enemy(self, posx, posy, dirx, diry):
        if self.map.ishero(posx + dirx, posy + diry):
            self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)
            pygame.quit()
            exit()
        self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)  # 把原来的变成路径
        self.map.setMap(posx + dirx, posy + diry, MAP_ENTRY_TYPE.MAP_ENEMY)

    # def draw_empty(self,posx,posy):
    #     if self.map.isempty(posx, posy)!=0:
    #         self.map.setMap(posx , posy, MAP_ENTRY_TYPE.MAP_EMPTY)
    def bullet_move(self, posx, posy, dirx, diry):
        herox, heroy = hero.get_curpos()
        if self.map.isMovable(posx + dirx, posy + diry):
            if herox != posx or heroy != posy:
                self.map.setMap(posx, posy,
                                MAP_ENTRY_TYPE.MAP_EMPTY)  #将经过的路置为空白
            self.map.setMap(posx + dirx, posy + diry,
                            MAP_ENTRY_TYPE.MAP_BULLET)
            return True
        else:
            if herox != posx or heroy != posy:
                self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)
            return False

    def hero_move(self, posx, posy, movex, movey):
        if self.map.iseaten(posx+movex, posy+movey) or self.map.isend(posx+movex, posy+movey)\
                or self.map.isbullet_enemy(posx+movex, posy+movey):
            # self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)
            # pygame.quit()
            # exit()
            self.del_bullet()
            hero.set_curpos()
            hero.del_enemies()
            game.generateMaze()
            wall_draw()
        elif self.map.isMovable(posx + movex, posy + movey):
            self.map.setMap(posx, posy, MAP_ENTRY_TYPE.MAP_EMPTY)  #把原来的变成路径
            self.map.setMap(posx + movex, posy + movey,
                            MAP_ENTRY_TYPE.MAP_TARGET)
            return True
        return False


def check_buttons(game, mouse_x, mouse_y):
    for button in game.buttons:
        if button.rect.collidepoint(mouse_x, mouse_y):
            button.click(game)
            for tmp in game.buttons:
                if tmp != button:
                    tmp.unclick()
            break


count = 0  #用于长按键盘持续相应
game = Game()
global hero
hero = Hero(1, 1)

game.generateMaze()
volcano = pygame.image.load('volcano.png')
fireball = pygame.image.load('fireball.png')
he = pygame.image.load('hero.png')
wall = pygame.image.load('wall.png')
mixer = pygame.mixer
mixer.init(22050)
music = mixer.music


def playMusic(name):
    music.load(name)
    music.set_volume(10)
    music.play()
    while (music.get_busy()):
        pass
        #time.sleep(1)
    music.stop()


def playSound(file_path):
    sound = mixer.Sound(file_path)
    sound.set_volume(50)
    channel = sound.play()
    # print( sound.get_length() )
    # while channel.get_busy() :
    #pygame.event.wait()
    #time.sleep(2)
    sound.stop()

def wall_draw():
    for y in range(game.map.height):
        for x in range(game.map.width):
            type = game.map.getType(x, y)
            if type == MAP_ENTRY_TYPE.MAP_BLOCK:
                game.ShowImage(wall, REC_SIZE * x, REC_SIZE * y + BUTTON_HEIGHT)
now_k=0
wall_draw()
while True:
    game.play()
    #pygame.display.update()

    i = 0
    while i < len(hero.bullets):
        if hero.bullets[i].get_state():
            hero.bullets[i].fly()
            i += 1
        else:
            del hero.bullets[i]  ##超级bug，，删除一个元素后后面的下标都变了！！！！
    i = 0
    while i < len(hero.enemies):
        if hero.enemies[i].get_state():
            hero.enemies[i].attack()
            i += 1
        else:
            del hero.enemies[i]  ##超级bug，，删除一个元素后后面的下标都变了！！！！
            path = os.path
            curr_dir = path.dirname(path.abspath(__file__))
            pygame.mixer.music.load('swim.wav')  #设置为背景音乐就不卡了。。。
            pygame.mixer.music.set_volume(0.2)  #设置音量
            pygame.mixer.music.play()  #播放
            #file_path = path.join(curr_dir, 'swim.wav')
            #playSound(file_path)

    while i < len(game.enenmy_bullets):
        if game.enenmy_bullets[i].get_state():
            game.enenmy_bullets[i].fly()
            i += 1
        else:
            del game.enenmy_bullets[i]  ##超级bug，，删除一个元素后后面的下标都变了！！！！

    if len(hero.enemies) < 20:  #把敌人控制在10个以内
        enemy = Enemy()
        hero.enemies.append(enemy)

    if count > 0:
        hero.react(now_k)

    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            pygame.quit()

            exit()

        if event.type == pygame.KEYDOWN:
            now_k= event.key
            if event.key == K_r:
                hero.del_enemies()
                game.del_bullet()
                game.generateMaze()
                hero.set_curpos()
                wall_draw()
            count = 1
            # key_name=pygame.key.name()

            # elif event.key==K_s:

        elif event.type == pygame.KEYUP:
            count = 0

        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = pygame.mouse.get_pos()
            check_buttons(game, mouse_x, mouse_y)