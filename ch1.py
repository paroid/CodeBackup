import sys
import os
import socket
import re
from ftplib import FTP


def bubbleSort(arr):
    for i in range(len(arr)-1):
        for j in range(len(arr)-1-i):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]


data=[1,5,6,8,9,4,2,3,45]
#data="asdbcxvxcfs"
bubbleSort(data)
#print(data)

def isLeap(year):
    if year&3:
        return False
    else:
        if year%100 or not year%400:
            return True
        else:
            return False

#print(isLeap(1110))

def cal(e):
    e=list(e.split(' '))
    if e[1]=='+':
        return int(e[0])+int(e[2])
    if e[1]=='-':
        return int(e[0])-int(e[2])
    if e[1]=='*':
        return int(e[0])*int(e[2])
    if e[1]=='/':
        return int(e[0])/int(e[2])

#print(cal("1 / 2"))


def gcd(a,b):
    if not b:
        return a
    return gcd(b,a%b)

#print(gcd(28,49))
a=1j
#print(a*a)
#print(3//2)
#print(0.1)


ss="hello"
#print(ss.center(12))

def pla(s):
    return s+s[-2::-1]
#print(pla("abcde"))

dat=['one','two','three','four']
def spell(s):
    for i in s:
        #sys.stdout.write(dat[int(i)-1]+" ")
        print(dat[int(i)-1]+" ",end="")

#spell("1234")

def itip(x):
    return str(x>>24)+"."+str(x>>16&0xff)+"."+str(x>>8&0xff)+"."+str(x&0xff)
def ipti(s):
    li=list(s.split('.'))
    return int(li[0])<<24|int(li[1])<<16|int(li[2])<<8|int(li[3])

#print(itip(1231234323))
#print(ipti("73.99.37.19"))
mul=lambda x,y:x*y
#print(mul(2,5))
def feb(x):
    if x==0 or x==1:
        return 1
    return feb(x-1)+feb(x-2)

ans=[0 for i in range(100)]
ans=[0]*100 #this works too
ans[0]=ans[1]=1  #initialize
def feb2(x):  #this is faster
    if ans[x]:
        return ans[x]
    ans[x]=feb2(x-1)+feb2(x-2)
    return ans[x]

for i in range(8):
    #print(feb2(i))
    pass

#for python challenge #4
#import urllib.request
#set the proxy
#pro=urllib.request.ProxyHandler({"http":'http://127.0.0.1:8087'})
#opn=urllib.request.build_opener(pro)
#urllib.request.install_opener(opn)
#tt="97224" #initial
#while(True):
#res=urllib.request.urlopen('http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing='+tt)
#dat=res.readline()
#print(dat)
#tt=dat.decode('utf8')[24:]
#print(str(tt))


#output=os.system('ipconfig')
#fp=os.popen('ipconfig')
#output=fp.read()
#files=output.split('\n')[8].split(':')
#print("IPv4："+files[1][1:])


#tcpSock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#tcpSock.bind(('127.0.0.1',1111))
#tcpSock.listen(5)
#info=tcpSock.accept()
#print(info)


#ft=FTP('202.118.24.170')
#res=ft.login('chenke','paroid$@^*&(')
#print(res)

import urllib.request
pro=urllib.request.ProxyHandler({"http":'http://127.0.0.1:8087'})
opn=urllib.request.build_opener(pro)
urllib.request.install_opener(opn)
#res=urllib.request.urlopen('http://www.amazon.cn/gp/product/B00478TO44/ref=s9_qpp_gw_p14_d18_g14_ir04?pf_rd_m=A1AJ19PSB66TGU&pf_rd_s=center-6&pf_rd_r=005WYC70NBP02ZRDKWNJ&pf_rd_t=101&pf_rd_p=58223252&pf_rd_i=899254051')
#res=urllib.request.urlopen('http://www.amazon.cn/ASICS-%E7%88%B1%E4%B8%96%E5%85%8B%E7%A7%81-GEL-DS-TRAINER-15-%E5%A5%B3%E8%BD%BB%E9%87%8F%E8%B7%91%E9%9E%8B-T064N/dp/B003YKGENK/ref=pd_rhf_gw_p_t_2')
#res=urllib.request.urlopen('http://www.amazon.cn/ASICS-%E7%88%B1%E4%B8%96%E5%85%8B%E7%A7%81-GEL-DS-TRAINER-15-%E5%A5%B3%E8%BD%BB%E9%87%8F%E8%B7%91%E9%9E%8B-T064N/dp/B003YKGENK/ref=pd_rhf_gw_p_t_2')
#html=res.read()
#tt=html.decode('utf8')

#f=open('B:/a.html','wb')
#f.write(html)

#pat=re.compile(r'<span id=\"actualPriceValue\"><b class=\"priceLarge\">.*</b></span>')
#mat=pat.search(tt)
#if mat:
#print('当前价格：'+''+mat.group()[50:57])


f=open("out","w")
#a=f.read()
#print(a)
#cnt=0
#for i in range(len(a)):
#if a[i]>='a' and a[i]<='z':
#cnt+=1

#print(cnt)
import math

a=28679718602997181072337614380936720482949
#a=17
b="532005663005364261011661054110306442515224556311"
c="204423415615455565142406225660"
d="13060142630"
def val(b):
    p=1
    res=0
    for i in range(len(b)):
        res+=int((ord(b[len(b)-1-i])-48)*p)
        p*=7
    print(res)
    return res


f="532005663005364261216414503026065341004024261231"
#val(f)
print("final: "+str(a-val(f)))
#print(a-val(b)-val(c)-val(d))


db=int(b)
dc=int(c)
dd=int(d)

def sevenAdd(a,b):
    c=0
    ans=0
    p=1
    while a>0 and b>0:
        s=a%10+b%10+c
        ans+=(s%7)*p
        c=int(s/7)
        a=int(a/10)
        b=int(b/10)
        p*=10
    print(c)
    print(a)
    print(b)
    return ans
#dc=int("532005663005364224206541330145055140213341414061")
print("ans"+str(sevenAdd(db,dc)))

def cov(a):
    cnt=0
    ans=""
    while a>0:
        t=chr(int(a%7+48))
        #print(t,end=" ")
        ans+=t
        bcp=a
        a=int(a/7)
        cnt+=1
        if a*7+ord(t)-48 != bcp:
            print("fuck!"+str(cnt))
    for i in range(len(ans)):
        print(ans[len(ans)-1-i],end="")
    print()

#cov(408504740)



