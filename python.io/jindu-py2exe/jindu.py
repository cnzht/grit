#-*-coding:utf-8-*-
#str.py
#进度条从1%-100%的程序，每隔0.1s刷新一次。
import time as t
jishu = 100
print("{0:-^30}".format("执行开始"))
for i in range (jishu+1):
    a = ">"*i
    b = "*"*(jishu-i)
    c = (i/jishu)*100
    ti = t.ctime() 
    print("\r{:^3.0f}%  {}[{:<}>{:>}]".format(c,ti,a,b),end=' ')
    t.sleep(0.1)
print("\n{0:-^30}".format("执行结束"))
