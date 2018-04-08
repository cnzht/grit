#-*-coding:utf-8-*-
#str.py
#2018年4月8日 20:51:39
#进度条从1%-100%的程序，每隔0.1s刷新一次。
'''
import time as t
print("{0:-^30}".format("执行开始"))
for i in range (101):
    sx = i*('*')
    print("\r{:^3.0f}%[{}]".format(i,sx),end="")
    t.sleep(0.01)
'''
#完整文本进度条实例，在一行实时刷新界面，并加入了程序运行计时。
'''   
import time 
scale = 50
print("执行开始".center(scale//2,'-'))
start = time.perf_counter()
for i in  range(scale + 1):
    a = i*('>')
    b = (scale-i)*'>'
    c = (i/scale)*100
    dur = time.perf_counter()-start
    print("\r{:^3.0f}%  [{}>{}]{:.2f}s".format(c,a,b,dur),end="")
    time.sleep(0.1)
print("\n"+"执行结束".center(scale//2,'-'))
'''
#获得用户输入的一个整数N，计算N的平方值；结果采用宽度20字符方式居中输出，空余字符采用减号(-)填充。如果结果超过20个字符，则以结果宽度为准。
'''
N = int(eval(input()))
print("{:-^20}".format(N*N))
'''
#读入一个整数N，分别计算如下内容：
'''
1. N的绝对值；

2. N与10进行同符号加法、减法和乘法运算，同符号运算指使用N的绝对值与另一个数进行运算，运算结果的绝对值被赋予N相同的符号，其中，0的符号是正号。

将上述4项结果在一行输出，采用空格分隔，输出结果均为整数。

'''
'''
N = int(input())
if (N<0):
    m = -1
elif (N>0):
    m = 1
else:
    m = 1
N1 =  abs(N)
N2 = abs((abs(N)+10))*m
N3 = abs((abs(N)-10))*m
N4 = abs((abs(N)*10))*m
print("{} {} {} {}".format(N1,N2,N3,N4))
'''
#一年365天，以第1天的能力值为基数，记为1.0。
'''
当好好学习时，能力值相比前一天提高N‰；当没有学习时，能力值相比前一天下降N‰。

每天努力或放任，一年下来的能力值相差多少呢？其中，N的取值范围是0到100，N可以是小数，假设输入符合要求。

获得用户输入的N，计算每天努力和每天放任365天后的能力值及能力间比值，其中，能力值保留小数点后2位，能力间比值输出整数，输出结果间采用英文逗号分隔。

使用input()获得N。
'''
'''
N = (float(input()))/1000
nup = pow((1.0+N),365)
ndn = pow((1.0-N),365)
print("{:.2f},{:.2f},{:.0f}".format(nup,ndn,int(nup//ndn)))
'''
#读入一个整数N，N是奇数，输出由星号字符组成的等边三角形，要求：
'''
第1行1个星号，第2行3个星号，第3行5个星号，依次类推，最后一行共N的星号。
'''
'''
N = int(input())
if N%2==1:
    for i in range (N):
        Tempstr=(1+2*i)*'*'
        print(Tempstr.center(N,' '))
        if(1+2*i)==N:
            break
'''
#凯撒密码是古罗马凯撒大帝用来对军事情报进行加解密的算法，它采用了替换方法对信息中的每一个英文字符循环替换为字母表序列中该字符后面的第三个字符，即，字母表的对应关系如下：
'''
原文：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

密文：D E F G H I J K L M N O P Q R S T U V W X Y Z A B C

对于原文字符P，其密文字符C满足如下条件：C=(P+3) mod 26

上述是凯撒密码的加密方法，解密方法反之，即：P=(C-3) mod 26

假设用户可能使用的输入仅包含小写字母a~z和空格，请编写一个程序，对输入字符串进行凯撒密码加密，直接输出结果，其中空格不用进行加密处理。使用input()获得输入。
'''
'''
#自己编写的程序，有案例不通过
N = str(input())
nlen = len(N)
for i in range(nlen):
    nord = ord(N[i:i+1])
    if ord(N[i:i+1])==32:
        jmnord = nord       
    else:
        jmnord = nord +3
        if (jmnord>=120):
            jmnord-=26
    jmnchr = chr(jmnord)
    print(jmnchr,end="")
#别人编写的程序，完全通过
sr1="abcdefghijklmnopqrstuvwxyz"
sr2=sr1.upper()
sr=sr1+sr1+sr2+sr2
in_str=input("")
out_str=""
for j in in_str:
    if j==" ":
        out_str = out_str +" "
        continue
    i=sr.find(j)
    if(i>-1):
        out_str=out_str+sr[i+3]
print(out_str)
'''
    
    





