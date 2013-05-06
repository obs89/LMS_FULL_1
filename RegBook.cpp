#include "RegBook.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include<conio.h>
#include <Windows.h>
#include "LMSMenu.h"


RegBook::RegBook(void):copies(0),ID(0),issued_copies(0)
{
}

void RegBook:: setcopies(int in)
{
	if(in<=50)// i have no idea why have i limit it to 50 :D
		copies=in;
	setissue_state();//
}
void RegBook:: setID(int in)
{
	ID=in;
}
int RegBook:: getcopies()const
{
	return copies;
}
int RegBook:: getID()const
{
	return ID;
}

void RegBook:: setissue_state()// true if book can be issued
{
	if((copies-issued_copies)<=1)
		issue_state=false;
	else
		issue_state=true;

}
bool RegBook::getissue_state()const
{
	return issue_state;
}

int RegBook::getissued_copies()const
{
	return issued_copies;
}
void RegBook::addissued_copies()
{
	issued_copies += 1;
	setissue_state();
}
void RegBook:: subissued_copies()
{
	issued_copies -= 1;
	setissue_state();
}

void RegBook::showhelper()
{
	short x=10,y=8;
	LMSMenu::border();
	//box(1,0,52,40,'-','|');
	gotoxy(20,4);
	std::cout<<"Add Book Menu";

	box(x+27,y-1,20,2,'-','|');
	gotoxy(x,y);
	std::cout<<"Enter Title :";
	box(x+27,y+2,20,2,'-','|');
	gotoxy(x,y+3);
	std::cout<<"Enter name of the author:";
	box(x+27,y+5,20,2,'-','|');
	gotoxy(x,y+6);
	std::cout<<"Enter year of publication:";
	box(x+27,y+8,20,2,'-','|');
	gotoxy(x,y+9);
	std::cout<<"Enter ISBN number:";
	box(x+27,y+11,20,2,'-','|');
	gotoxy(x,y+12);
	std::cout<<"Enter name of Publisher:";
	box(x+27,y+14,20,2,'-','|');
	gotoxy(x,y+15);
	std::cout<<"Enter DDC number:";
	box(x+27,y+17,20,2,'-','|');
	gotoxy(x,y+18);
	std::cout<<"Enter no of copies:";
	gotoxy(x,y+21);
	std::cout<<"Select the classification of the Book(1-7)";//c,s,a,h,t,l,r :";
	box(x+3,y+22,12,2,'-','|');
	gotoxy(x+3,y+23);
	std::cout<<"Computer(1)";
	box(x+17,y+22,12,2,'-','|');
	gotoxy(x+17,y+23);
	std::cout<<"Science(2)";
	box(x+31,y+22,12,2,'-','|');
	gotoxy(x+31,y+23);
	std::cout<<"Arts(3)";
	box(x+3,y+25,12,2,'-','|');
	gotoxy(x+3,y+26);
	std::cout<<"History(4)";
	box(x+17,y+25,12,2,'-','|');
	gotoxy(x+17,y+26);
	std::cout<<"Technology(5)";
	box(x+31,y+25,12,2,'-','|');
	gotoxy(x+31,y+26);
	std::cout<<"Language(6)";
	box(x+17,y+28,12,2,'-','|');
	gotoxy(x+17,y+29);
	std::cout<<"Religion(7)";
	box(x,y+32,2,2,'-','|');
}

void RegBook:: input()
{
	int temp_copies;
	char a;
	do{
		clrscr();
		showhelper();
		Publication::input();
		Book::input();
	
	//std::cout<<"Enter no of copies :";
	//std::cin>>temp_copies;
		numberinput(temp_copies,37,26);
		setcopies(temp_copies);
		inputcatagory();
		ID=type.IDgen();
	//std::cin.clear();
		gotoxy(10,43);
		std::cout<<"Press Enter to save....";
		a=getkey();
	}while(a!=13);
}
void RegBook:: inputcatagory()
{
	char select;//c,s,a,h,t,l,r
	//std::cout<<"Select the classification c,s,a,h,t,l,r :";
	gotoxy(10,41);
	while(1){
		select=getche();
		if (select=='1' ||select=='2' ||select=='3' || select=='4' || select=='5' || select=='6' || select=='7' )
		{
			getch();
			break;
		}
		else
		{
			gotoxy(10,41);
			//std::cout<<' ';
		}
	}
	//std::cin>>select;
	switch(select)
	{
		case '1':
			type.setdomain(computer);
			break;
		case '2':
			type.setdomain(science);
			break;
		case '3':
			type.setdomain(arts);
			break;
		case '4':
			type.setdomain(history);
			break;
		case '5':
			type.setdomain(technology);
			break;
		case '6':
			type.setdomain(language);
			break;
		case '7':
			type.setdomain(religion);
			break;
	}
}
void RegBook:: showhelper_out()
{
	int x=5,y=8;

	box(x+10,y-1,50,2,'-','|');
	gotoxy(x,y);
	std::cout<<"Title : ";	
	gotoxy(x+10,y);
	std::cout<<gettitle();
	box(x+31,y+5,30,2,'-','|');
	gotoxy(x,y+6);
	std::cout<<"Author : ";	
	gotoxy(x+31,y+6);
	std::cout<<getauthor();
	box(x+31,y+8,30,2,'-','|');
	gotoxy(x,y+9);
	std::cout<<"Year of publication :";		
	gotoxy(x+31,y+9);
	std::cout<<getpubYear();
	box(x+31,y+11,30,2,'-','|');
	gotoxy(x,y+12);
	std::cout<<"ISBN Number :";
	gotoxy(x+31,y+12);
	std::cout<<getISBN();
	box(x+31,y+14,30,2,'-','|');
	gotoxy(x,y+15);
	std::cout<<"Publisher :";
	gotoxy(x+31,y+15);
	std::cout<<getpublisher();
	box(x+31,y+17,30,2,'-','|');
	gotoxy(x,y+18);
	std::cout<<"DDC Number :";	
	gotoxy(x+31,y+18);
	std::cout<<getDDC();
	box(x+31,y+20,30,2,'-','|');
	gotoxy(x,y+21);
	std::cout<<"Number of copy(s) of the book ";  
	gotoxy(x+31,y+21);
	std::cout<<copies;
	box(x+31,y+23,30,2,'-','|');
	gotoxy(x,y+24);
	std::cout<<"book ID :";
	gotoxy(x+31,y+24);
	std::cout<<ID;
	box(x+31,y+26,30,2,'-','|');
	gotoxy(x,y+27);
	std::cout<<"classification of the book ";
	//class show
	gotoxy(x+31,y+27);
	int get=type.getdomain();
	switch(get)
	{
	case 0:
		std::cout<<"Computer";
		break;
	case 1:
		std::cout<<"Science";
		break;
	case 2:
		std::cout<<"Arts";
		break;
	case 3:
		std::cout<<"History";
		break;
	case 4:
		std::cout<<"Technology";
		break;
	case 5:
		std::cout<<"Language";
		break;
	case 6:
		std::cout<<"Religion";
		break;
	}
	box(x+31,y+29,30,2,'-','|');
	gotoxy(x,y+30);
	std::cout<<"Book Issue Status ";
	gotoxy(x+31,y+30);
	(issue_state)?std::cout<<"Issuable": std::cout<<"Not Issuable";
	box(x+31,y+32,30,2,'-','|');
	gotoxy(x,y+33);
	std::cout<<"Current No of Copy(s) Library ";
	gotoxy(x+31,y+33);
	std::cout<<copies-issued_copies;
}
void RegBook:: show()
{
	clrscr();
	LMSMenu::border();
	//Publication::show();
	showhelper_out();
	//Book::show();
	//std::cout<<"Number of copies of the book :"<<copies<<std::endl;
	//std::cout<<"book ID :"<<ID<<std::endl;
	//std::cout<<"classification of the book :";
	
	//(issue_state)?std::cout<<"This Book can be Issued "<<std::endl : std::cout<<"This Book can not be Issued"<<std::endl;
//	std::cout<<"Library have "<<copies-issued_copies<<" of this book"<<std::endl;
}
//======================================================================================
//----------------START OF STATIC FTNS-------------------------------------------------- 
void RegBook:: addBook()
{
	using namespace std;
	RegBook indata;
	indata.input();
	fstream file;
	file.open("RegBooks.txt",ios::binary |ios::out|ios::app);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"bad file!"<<std::endl;
		getch();
	}
	else
		file.write(reinterpret_cast<char*>(&indata),sizeof(RegBook));
	file.close();
	gotoxy(10,44);
	cout<<"New Book is Added.....";
	Sleep(2000);
}
void RegBook::displayallBooks()
{
	using namespace std;
	RegBook outdata;
	int a=0,keep=0;
	char q;
	std::fstream file;
	file.open("RegBooks.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"bad file or no Record!"<<std::endl;
		getch();
	}
	else
	{
		file.seekg(0,ios::end);
		keep=static_cast<int>(file.tellg());// by placing auto warninng was gone Alas!:(
		file.seekg(0);
		do
		{
			cout<<endl<<endl;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(RegBook));
				outdata.show();
			gotoxy(10,43);
			cout<<"Press any key to continue or esape to exit";
			q=getkey();
			a=static_cast<int>(file.tellg());
			if(q==27)
				break;
		}while(!file.eof() && a!=keep);
	}
		file.close();

}

int RegBook::findBookby_ID(int find)
{
	using namespace std;
	RegBook outdata;
	int a=0,re=-1,keep=0;// may need long
	fstream file;
	bool is=false;
	file.open("RegBooks.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"bad file!"<<std::endl;
	}
	else
	{
		file.seekg(0,ios::end);
		keep=static_cast<int>(file.tellg());
		file.seekg(0);
		while(!file.eof() && a!=keep)
		{
			re++;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(RegBook));
			if (outdata.ID==find)
			{
				is=true;
				break;
			}
			//re=static_cast<int>(file.tellg());
			a=static_cast<int>(file.tellg());
		}
	}
	file.close();
	if(is==false)
		re=-1;
	return re;//-sizeof(RegBook);
}

int* RegBook:: findBookby_Title(char* chkname)
{
	using namespace std;
	//toupper(chkname);
	int * place= new int[20];
	for(int m=0;m<20;m++)
	{
		place[m]=-1;
	}
	int i=0;
	RegBook outdata;
	bool is=false;
	int a=0,re=-1;// may need long
	fstream file;
	file.open("RegBooks.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"file does not exist!"<<std::endl;
	}
	else
	{
		file.seekg(0,ios::end);
		int keep=static_cast<int>(file.tellg());
		file.seekg(0);
		while(!file.eof() && a!=keep)
		{
			re++;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(RegBook));
			if (strcmpi(outdata.gettitle(),chkname)==0)
			{
				is=true;
				place[i]=re;
				i++;
				//break;
			}  
			//re=static_cast<int>(file.tellg());
			a=static_cast<int>(file.tellg());
		}
	}
		file.close();
	if(is==false)
	{
		place=NULL;
		re=-1;
	}
	return place;//-sizeof(Reader);
}

int* RegBook:: findBookby_Author(char *chkauthor)
{
	using namespace std;
	//toupper(chkname);
	int * place= new int[20];
	for(int m=0;m<20;m++)
	{
		place[m]=-1;
	}
	int i=0;
	RegBook outdata;
	bool is=false;
	int a=0,re=-1;// may need long
	fstream file;
	file.open("RegBooks.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"file does not exist!"<<std::endl;
	}
	else
	{
		file.seekg(0,ios::end);
		int keep=static_cast<int>(file.tellg());
		file.seekg(0);
		while(!file.eof() && a!=keep)
		{
			re++;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(RegBook));
			/*
				strstr ftn is far better the strcmpi.......
			*/

			if (strcmpi(outdata.getauthor(),chkauthor)==0)
			{
				is=true;
				place[i]=re;
				i++;
				//break;
			}  
			//re=static_cast<int>(file.tellg());
			a=static_cast<int>(file.tellg());
		}
	}
		file.close();
	if(is==false)
	{
		place=NULL;
		re=-1;
	}
	return place;//-sizeof(Reader);
}

 int RegBook:: totalBook()
 {
	using namespace std;
	int keep;
	int res=0;
	fstream file;
	file.open("RegBooks.txt",ios::binary |ios::in);
	if(!file)
	{
		//empty
	}
	else{
		file.seekg(0,ios::end);
		keep=static_cast<int>(file.tellg());
		res=keep/sizeof(RegBook);
	}
	file.close();
	
	return res;
 }
void RegBook:: displayBook(int on)
{
	using namespace std;
	if(on>-1)
	{
		RegBook outdata;
		fstream file;
		file.open("RegBooks.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"bad file!"<<std::endl;
		}
		else
		{
			file.seekg(on*sizeof(RegBook),ios::beg);
			file.read(reinterpret_cast<char *>(&outdata),sizeof(RegBook));
				outdata.show();
		}
		file.close();
	}
}

bool RegBook::setissue(int set_id)
{
	using namespace std;
	int place=0;
	bool status;
	//place=findBookby_ID(set_id);
	place=set_id;
	if(place>-1)
	{
		status=true;
		fstream file;
		RegBook update;
		file.open("RegBooks.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"bad file!"<<std::endl;
		}
		else
		{
			file.seekg(sizeof(RegBook)*place,ios::beg);
			file.read(reinterpret_cast<char *>(&update),sizeof(RegBook));
		}
			file.close();

		if(update.getissue_state()==true)
		{
			update.addissued_copies();
			file.open("RegBooks.txt",ios::binary |ios::out|ios::in);
			if(!file)
			{
				gotoxy(10,45);
				cout<<"Bad file"<<endl;
			}
			else
			{
				file.seekp(sizeof(RegBook)*place,ios::beg);
				file.write(reinterpret_cast<char *>(&update),sizeof(RegBook));
			}
			file.close();
			status=true;
		}
		else
			status=false;
	}
	else
		status=false;
	return status;
}

bool RegBook:: unsetissue(int set_id)
{
	using namespace std;
	int place=0;
	bool status;
	place=findBookby_ID(set_id);
	if(place>-1)
	{
		status=true;
		fstream file;
		RegBook update;
		file.open("RegBooks.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"bad file!"<<std::endl;
		}
		else
		{
			file.seekg(sizeof(RegBook)*place,ios::beg);
			file.read(reinterpret_cast<char *>(&update),sizeof(RegBook));
		}
		file.close();
		update.subissued_copies();
		file.open("RegBooks.txt",ios::binary |ios::out|ios::in);
		if(!file)
		{
			gotoxy(10,45);
			cout<<"Bad file"<<endl;
		}
		else
		{
			file.seekp(sizeof(RegBook)*place,ios::beg);
			file.write(reinterpret_cast<char *>(&update),sizeof(RegBook));
		}
		file.close();
	}
	else
		status=false;
	return status;
}

RegBook::~RegBook(void)
{
}
