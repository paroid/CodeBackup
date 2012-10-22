/*
 *2009-08-13 by paroid
 * */
#include"iostream"
#include"fstream"
#include"time.h"

#define PER ((clock_t)1000)
using namespace std;

void ConBin(int d,bool *s){ //convert integer to binary bits
	int i;
	for(i=0;i<8;i++){
		s[7-i]=(bool)(d&1);
		d>>=1;
	}
}

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
class Cko{  // File Class
public:
	Cko(char *filename);
	bool FileCheck();
	void FileConvert();
	void Endecry(char *keyword,bool type=0); //  Encrypt_Decipher
	void RC4(char *key);
private:
	char name[50];  // FileName
};

Cko::Cko(char *filename){
	strcpy(name,filename);
}

bool Cko::FileCheck(){
	ifstream f;
	f.open(name,ios::binary);
	return f;
}

void Cko::FileConvert(){
	fstream in,out;
	char tem[50],ch,dam;
	int l=strlen(name),a;
	unsigned char cur;
	long int size;
	strcpy(tem,name);
	tem[l]='.',tem[l+1]='t',tem[l+2]='x',tem[l+3]='t',tem[l+4]='\0';

	in.open(name,ios::in|ios::binary);
	out.open(tem,ios::out|ios::binary);
	size=0;
	cout<<"\n----------------------"<<endl;
	cout<<"|   Please Wait...   |"<<endl;
	cout<<"----------------------"<<endl;
	double de=0;
	a=in.tellg();
	in.seekg(0,ios::end);
	size=in.tellg();
	size-=a;
	a=0;
	in.seekg(0,ios::beg);
	clock_t start,finish;
	start=clock();
	cout<<" 10 20 30 40 50 60 70 80 90 Done %"<<endl;
	while(in.get(ch)){
		cur=128;
		dam=0;
		for(int i=0;i<4;i++){
			dam<<=1;
			if(ch&cur)
				dam+=1;
			cur>>=1;
		}
		if(dam<10)
			dam+='0';
		else
			dam+='A'-10;
		out.put(dam);
		dam=0;
		for(int i=0;i<4;i++){
			dam<<=1;
			if(ch&cur)
				dam+=1;
			cur>>=1;
		}
		if(dam<10)
			dam+='0';
		else
			dam+='A'-10;
		out.put(dam);
		a++;
		out.put(' ');

		if(!(a&15))
			out.put('\n');
		else if(!(a&7)){
			out.put('-');
			out.put(' ');
		}
		double tt=(double)a/(double)size;
		if(tt-de>0.1){
			de=tt;
			cout<<">>>";
		}
	}
	cout<<">>>>>"<<endl;
	in.close();
	out.close();
	finish=clock();
	cout<<"\n----------------------"<<endl;
	cout<<"|        Success !   |"<<endl;
	cout<<"----------------------\n"<<endl;
	cout<<" Time:   "<<(finish-start)<<"  ms"<<endl;
	cout<<" FileSize: ";
	if(size<1024){
		cout<<(double)(size)<<"  B"<<endl;
		cout<<" Speed:    "<<(double)(size)/(finish-start)*PER<<"  B/s"<<endl;
	}
	else if(size<1048576){
		cout<<(double)(size*3/1024.0)<<"  KB"<<endl;
		cout<<" Speed:    "<<(double)(size/1024.0)/(finish-start)*PER<<"  KB/s"<<endl;
	}
	else{
		cout<<(double)(size/1048576.0)<<"  MB"<<endl;
		cout<<" Speed:    "<<(double)(size/1048576.0)/(finish-start)*PER<<"  MB/s"<<endl;
	}
	system("pause");
}

void Cko::Endecry(char *keyword,bool type){
	fstream in,out;
	char tem[50],ch;
	int l=strlen(name),i;
	strcpy(tem,name);
	if(tem[l-1]=='o'&&tem[l-2]=='k'&&tem[l-3]=='c'&&tem[l-4]=='.'){
		tem[l-1]='\0';
		l=l-5;
		while(tem[l--]!='.')
			tem[l+4]=tem[l+1];
		tem[l+4]='.',tem[l+3]='k',tem[l+2]='c',tem[l+1]='@';
	}
	else{
		tem[l]='.',tem[l+1]='c',tem[l+2]='k',tem[l+3]='o',tem[l+4]='\0';
	}

	in.open(name,ios::in|ios::binary);
	out.open(tem,ios::out|ios::binary);

	l=strlen(keyword);
	bool *key;
	key=new bool[l*8];
	for(i=0;i<l;i++){
		ConBin(keyword[i],&key[i*8]);
	}
	i=0;
	int buf,j,a;
	long int size=0,mark=0,remain;
	a=in.tellg();
	in.seekg(0,ios::end);
	size=in.tellg();
	size-=a;
	remain=size;
	in.seekg(0,ios::beg);
	cout<<"\n----------------------"<<endl;
	cout<<"|   Please Wait...   |"<<endl;
	cout<<"----------------------\n"<<endl;
	clock_t start, finish;
	start=clock();
	cout<<" 10 20 30 40 50 60 70 80 90 Done %"<<endl;
	double de=0;
	while (in.get(ch)) {
		buf=0;
		unsigned char po=128;
		for(j=0;j<8;j++){
			if(i>=l*8){   // Circle Queue
				key[i%(l*8)]=key[(i+1)%(l*8)]^key[(i+3)%(l*8)]; //  FeedBack
			}
			if(key[i++%(8*l)])
				buf+=po;
			po>>=1;
		}
		out.put(ch^buf);
		remain--;
		mark++;
		char buff[129];
		if(type&&mark>1024&&remain>=128){
			in.read(buff,128);
			for(int i=0;i<128;i++)
				buff[i]^=170;
			out.write(buff,128);
			remain-=128;
			mark+=128;
		}
		double tt=(double)mark/(double)size;
		if(tt-de>0.1){
			de=tt;
			cout<<">>>";
		}
	}
	cout<<">>>>>"<<endl;
	in.close();
	out.close();
	finish=clock();
	cout<<"\n----------------------"<<endl;
	cout<<"|        Success !   |"<<endl;
	cout<<"----------------------\n"<<endl;
	cout<<" Time:   "<<(finish-start)<<"  ms"<<endl;
	cout<<" FileSize: ";
	if(size<1024){
		cout<<size<<"  B"<<endl;
		cout<<" Speed:    "<<(double)(size)/(finish-start)*PER<<"  B/s"<<endl;
	}
	else if(size<1048576){
		cout<<(double)(size/1024.0)<<"  KB"<<endl;
		cout<<" Speed:    "<<(double)(size/1024.0)/(finish-start)*PER<<"  KB/s"<<endl;
	}
	else{
		cout<<(double)(size/1048576.0)<<"  MB"<<endl;
		cout<<" Speed:    "<<(double)(size/1048576.0)/(finish-start)*PER<<"  MB/s"<<endl;
	}
	system("pause");
}

void Cko::RC4(char *key){
	fstream in,out;
	char tem[50],ch;
	int l=strlen(name),i;
	strcpy(tem,name);
	if(tem[l-1]=='o'&&tem[l-2]=='k'&&tem[l-3]=='c'&&tem[l-4]=='.'){
		tem[l-1]='\0';
		l=l-5;
		while(tem[l--]!='.')
			tem[l+4]=tem[l+1];
		tem[l+4]='.',tem[l+3]='k',tem[l+2]='c',tem[l+1]='@';
	}
	else{
		tem[l]='.',tem[l+1]='c',tem[l+2]='k',tem[l+3]='o',tem[l+4]='\0';
	}

	in.open(name,ios::in|ios::binary);
	out.open(tem,ios::out|ios::binary);
	l=strlen(key);
	int j,a;
	long int size=0,mark=0;
	a=in.tellg();
	in.seekg(0,ios::end);
	size=in.tellg();
	size-=a;
	in.seekg(0,ios::beg);
	cout<<"\n----------------------"<<endl;
	cout<<"|   Please Wait...   |"<<endl;
	cout<<"----------------------\n"<<endl;
	clock_t start, finish;
	start=clock();
	cout<<" 10 20 30 40 50 60 70 80 90 Done %"<<endl;
	double de=0;
	int ss[256];
	for(i=0;i<256;i++)	// initialize S stream
		ss[i]=i;
	for(i=0;i<l;i++){	// permutation
		j=(i+ss[i]+key[i])%256;
		swap(ss[i],ss[j]);
	}
	j=0;
	i=0;
	while(in.get(ch)){
		i=(i+1)%256;
		j=(j+ss[i])%256;
		swap(ss[i],ss[j]);
		int t=(ss[i]+ss[j])%256;
		out.put(ss[t]^ch);
		mark++;
		double tt=(double)mark/(double)size;
		if(tt-de>0.1){
			de=tt;
			cout<<">>>";
		}
	}
	cout<<">>>>>"<<endl;
	in.close();
	out.close();
	finish=clock();
	cout<<"\n----------------------"<<endl;
	cout<<"|        Success !   |"<<endl;
	cout<<"----------------------\n"<<endl;
	cout<<" Time:   "<<(finish-start)<<"  ms"<<endl;
	cout<<" FileSize: ";
	if(size<1024){
		cout<<size<<"  B"<<endl;
		cout<<" Speed:    "<<(double)(size)/(finish-start)*PER<<"  B/s"<<endl;
	}
	else if(size<1048576){
		cout<<(double)(size/1024.0)<<"  KB"<<endl;
		cout<<" Speed:    "<<(double)(size/1024.0)/(finish-start)*PER<<"  KB/s"<<endl;
	}
	else{
		cout<<(double)(size/1048576.0)<<"  MB"<<endl;
		cout<<" Speed:    "<<(double)(size/1048576.0)/(finish-start)*PER<<"  MB/s"<<endl;
	}
	system("pause");
}

int Checklc(){
	fstream lcc,lk;
	int i=0;
	lcc.open("c:\\Ck_license",ios::in|ios::binary);
	if(!lcc){
		lcc.close();
		system("cls");
licen:
		cout<<"========================================"<<endl;
		cout<<"|   Please Input The License Number !  |"<<endl;
		cout<<"========================================"<<endl;
		int num,y,m,d;
		cin>>num;
		y=num/100000;
		m=(num%100000)/1000;
		d=num%1000;
		if(!(y%90)&&!(m%5)&&!(d%6)){
			lk.open("c:\\Ck_license",ios::out|ios::binary);
			lk.put(17);
			lk.close();
			return 1;
		}
		else if(!(y%90)&&!(m%4)&&!(d%26)){
			lk.open("c:\\Ck_license",ios::out|ios::binary);
			lk.put(34);
			lk.close();
			return 2;
		}
		else if(!(y%89)&&!(m%7)&&!(d%3)){
			lk.open("c:\\Ck_license",ios::out|ios::binary);
			lk.put(51);
			lk.close();
			return 3;
		}
		else{
			cout<<"========================================"<<endl;
			cout<<"|  Sorry! Your License Number Is Wrong.|"<<endl;
			cout<<"========================================"<<endl;
			if(i++<3)
				goto licen;
			else
				return 0;
		}
	}
	else{
		char ch;
		lcc.get(ch);
		if(ch==17||ch==34||ch==51){
			lcc.close();
			return ch/17;
		}
		else{
			cout<<"========================================"<<endl;
			cout<<"|  Sorry! Your License Number Is Wrong.|"<<endl;
			cout<<"========================================"<<endl;
			lcc.close();
			return 0;
		}
	}
}

bool pass(){
	fstream lc,lk,lp;
	int i=0,l;
	char key[21],ch;
	lc.open("c:\\Ck_password",ios::in|ios::binary);
	if(!lc){
cp:
		system("cls");
		cout<<"========================================"<<endl;
		cout<<"|    Input Your PassWord!  (1-20 long) |"<<endl;
		cout<<"========================================"<<endl;
		cin>>key;
		l=strlen(key);
		lk.open("c:\\Ck_password",ios::out|ios::binary);
		i=0;
		while(i<l){
			key[i]^=170;
			lk.put(key[i++]);
		}
		lk.close();
		lc.close();
		goto pw;
	}
	else{
		lc.close();
		system("cls");
		l=0;
pw:
		lp.open("c:\\Ck_password",ios::in|ios::binary);
		cout<<"========================================"<<endl;
		cout<<"|    Input Your PassWord!  (1-20 long) |"<<endl;
		cout<<"========================================"<<endl;
		cin>>key;
		i=0;
		while(lp.get(ch)){
			ch^=170;
			if(ch!=key[i++]){
				system("cls");
				cout<<"========================================"<<endl;
				cout<<"|   Wrong PassWord !   Input Again !   |"<<endl;
				cout<<"========================================"<<endl;
				if(l++<3){
					lp.close();
					goto pw;
				}
				else{
					lp.close();
					return false;
				}
			}
		}
re:
		system("cls");
		cout<<"========================================"<<endl;
		cout<<"|        Change Password ?   <y/n>     |"<<endl;
		cout<<"========================================"<<endl;
		cin>>ch;
		if(ch=='Y'||ch=='y')
			goto cp;
		else if(ch=='n'||ch=='N'){
			lp.close();
			return true;
		}
		else
			goto re;
	}
}

int main(){
	char s[21],keyword[16];
	char sw;
	int ed=Checklc();
	if(!ed||!pass())
		return 0;
	system("cls");
menu:
	cout<<"*****************************************************"<<endl;
	cout<<"|            Encryption Decryption Tool             |"<<endl;
	if(1==ed)
	cout<<"|               ChKo Ultimate Edition               |"<<endl;
	else if(2==ed)
	cout<<"|           Bread Brother Special Edition           |"<<endl;
	else
	cout<<"|              The Fuckin' Man Edition              |"<<endl;
	cout<<"|                    By - ChKo                      |"<<endl;
	cout<<"|===================================================|"<<endl;
	cout<<"|         1 > Convert File To Hex                   |"<<endl;
	cout<<"|         2 > Linear Shift Register                 |"<<endl;
	cout<<"|         3 > RC4                                   |"<<endl;
	cout<<"|         0 > Exit                                  |"<<endl;
	cout<<"|===================================================|"<<endl;
	cout<<"|   Press Key To Select ...                         |"<<endl;
	cout<<"*****************************************************"<<endl;
	cin>>sw;
	if(sw<'0'||sw>'3'){
		system("cls");
		goto menu;
	}
	cin.get();
	if('0'==sw)
		return 0;  // exit

	// Get FileName
Error:
	cout<<"Input FileName (1-40 long)"<<endl;
	cin.getline(s,50);
	if(strlen(s)>40){ // Error
		system("cls");
		cout<<"length Error !"<<endl;
		goto Error;
	}
	Cko file(s);
	if(!file.FileCheck()){
		system("cls");
		cout<<"File Desn't Exist !"<<endl;
		goto Error;
	}

	// Function 1  Convert To Binary
	if('1'==sw){
		file.FileConvert();
		system("cls");
		goto menu;
	}

	// Get The Keyword
E:
	cout<<"Input The Key (1-15 long)"<<endl;
	cin.getline(keyword,16);
	if(strlen(keyword)>15){ // Error
		system("cls");
		cout<<"length Error !"<<endl;
		goto E;
	}
	switch(sw){
		case '2':// Function 2  En_Decipher
			do{
				cout<<"Security Type ?\n 0> Security  Or  1> Efficiency \n Please Select...?"<<endl;
				cin>>sw;
			}while(sw!='0'&&sw!='1');
			if('0'==sw){
				file.Endecry(keyword,0); // Encrypt or Decipher
				system("cls");
				goto menu;
			}
			else{
				file.Endecry(keyword,1);
				system("cls");
				goto menu;
			}
			break;
		case '3':
			file.RC4(keyword);
			system("cls");
			goto menu;
			break;
	}
	return 0;
}
