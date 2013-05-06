#include "LMSMenu.h"
#include <iostream>
#include <windows.h>
#include<conio.h>

#include <fstream>


using namespace std;


LMSMenu::LMSMenu(void)
{
}


void LMSMenu:: border()
{
	Date display;
	display.getsystemdate();
	box(1,1,70,46,(char)205,(char)186);
	//box(3,3,67,43,'-','|');
	gotoxy(2,2);
	display.showdate();
	gotoxy(50,2);
	cout<<(char)174<<"---LMS---"<<(char)175;
}

void LMSMenu:: mainmenu()
{
	char a='\0';
	int x=9,y=9;
	int sel=1;
	bool exit=true;
	do{
		//clrscr();
		do{
			//system("cls");
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>21)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			if(y==17)
				sel=3;
			if(y==21)
				sel=4;	
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,7);
			std::cout<<"MAIN MENU";
			box(10,10,18,2,'-','|');//search
			gotoxy(10,11);
			std::cout<<"Search Menu";
			box(10,14,18,2,'-','|');//login
			gotoxy(10,15);
			std::cout<<"Add Menu";
			box(10,18,18,2,'-','|');//issue/return
			gotoxy(10,19);
			std::cout<<"Issue/Return Menu";
			box(10,22,18,2,'-','|');//exit
			gotoxy(10,23);
			std::cout<<"Exit";
			a=getkey();
		}while(a!=13);
		switch(sel)
		{
			case 1:
				searchmenu();
				break;
			case 2:
				addmenu();
				break;
			case 3:
				irmenu();
				break;
			case 4:
				exit =false;
				break;
		}
		//if(y==17)
			//	y=17;
		
	}while(exit);
}
void LMSMenu:: addmenu()
{
	char a='\0';
	int x=9,y=9;
    int	sel=0;
	do{
		do{
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>13)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,7);
			std::cout<<"ADD MENU";
			box(10,10,18,2,'-','|');//add book
			gotoxy(10,11);
			std::cout<<"Add Book";
			box(10,14,18,2,'-','|');//add member
			gotoxy(10,15);
			std::cout<<"Add Member";
			a=getkey();
			if(a==27)
				sel=0;
		}while(a!=13 && a!=27);
		switch(sel)
		{
			case 1:
				RegBook::addBook();
				break;
			case 2:
				Reader::addReader();
				break;
		}
	}while(a!=27);

}
void LMSMenu:: irmenu()
{
	char a='\0';
	int x=9,y=9;
    int	sel=0;
	do{
		do{
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>13)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,7);
			std::cout<<"ISSUE AND RETURN MENU";
			box(10,10,18,2,'-','|');
			gotoxy(10,11);
			std::cout<<"Issue Book";
			box(10,14,18,2,'-','|');
			gotoxy(10,15);
			std::cout<<"Return Book";
			a=getkey();
			if(a==27)
				sel=0;
			if(a==12)
			{
				clrscr();
				IR_handler:: displayall();
				getch();
			}
		}while(a!=13 && a!=27);
		switch(sel)
		{
			case 1:
				IR_handler::Issue();
				break;
			case 2:
				IR_handler::Return();
				break;
		}
	}while(a!=27);

}

bool LMSMenu::  isfile_book(){
	bool is;
	fstream file;
	file.open("total.txt",ios::in);
	if (!file)
		is=false;
	else
		is=true;
	return is;
}

bool LMSMenu::  isfile_reader(){
	bool is;
	fstream file;
	file.open("user.txt",ios::in);
	if (!file)
		is=false;
	else
		is=true;
	return is;
}

void LMSMenu:: install()
{
	bool isB,isR;
	isB=isfile_book();
	isR=isfile_reader();
	if(isB==false)
	{
		Classification::createfile_book();
	}
	if(isR==false)
	{
		Classification::createfile_user();
	}
}

void LMSMenu:: searchmenu()
{
	char a='\0';
	int x=9,y=9;
    int	sel=0;
	do{
		do{
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>13)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,7);
			std::cout<<"SEARCH MENU";
			box(10,10,18,2,'-','|');
			gotoxy(10,11);
			std::cout<<"Search for Book";
			box(10,14,18,2,'-','|');
			gotoxy(10,15);
			std::cout<<"Search for Member";
			a=getkey();
			if(a==27)
				sel=0;
		}while(a!=13 && a!=27);
		switch(sel)
		{
			case 1:
				searchbook();
				break;
			case 2:
				searchmember();
				break;
		}
	}while(a!=27);

}
void LMSMenu:: searchbook()
{
	char a='\0';
	int x=9,y=9;
	int sel=1;
	do{
		do{
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>21)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			if(y==17)
				sel=3;
			if(y==21)
				sel=4;	
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,5);
			std::cout<<"SEARCH BOOK MENU";
			gotoxy(40,6);
			std::cout<<"Total Books ::"<<RegBook::totalBook();
			box(10,10,18,2,'-','|');//search
			gotoxy(10,11);
			std::cout<<"Search by ID";
			box(10,14,18,2,'-','|');//login
			gotoxy(10,15);
			std::cout<<"Search by Title";
			box(10,18,18,2,'-','|');//issue/return
			gotoxy(10,19);
			std::cout<<"Search by Author";
			box(10,22,18,2,'-','|');//exit
			gotoxy(10,23);
			std::cout<<"See all Books";
			a=getkey();
			if(a==27)
				sel=0;
		}while(a!=13 && a!=27);
		switch(sel)
		{
			case 1:
				clrscr();
				helper_searchbookID();
				break;
			case 2:
				clrscr();
				helper_searchbookTITLE();
				break;
			case 3:
				clrscr();
				helper_searchbookAUTHOR();
				break;
			case 4:
				clrscr();
				RegBook::displayallBooks();
				break;
		}
	}while(a!=27);
}

void LMSMenu:: helper_searchbookID()
{
	int test_a,test_id;
	int x=11,y=11;
	border();
	gotoxy(x,y);
	cout<<"Enter id to search for ::";
	box(x+29,y-1,6,2,'-','|');
	numberinput(test_id,x+30,y);
	//cin>>test_id;
	test_a=RegBook::findBookby_ID(test_id);
	gotoxy(x,y+5);
	cout<<"Searching.....";
	Sleep(1000);
	if(test_a>-1)
	{
			RegBook::displayBook(test_a);
			getch();
	}
	else
	{
		gotoxy(x,y+9);
		cout<<"Book not Found!"<<endl;
		getch();
	}
}

void LMSMenu:: helper_searchbookTITLE()
{
	int i=0,total=0;
	int x=11,y=11;
	char fndinput[50];
	char in;
	border();
	box(x+29,y-1,12,2,'-','|');
	gotoxy(x,y);
	std::cout<<"Enter Title of the Book ::";
	stringinput(fndinput,50,x+29,y,12);
		int * get =RegBook::findBookby_Title(fndinput);
	
	if(get!=NULL){
		total=helper_noofresults(get);
		do{
			RegBook::displayBook(get[i]);
			gotoxy(50,6);
			std::cout<<"found "<<1+i<<" of "<<total;
			gotoxy(25,44);
			std::cout<<"Use Arrow keys to move forword and backwards";
			gotoxy(25,45);
			std::cout<<"Use Escape key to stop";	
			in=getkey();
			if(in==77)//right
				i++;
			if(in==75)//left
				i--;
			if(in==27)
				break;
			if(i<0)
				i=0;
			if(i>=total)
				i=total;
			//i++;
			//getch();
			//Reader::displayReader(get[1]);
		}while(in!=27);
	}
	else
	{
		gotoxy(30,28);
		std::cout<<"No Book of Title "<<fndinput<<" found";
		getch();
	}
		delete [] get;
}
void LMSMenu:: helper_searchbookAUTHOR()
{
	int i=0,total=0;
	int x=11,y=11;
	char fndinput[50];
	char in;
	border();
	box(x+29,y-1,12,2,'-','|');
	gotoxy(x,y);
	std::cout<<"Enter Author of the Book ::";
	stringinput(fndinput,50,x+29,y,12);
		int * get =RegBook::findBookby_Author(fndinput);
	
	if(get!=NULL){
		total=helper_noofresults(get);
		do{
			RegBook::displayBook(get[i]);
			gotoxy(50,6);
			std::cout<<"found "<<1+i<<" of "<<total;
			gotoxy(25,45);
			std::cout<<"Use Arrow keys to move forword and backwards";
			gotoxy(25,46);
			std::cout<<"Use Escape key to stop";	
			in=getkey();
			if(in==77)//right
				i++;
			if(in==75)//left
				i--;
			if(in==27)
				break;
			if(i<0)
				i=0;
			if(i>=total)
				i=total;
			//i++;
			//getch();
			//Reader::displayReader(get[1]);
		}while(in!=27);
	}
	else
	{
		gotoxy(30,28);
		std::cout<<"No Book of Author "<<fndinput<<" found";
		getch();
	}
		delete [] get;
}

void LMSMenu::searchmember()
{
	char a='\0';
	int x=9,y=9;
    int	sel=0;
	do{
		do{
			clrscr();
			if(a==80)
			{
				x=9;
				y +=4;
			}

			if(a==72)
			{
				x=9;
				y -=4;
			}
			if(y<9 || y>17)
					y=9;
			if(y==9)
				sel=1;
			if(y==13)
				sel=2;
			if(y==17)
				sel=3;
			box(x,y,21,4,'-','|');
			border();
			gotoxy(24,5);
			std::cout<<"SEARCH MEMBER MENU";
			gotoxy(40,6);
			std::cout<<"Total Members ::"<<Reader::totalReader();
			box(10,10,18,2,'-','|');
			gotoxy(10,11);
			std::cout<<"Search by ID";
			box(10,14,18,2,'-','|');
			gotoxy(10,15);
			std::cout<<"Search by Name";
			box(10,18,18,2,'-','|');
			gotoxy(10,19);
			std::cout<<"Show all Members";
			a=getkey();
			if(a==27)
				sel=0;
		}while(a!=13 && a!=27);
		switch(sel)
		{
			case 1:
				clrscr();
				helper_searchmemberID();
				break;
			case 2:
				clrscr();
				helper_searchmemberNAME();
				break;
			case 3:
				clrscr();
				Reader::displayallReader();
				break;
		}
	}while(a!=27);

}
void LMSMenu::helper_searchmemberID()
{
	int test_a,test_id;
	int x=11,y=11;
	border();
	gotoxy(x,y);
	cout<<"Enter id to search for ::";
	box(x+29,y-1,6,2,'-','|');
	numberinput(test_id,x+30,y);
	//cin>>test_id;
	test_a=Reader::findReaderby_ID(test_id);
	gotoxy(x,y+5);
	cout<<"Searching.....";
	Sleep(1000);
	if(test_a>-1)
	{
			Reader::displayReader(test_a);
			getch();
	}
	else
	{
		gotoxy(x,y+9);
		cout<<"User not Found"<<endl;
		getch();
	}
}

void LMSMenu::helper_searchmemberNAME()
{
	int i=0,total=0;
	int x=11,y=11;
	char fndinput[50];
	char in;
	border();
	box(x+29,y-1,12,2,'-','|');
	gotoxy(x,y);
	std::cout<<"Enter Name of the Member ::";
	stringinput(fndinput,50,x+29,y,12);
		int * get =Reader::findReaderby_name(fndinput);
	
	if(get!=NULL){
		total=helper_noofresults(get);
		do{
			Reader::displayReader(get[i]);
			gotoxy(50,6);
			std::cout<<"found "<<1+i<<" of "<<total;
			gotoxy(25,32);
			std::cout<<"Use Arrow keys to move forword and backwards";
			gotoxy(25,33);
			std::cout<<"Use Escape key to stop";	
			in=getkey();
			if(in==77)//right
				i++;
			if(in==75)//left
				i--;
			if(in==27)
				break;
			if(i<0)
				i=0;
			if(i>=total)
				i=total;
			//i++;
			//getch();
			//Reader::displayReader(get[1]);
		}while(in!=27);
	}
	else
	{
		gotoxy(30,28);
		std::cout<<"No Member of name "<<fndinput<<" found";
		getch();
	}
		delete [] get;
}

int LMSMenu:: helper_noofresults(int * find)
{
	int i;
	for(i=0;find[i]!=-1;i++);
	return i;
}

void LMSMenu:: numberinput(int& temp,short x,short y)
{
	gotoxy(x,y);
	while(true) // cycle until input OK
	{
		//cout << "\nEnter an integer: ";
		std::cin.unsetf(std::ios::skipws);
		std::cin >> temp;
		if( std::cin.good() ) // if no errors
		{
			std::cin.ignore(10, '\n'); // remove newline
			break; // exit loop
		}
		std::cin.clear(); // clear the error bits
		//cout << "Incorrect input";
		gotoxy(x,y);
		std::cout<<"           ";// bad hard code!!!!
		gotoxy(x,y);
		//
		std::cin.ignore(10, '\n'); // remove newline
	}
}



LMSMenu::~LMSMenu(void)
{
}
//=====================================================================================
//----------------------------FRIEND FUNCTIONS-----------------------------------------
//=====================================================================================
inline void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;// class of win NT 
	COORD Cursor_an_Pos = { x,y}; // struct of point
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);//gets current state 
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos); // sets to new position

}

char getkey()
{
	char ch1,ch2;
	ch1=getch();
	if(ch1 == 0)
	{
		ch2=getch();
		return ch2;

	}
	return ch1;
}

inline void clrscr()
{
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// class of winNT
  COORD coord = {0, 0};// COORD is a struct of int x,y
  DWORD count;// unsigned long
  CONSOLE_SCREEN_BUFFER_INFO csbi;//saves the demensions of screen
  GetConsoleScreenBufferInfo(hStdOut, &csbi);// tells the current demensions

  FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
  //set the console to blank; 
  SetConsoleCursorPosition(hStdOut, coord);// sets the cursor position
}

inline void box(int x, int y, int l, int w, char c,char lo)
{

	int i=0;
	int xq,yq;
	xq=x;
	yq=y;
	gotoxy(x,y);
	while(i<l)
	{
		cout<<c;
		i++;
	}
	i=1;
	while(i<w)
	{
		gotoxy(xq-1,yq+i);	
		cout<<lo;
		gotoxy(xq+l,yq+i);
		cout<<lo;
		i++;
	}
	yq=yq+i;;
	gotoxy(x,yq);
	i=0;
	while(i<l)
	{
		cout<<c;
		i++;
	}
}

void stringinput(char *str,int t,int x,int y,int l)
{
	// t = lenght of str
	// l= max no of charter displayed 
	// keep l according to the lenght of the box!! 
	int x1=x;
	int i=0,j=1,a=1,b;
	//box(x,y-1,l,2,'-','|');
	gotoxy(x,y);
	while(i<t)
	{
		gotoxy(x1,y);
		str[i]=getch();
		
		if(str[i]==13 || str[i]==9 )
		{
			break;
		}
		else if(str[i]!=8)
		{
			if(i>=l-1)
			{
				j=i-l;
				gotoxy(x,y);
				j=i-l+2;
				while(j<=i)
				{
					cout<<str[j];
					j++;
				}
			}
			else
			{
				gotoxy(x1,y);
				cout<<str[i];
				x1++;
			}
			i++;
		}
		else if(str[i]==8)
		{	
			if(i>l-1)
			{ 
				b=i-l;
				gotoxy(x,y);
				while(b<i-1)
				{		
					cout<<str[b];
					b=b+1;
				
				}
				i--;
			}	
			else if(i>0)
			{
				x1--;
				cout<<str[i];
				str[i-1]=' ';
				cout<<str[i-1];
				cout<<str[i];
				i--;
			}
		}
	}
	str[i]='\0';

}