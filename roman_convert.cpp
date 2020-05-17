#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
char roman[50];
int*normal;
int romanconvert();
void cover();
void output();
int checkvalid(char*);
void main()
{
	char roman[50],ans='y';
	int gdriver = DETECT, gmode,i;
	initgraph(&gdriver, &gmode, "");

	setbkcolor(1);
	cover();
	while(ans!='n')
       {
		 clrscr();
		 cleardevice();
		 output();
		//int valid=checkvalid(roman);
		//number=romanconvert(end,roman);
		//if(checkvalid==0)
		cout<<romanconvert();
		gotoxy(47,9);
		outtextxy(0,117,"\n\nDo you want to enter another number? ");
		setfillstyle(1,2);
		fillellipse(250,463,5000,10);
		settextstyle(2,0,5);
		outtextxy(125,455,"Press 'n' or 'N' to Exit or any other letter to continue.");
		settextstyle(5,0,2);
		cin>>ans;

       }
       exit(0);
       //delay(1000);
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

void output()
{
	int poly[8];
	poly[0]=0;
	poly[1]=407;
	poly[2]=638;
	poly[3]=407;
	poly[4]=638;
	poly[5]=475;
	poly[6]=0;
	poly[7]=475;
	poly[8]=479;
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
	setfillstyle(1,2);
	setlinestyle(0,0,2);
	fillpoly(4,poly);
	settextstyle(2,0,5);
	settextstyle(2,0,5);
	outtextxy(205,415,"Press 'r' to Switch between modes");
	outtextxy(235,435,"Current mode: From Roman");
	outtextxy( 235,455,"Press 'Enter' to convert");
	settextstyle(5,0,2);
}

int romanconvert()
{
	int len,i=0,number=0,k=0;
//	int*normal;
  //	char roman[50];
	//clrscr();
	//cleardevice();
     //	settextstyle(5,0,2);
       //	outtextxy(2,51,"Roman numeral:");
//	outtextxy(2,84,"Converted Number:");
  //	setfillstyle(1,2);
    //	fillellipse(250,463,5000,10);
      //	settextstyle(2,0,5);
	//settextstyle(2,0,5);
       //	outtextxy(235,455,"Press 'Enter' to Convert");
	settextstyle(5,0,2);
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
				k=normal[i]+normal[i+1];
				if(k<normal[i+2])
					number-=k;
				else
					number+=k;
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
