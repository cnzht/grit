#-*-coding:utf-8-*-
#2018年4月13日 14:07:21
#学习关于七段数码管程序的设计
#1、先设计运行可以显示位的七段数码管
'''
import turtle
import time
def Drawgap():
    turtle.penup()
    turtle.fd(7)
def Drawline(draw):
    Drawgap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(30)
    Drawgap()
    turtle.right(90)
def Drawseven(DATA):
    turtle.color("blue")
    Drawline(True) if DATA in[2,3,4,5,6,8,9] else Drawline(False)#第1条线
    Drawline(True) if DATA in[0,1,3,4,5,6,7,8,9] else Drawline(False)#第2条线  
    Drawline(True) if DATA in[0,2,3,5,6,8,9] else Drawline(False)#第3条线  
    Drawline(True) if DATA in[0,2,6,8] else Drawline(False)#第4条线
    turtle.left(90)
    Drawline(True) if DATA in[0,4,5,6,8,9] else Drawline(False)#第5条线
    Drawline(True) if DATA in[0,2,3,5,6,7,8,9] else Drawline(False)#第6条线
    Drawline(True) if DATA in[0,1,2,3,4,7,8,9] else Drawline(False)#第7条线
    turtle.right(180)
    turtle.penup()
    turtle.fd(20)
def Drawymd(ti):
    for i in ti:
        if i == '-':
            turtle.color("red")
            turtle.write('年', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        elif i == '=':
            turtle.color("red")
            turtle.write('月', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        elif i == '+':
            turtle.color("red")
            turtle.write('日', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        elif i == '*':
            turtle.color("red")
            turtle.write('时', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        elif i == '~':
            turtle.color("red")
            turtle.write('分', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        elif i == '@':
            turtle.color("red")
            turtle.write('秒', font=('Arial', 18, 'normal'))
            turtle.fd(30)
        else:
            Drawseven(eval(i))
def main():
    turtle.setup(1300,250,100,100)
    turtle.pensize(10)
    turtle.penup()
    turtle.bk(600)
    turtle.pendown()
    turtle.speed(10)
    ti = time.strftime("%Y-%m=%d+%I*%M~%S@",time.gmtime())
    Drawymd(ti)
    turtle.hideturtle() 
    turtle.done()
main()
'''

#方案二直接采用turtle.wirte方式绘制。
'''
import部分
'''
from time import sleep
import turtle
import time
'''
函数部分
'''
def Drawhms(digit):
    turtle.color('blue')
    sr = str(digit)
    turtle.write(sr[0], font=('Arial', 30, 'normal'))
    turtle.penup()
    turtle.fd(20)
    turtle.pendown()
def Drawzuozhe():
    zz = '作者：周某人 2018年4月13日'
    bb = '版本：V-0.1'
    turtle.color('green')
    turtle.penup()
    turtle.right(90)
    turtle.fd(50)
    turtle.right(90)
    turtle.fd(470)
    turtle.pendown()
    turtle.write(zz, font=('楷体', 30, 'normal'))
    turtle.left(180)
    turtle.penup()
    turtle.right(90)
    turtle.fd(50)
    turtle.right(90)
    turtle.pendown()
    turtle.write(bb, font=('楷体', 30, 'normal'))
    turtle.penup()
def Drawymd(ti):
    for i in ti:
        if i == '-':
            turtle.color("red")
            turtle.write('年', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        elif i == '=':
            turtle.color("red")
            turtle.write('月', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        elif i == '+':
            turtle.color("red")
            turtle.write('日', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        elif i == '*':
            turtle.color("red")
            turtle.write('时', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        elif i == '~':
            turtle.color("red")
            turtle.write('分', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        elif i == '@':
            turtle.color("red")
            turtle.write('秒', font=('楷体', 18, 'normal'))
            turtle.penup()
            turtle.fd(30)
            turtle.pendown()
        else:
            Drawhms(eval(i))
def circle():
    turtle.pensize(2)
    turtle.penup()
    turtle.bk(200)
    turtle.pendown()
    turtle.fd(180)
    turtle.circle(20,180)
    turtle.fd(180)
    turtle.circle(20,180)
    turtle.penup()
    turtle.bk(20)
    turtle.left(90)
    turtle.fd(20)
    turtle.right(90)
    turtle.fd(19)
    turtle.pendown()
def jindu():
    turtle.pensize(36)
    turtle.pencolor('red')
    turtle.fd(2)
def wirte(i):
    turtle.color('green')
    t = str(i)
    turtle.write(t[0:3], font=('楷体', 14, 'normal'))
def tip():
    turtle.reset()
    turtle.penup()
    turtle.bk(200)
    turtle.pendown()
    turtle.write('程序载入成功！',font=('楷体',24,'normal'))
    turtle.hideturtle()
    sleep(2)
    turtle.penup()
    turtle.reset()
def main():
    turtle.setup(600,350,400,400)
    turtle.hideturtle()
    turtle.speed(10)
    circle()
    for i in range(1,92):
        jindu()
        wirte(round((i/90)*100,1))
        sleep(0.01)
    tip()
    turtle.pensize(10)
    turtle.penup()
    turtle.bk(230)
    turtle.pendown()
    ti = time.strftime("%Y-%m=%d+%I*%M~%S@",time.gmtime())
    Drawymd(ti)
    Drawzuozhe()
    turtle.hideturtle() 
    turtle.done()
'''
主函数部分
'''
main()




















