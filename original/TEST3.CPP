#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
int*normal;
char roman[25];
int romanconvert();
void normalconvert();
void cover();
int mainscreen(int);
int checkvalid(char*);
void main()
{
	char ans='n';
	int mode,gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "");
	setbkcolor(4);
	cover();
	while(ans!='y')
       {
		if(ans==27)
		{
			cleardevice();
			closegraph();
			exit(0);
		}
		mode=mainscreen(0);
		ans='y';
		while(ans=='y')
		{
			mainscreen(1);
			switch(mode)
			{
				case'R':
				case'r':cout<<romanconvert();
					break;
				case'N':
				case'n':gotoxy(10,4);
					cout<<"";
					break;
			}
			gotoxy(47,9);
			outtextxy(0,117,"Do you want to enter another number?");
			ans=getch();
			settextstyle(2,0,6);
			switch(ans)
			{
				case'Y':
				case'y':outtextxy(370,125,"Yes");
					break;
				case'N':
				case'n':outtextxy(370,125,"No");
					break;
				case 27:outtextxy(370,125,"Exiting...");
					delay(500);
					break;
			}
			delay(500);
		}

       }
       closegraph();
}
void cover()
{
	int x1=125,y1=101,x2=300,y2=199,x3=175,y3=298,i=0,size=7;
	settextstyle(4,0,7);
	outtextxy(x1,y1,"From ROMAN");
	outtextxy(x2,y2,"to");
	outtextxy(x3,y3,"ARABIC!");
	delay(1000);
	while(i<15)
	{
		cleardevice();
				if(i==14)
		{	outtextxy(x1+2,y1,"From ROMAN");
			outtextxy(x2+1,y2-1,"to");
			outtextxy(x3+2,y3-1,"ARABIC!");
			cout<<size;
		}
		else
		{	outtextxy(x1,y1,"From ROMAN");
			outtextxy(x2,y2,"to");
			outtextxy(x3,y3,"ARABIC!");
		}
		x1+=2;
		if(i%2)
			x2+=3;
		x3+=12;
		y1-=7;
		y2-=14;
		y3-=21;
		i++;
		if(i%3==0)
		{
			size--;
			settextstyle(4,0,size);
		}
		//delay(1);
		//cout<<x2<<y2;
	}
	setlinestyle(1,0,2);
	line(150,30,455,30);
	line(150,32,455,32);

}
int mainscreen(int type)
{
	int ret,poly[8];
	if(!type)
	{
		clrscr();
		cleardevice();
		settextstyle(4,0,3);
		outtextxy(163,3,"From ROMAN to ARABIC!");
	       //	outtextxy(321,3,"to");
	     //	outtextxy(343,3,"ARABIC!");
		setlinestyle(1,0,2);
		line(160,30,465,30);
		line(160,32,465,32);
		poly[0]=0;
		poly[1]=410;
		poly[2]=639;
		poly[3]=410;
		poly[4]=639;
		poly[5]=475;
		poly[6]=0;
		poly[7]=475;
		poly[8]=479;
		settextstyle(2,0,6);
		setfillstyle(1,12);
		setlinestyle(0,0,2);
		fillpoly(4,poly);
		outtextxy(180,415,"Press 'r' to convert from Roman and");
		outtextxy(205,435,"Press 'n' to convert to Roman.");
		outtextxy(255,455,"Press 'Esc' to Exit");
		outtextxy(2,51,"Enter mode:");
		ret=getch();
		settextstyle(2,0,5);
		switch(ret)
		{
			case'r':
			case'R':outtextxy(107,55,"From Roman");
				break;
			case'n':
			case'N':outtextxy(107,55,"To Roman");
				break;
			case 27:outtextxy(107,55,"Exiting...");
				delay(1000);
				closegraph();
				exit(0);
		}
		delay(500);
		settextstyle(4,0,3);
		outtextxy(153,3,"From ROMAN");
		outtextxy(321,3,"to");
		outtextxy(343,3,"ARABIC!");
		setlinestyle(1,0,2);
		line(150,30,455,30);
		line(150,32,455,32);
		settextstyle(5,0,2);
		outtextxy(2,51,"Roman numeral:");
		outtextxy(2,84,"Converted Number:");
		return(ret);
	}
	else
	{
		clrscr();
		cleardevice();
		settextstyle(4,0,3);
		outtextxy(153,3,"From ROMAN");
		outtextxy(321,3,"to");
		outtextxy(343,3,"ARABIC!");
		setlinestyle(1,0,2);
		line(150,30,455,30);
		line(150,32,455,32);
		settextstyle(5,0,2);
		outtextxy(2,51,"Roman numeral:");
		outtextxy(2,84,"Converted Number:");
	}
}

int romanconvert()
{
	int len,i=0,number=0,j=0;
	gotoxy(20,5);
	gets(roman);
	len=strlen(roman);
	normal=new int[len];
	for(i=0;i<len;i++)
	{
		switch(roman[i])
		{	case'i':
			case'I':normal[i]=1;
				break;
			case'v':
			case'V':normal[i]=5;
				break;
			case'x':
			case'X':normal[i]=10;
				break;
			case'l':
			case'L':normal[i]=50;
				break;
			case'C':
			case'c':normal[i]=100;
				break;
			case'd':
			case'D':normal[i]=500;
				break;
			case'm':
			case'M':normal[i]=1000;
				break;
		}
	}
	i=0;
	while(i+1<len)
	{
		if(normal[i+1]<=normal[i])
		{
			if(normal[i+1]==normal[i]&&i+2<len)
			{
				j=normal[i]*2;
				if(j<normal[i+2])
					number-=j;
				else
					number+=j;
				i++;
			}
			else
				number+=normal[i];
		}
		else
		{
			number-=normal[i];
		}
		i++;

	}
	number+=normal[i];
	gotoxy(22,7);
	return(number);
}

int checkvalid(char*rome)
{	int i=0,flag=0;
	char temp;
	while(i<=strlen(rome))
	{     if(flag>=2)
		{
			i+=strlen(rome);
			return(1);
		}
	}
	return(0);
}