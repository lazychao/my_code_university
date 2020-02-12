from random import randint
from enum import Enum


class MAP_ENTRY_TYPE(Enum):#继承一个enum类
    MAP_EMPTY = 0,
    MAP_BLOCK = 1,
    MAP_TARGET = 2,
    MAP_BULLET = 3,
    MAP_ENEMY= 4,
    MAP_DEST=5,
    MAP_BULLET_ENEMY=6,


class WALL_DIRECTION(Enum):
    WALL_LEFT = 0,
    WALL_UP = 1,
    WALL_RIGHT = 2,
    WALL_DOWN = 3,


map_entry_types = {0: MAP_ENTRY_TYPE.MAP_EMPTY, 1: MAP_ENTRY_TYPE.MAP_BLOCK, 2: MAP_ENTRY_TYPE.MAP_TARGET,
                   3: MAP_ENTRY_TYPE.MAP_BULLET,4: MAP_ENTRY_TYPE.MAP_ENEMY,
                   5: MAP_ENTRY_TYPE.MAP_DEST,6:MAP_ENTRY_TYPE.MAP_BULLET_ENEMY}


class Map():
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.map = [[0 for x in range(self.width)] for y in range(self.height)]#产生一个二维数组

    def generatePos(self, rangeX, rangeY):  #传入一个矩形范围  随机生成其中一个位置
        x, y = (randint(rangeX[0], rangeX[1]), randint(rangeY[0], rangeY[1]))
        while self.map[y][x] == 1:
            x, y = (randint(rangeX[0], rangeX[1]), randint(rangeY[0], rangeY[1]))
        return (x, y)

    def resetMap(self, value):
        for y in range(self.height):
            for x in range(self.width):
                self.setMap(x, y, value)

    def setMap(self, x, y, value):#设置一个位置的类型
        if value == MAP_ENTRY_TYPE.MAP_EMPTY:
            self.map[y][x] = 0
        elif value == MAP_ENTRY_TYPE.MAP_BLOCK:
            self.map[y][x] = 1
        elif value == MAP_ENTRY_TYPE.MAP_TARGET:
            self.map[y][x] = 2
        elif value == MAP_ENTRY_TYPE.MAP_ENEMY:
            self.map[y][x] = 4
        elif value == MAP_ENTRY_TYPE.MAP_DEST:
            self.map[y][x] = 5
        else:
            self.map[y][x] = 3
    def iseaten(self,x,y):
        return self.map[y][x] ==4
    def isbullet_enemy(self,x,y):
        return self.map[y][x]==6
    def isend(self,x,y):
        return self.map[y][x] ==5
    def ishero(self,x,y):
        return self.map[y][x] == 2
    def isenemy(self,x,y):
        return self.map[y][x] ==4
    def isVisited(self, x, y):
        return self.map[y][x] != 1
    def isempty(self, x, y):
        return self.map[y][x] ==0
    def isMovable(self, x, y):
        return self.map[y][x] != 1

    def isValid(self, x, y):
        if x < 0 or x >= self.width or y < 0 or y >= self.height:
            return False
        return True

    def getType(self, x, y):
        return map_entry_types[self.map[y][x]]

    def showMap(self):
        for row in self.map:
            s = ''
            for entry in row:
                if entry == 0:
                    s += ' 0'
                elif entry == 1:
                    s += ' #'
                else:
                    s += ' X'
            print(s)