import png
#hacker.org challenge <Lotsa Dots>
#funny  :)
pic=png.Reader(filename='C:/Users/Chen/Desktop/stars.php') #the png file
f=open('D:/res.txt','w')
dat=pic.asRGB() #decode the file
li,y=list(dat[2]),dat[1]
y=y>>4
for i in range(y):
	ans=0
	for j in range(8):
		ans=(ans<<1)+int(li[(i<<4)+8][((j<<4)+8)*3]==230) #decode the bit
	f.write(chr(ans)) #store in file for fast copy


