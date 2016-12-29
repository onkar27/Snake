#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<time.h>
#define X 116
#define Y 28
using namespace std;
void gotoxy(short x, short y){
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);}
class cord
{
	public:
	int x,y;
	cord(int a=0,int b=0):x(a),y(b){}
	~cord(){}
	int operator ==(cord t){return (x==t.x?(y==t.y?1:0):0);}
};
vector <cord> a;
int check(int x1,int y1){
	int i=0;
	cord tmp(x1,y1);
	for(i=0;i<a.size();i++)
	{
		if(tmp==a[i])break;
	}
	return i!=a.size();
}
int check()
{
	int i;
	for(i=2;i<a.size();i++)
	{
		if(a[0]==a[i])break;
	}
	return i!=a.size();
}
int main()
{
	int i,j,k,level,err=0,m=90,n=12,score=0;
	cord t;
    cout<<"Controls : Arrow keys \tPRESS ANY KEY \n";getch();
	do{cout<<"Enter your Level : ";
	cin>>level;}while(level>10||level<0);
	cout<<"PRESS ANY KEY \n";getch();system("cls");
	gotoxy(m,n);printf("%c",'O');
	for(i=0;i<5;i++)
	{
		t=cord(10,10+i);
		a.push_back(t);
	}
	if(check())err++;
	char c=72,p=75;cord t1,t2;
	while(1)
	{
		if(kbhit())
		{
			p=c;c=getch();
			if(p==75&c==77||p==77&&c==75)c=p;
			else if(p==72&&c==80||p==80&&c==72)c=p;
			if(c!=72&&c!=75&&c!=80&&c!=77)c=p;
		}
		if(c=='e')break;
		t1=a[0];
		gotoxy(a[0].x,a[0].y);
		printf("%c",'O');
		switch(c)
		{
		case 72:(a[0].y==0?err++:0);a[0].y--;break;
		case 77:(a[0].x==X?err++:0);a[0].x++;break;
		case 75:(a[0].x==0?err++:0);a[0].x--;break;
		case 80:(a[0].y==Y?err++:0);a[0].y++;break;
		}
		if(check(m,n))
		{
			t=cord(m,n);score++;
			a.push_back(t);
			m=rand()%X;n=rand()%Y;
			gotoxy(m,n);printf("%c",'O');
		}
		gotoxy(a[0].x,a[0].y);
		printf("%c",'O');
		for(i=1;i<a.size();i++)
		{
			gotoxy(a[i].x,a[i].y);
			cout<<" ";
			((i%2==1)?(t2=a[i],a[i]=t1):(t1=a[i],a[i]=t2));
			gotoxy(a[i].x,a[i].y);
			cout<<"*";
		}
		if(check())err++;
		if(err)break;
		for( j=0;j<1000;j++)
		for( k=0;k<level*500;k++)rand();
		gotoxy(X-15,Y+1);
		cout<<"YOUR SCORE IS : "<<score;}
		if(err){getch();system("cls");gotoxy(X/2-10,Y/2);cout<<"GAME OVER\n\n\n\n\t\t\tBY : Onkar J. Sathe";getch();cout<<"\n\t\t\t\t\t\t\tYOUR SCORE IS : "<<score;getch();}
}
