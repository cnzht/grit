#-*-coding:utf-8-*-
#bodyBMI.py
#2018年4月11日 21:03:12
#打印出字符串中的某一部分
'''
import random
st = [1,1,15,1,5,8,1,5,8]
print (random.shuffle(st))
'''
'''
#利用蒙特卡洛方法计算圆周率PI
from random import random 
from time import perf_counter 
DATA = pow(1000,100)
hit = 0
start = perf_counter()
for i in range(1,DATA+1):
    x,y = random(),random()
    if pow((x**2)+(y**2),0.5)<=1:
        hit+=1
PI = 4*(hit/DATA)
print("圆周率PI={}".format(PI))
print("程序运行时间={}".format(start-perf_counter()))
'''
'''
#利用函数定义计算N的阶乘
n = 10
sr = [1,2,5,23,92,14,20,1]
def fact(m=1):
    global n
    for i in range(1,n):
        n*=i
    return n//m
print(fact())
print("最大的是:{}\n最小的是:{}".format(max(sr),min(sr)))    
'''
'''
#前期复习
sr = ['sa','ad']
print(''.join(sr))
'''
'''
#海龟进度条
import time
import turtle as t
t.setup(600,600,200,200)
t.pensize(12)
t.pencolor('red')
t.bk(100)
t.done()
'''
'''
try:
    st = str(input())
    print(st)
except:
    print("error!")
else:
    print("right")
finally:
    print("end")
'''
'''
for i in range(1,10+1):
    if i==8:
        continue
    print(i)
    print('xx')
'''
#第五周函数学习
#可变参数学习
'''
def fact(n,*b):
    s = 1
    for i in range (1,n):
        s+=i
    for iteam in b:
        s*=iteam
    return s
print (fact(10,2,3,4))
'''
'''
s = 10
def fact(n,*b):
    global s
    for i in range (1,n):
        s+=i
    for iteam in b:
        s*=iteam
    return s,b
a,b = fact(10,2,3,4) 
print (a,b)
'''
#局部变量为组合数据类型，且为创建，等同于全局变量。
'''
#eg1
ls = ['d','f']
def func(a):
    ls.append(a)
    return
func('c')
print(ls)

#eg2
ls = ['d','f']
def func(a):
    ls = [] #重新定义了ls，使它被创建成为了局部变量。
    ls.append(a)
    return
func('c')
print(ls)
'''
'''
dc =lambda a,b : a+b=1 #错误写法，不能赋值
print(dc(10,12))

dc = lambda a,b : a+b #正确方式
print(dc(10,12))
'''
'''
#无参数值的。
dc = lambda :"武汉大学" #其中不能有打印函数
print(dc())
'''




















