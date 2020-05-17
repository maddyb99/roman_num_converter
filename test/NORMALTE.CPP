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
void convert(int);
void cover();
int mainscreen(int);
int checkvalid();
void main()
{
	int mode;
	cover();
	char ans='n';
	while(ans!='y')
       {
		if(ans==27)
		{
			clrscr();
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
				case'r':convert(0);
					break;
				case'A':
				case'a':gotoxy(10,4);
					cout<<"";
					break;
			}
			cout<<"\n\nDo you want to enter another number? ";
			ans=getch();
			switch(ans)
			{
				case'Y':
				case'y':cout<<"Yes";
					break;
				case'N':
				case'n':cout<<"No";
					break;
				case 27:cout<<"Exiting...";
					delay(500);
					break;
			}
			delay(500);
		}

       }
}
void cover()
{
	clrscr();
	int x=30,y=10;
	gotoxy(x,y);
	cout<<"From ROMAN to ARABIC!";
	delay(1000);
	while(y!=1)
	{
		clrscr();
		gotoxy(x,y);
		cout<<"From ROMAN to ARABIC!";
		y--;
		delay(70);
	}

}
int mainscreen(int type)
{
	int ret;
	if(!type)
	{
		clrscr();
		gotoxy(30,1);
		cout<<"From Roman to Arabic!";
		gotoxy(1,3);
		cout<<"Enter mode:";
		ret=getch();
		switch(ret)
		{
			case'r':
			case'R':cout<<"From Roman";
				break;
			case'a':
			case'A':cout<<"To Roman";
				break;
			case 27:cout<<"Exiting...";
				delay(1000);
				exit(0);
		}
		delay(500);
		gotoxy(30,1);
		cout<<"From ARABIC to ARABIC!";
		gotoxy(1,3);
		cout<<"Roman Numeral:";
		gotoxy(1,4);
		cout<<"Arabic Numeral:";
		return(ret);
	}
	else
	{
		clrscr();
		gotoxy(30,1);
		cout<<"From ROMAN to ARABIC!";
		gotoxy(1,3);
		cout<<"Roman Numeral:";
		gotoxy(1,4);
		cout<<"Arabic Numeral:";
	}
	return(ret);
}

void convert(int mode)
{
	int i=0,j=16;
       //	roman=new char[25];
	char ch;
	gotoxy(j,3);
	ch=getche();
	while(ch!=27)
	{
		roman[i]=ch;
		if(checkvalid())
			cout<<romanconvert();
		else
		{
			gotoxy(16,4);
			cout<<"(Error_(0x0245): Invalid Entry!)";
		}
		j++;
		gotoxy(j,3);
		ch=getche();
		i++;
	}
       //	delete roman;
}

int romanconvert()
{
	int len,i=0,number=0,j=0;
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
			if(normal[i+1]==normal[i]&&normal[i+2]<len)
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
       //	delete normal;
	gotoxy(16,4);
	return(number);
}

int checkvalid()
{
	int i=0, j;
	while(i<strlen(roman))
	{
		if(roman[i]==roman[i+1])
			if(roman[i+1]==roman[i+2])
				if(roman[i+2]==roman[i+3])
					return(0);
		switch(roman[i])
		{	case'i':break;
			case'I':break;
			case'v':
			case'V':if(roman[i+1]=='v'||roman[i+1]=='V')
					return(0);
				break;
			case'x':break;
			case'X':break;
			case'l':
			case'L':if(roman[i+1]=='l'||roman[i+1]=='L')
					return(0);
				break;
			case'C':break;
			case'c':break;
			case'd':
			case'D':if(roman[i+1]=='D'||roman[i+1]=='d')
					return(0);
				break;
			case'm':break;
			case'M':break;
			default:return(0);
		}
		i++;
	}
	return(1);
}