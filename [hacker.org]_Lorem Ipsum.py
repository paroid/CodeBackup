import sys
import os

f=open("lorem.txt")
text=f.read()
t1=text.split(",") #discard ,
s1=""
for s in t1:
    s1+=s
t2=s1.split(".")  #discard .
s2=""
for s in t2:
    s2+=s

a=set()  #set1
b=set()  #multiple elements set
ls=s2.splitlines()  #lines
for ln in ls:
    lis=ln.split(" ")
    for it in lis:		#element
        if  it in a:	#exist
            b.add(it)
        else:			#first exist
            a.add(it)

c=a.difference(b)       #the only one
for e in c:
    print(e)
