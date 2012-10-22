import sys
import os
import socket
import re
import win32clipboard as wincb
import win32con
 

#hacker.org Type Fastest Solution
wincb.OpenClipboard()
text=wincb.GetClipboardData(win32con.CF_TEXT) #get Text
wincb.CloseClipboard()
st=text.decode('utf-8') #decode
print(st)
a=st.split("FOO")
ans=""
for e in a:
    ans+=e
ans=ans.encode('GB2312') #need encode
wincb.OpenClipboard()
wincb.EmptyClipboard()
wincb.SetClipboardData(win32con.CF_TEXT,ans)
wincb.CloseClipboard()
