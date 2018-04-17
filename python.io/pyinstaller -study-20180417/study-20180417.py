#-*-coding:utf-8-*-
'''
import turtle as tt
def koch(size,n):
    if n==0:
        tt.fd(size)
    else:
        
        for angle in [0,60,-120,60]:
            tt.left(angle)
            koch(size/3,n-1)
def main():
    tt.setup(1200,800,100,50)
    tt.penup()
    tt.goto(-300,100)
    tt.speed(10)
    tt.pensize(2)
    tt.color('red')
    tt.pendown()
    koch(450,3)
    tt.right(120)
    koch(450,3)
    tt.right(120)
    koch(450,3)
    tt.hideturtle()
    tt.done()
main()
'''
#KochDrawV2.py
import turtle
def koch(size, n):
    if n == 0:
        turtle.fd(size)
    else:
        for angle in [0, 60, -120, 60]:
           turtle.left(angle)
           koch(size/3, n-1)
def main():
    turtle.setup(600,600)
    turtle.penup()
    turtle.goto(-200, 100)
    turtle.speed(10)
    turtle.color("blue")
    turtle.pendown()
    turtle.hideturtle()
    turtle.pensize(2)
    level = 3      # 3阶科赫雪花，阶数
    for i in range(9):
        koch(150,level)     
        turtle.right(40)
    turtle.hideturtle()
    turtle.done()
main()
