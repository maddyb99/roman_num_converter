#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>

int romanconvert();
int cover();
int checkvalid(char*);
void main()
{
	char roman[50],ans='y';
	int gdriver = DETECT, gmode,i;
	initgraph(&gdriver, &gmode, "");
	settextstyle(4,0,7);
	setbkcolor(1);
	cover();
	while(ans=='y')
       {

		//int valid=checkvalid(roman);
		//number=romanconvert(end,roman);
		//if(checkvalid==0)
		cout<<romanconvert();
		cout<<"\n\nDo you want to enter another number? ";
		cin>>ans;

       }
       //delay(1000);
}
int romanconvert()
{
	int len,i=0,number=0,j=0;
	int*normal;
	char roman[50];
	//clrscr();
	cleardevice();
	cout<<"Enter roman numeral:";
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
			if(normal[i+1]==normal[i])
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
int cover()
{
	outtextxy(125,100,"From ROMAN");
	outtextxy(300,200,"to");
	outtextxy(175,300,"ARABIC!");
	getch();
}