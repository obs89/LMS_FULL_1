#include "Reader.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <Windows.h>
#include "LMSMenu.h"

Reader::Reader(void)// seting havebooks to 0 is needed 4 smooth working of sethavebook()
{
	for(int i=0;i<3;i++){
		haveBook[i]=0;
	}
}
void Reader:: setuser_type(type set)
{
	if(set==student || set==teacher || set==other)
	{
		user_type.setdomain(set);
		setuser_id();
	}
}
void Reader::setuser_id()
{
	user_id=user_type.IDgen();
}
int Reader:: getuser_type()const
{
	return user_type.getdomain();
}
int Reader:: getuser_id()const
{
	return user_id;
}
bool Reader:: sethaveBook(int have)// returns true if book issue is seccuessful
{
	bool status=false;
	for(int i=0;i<3;i++)
	{
		if(haveBook[i]==0)
		{
			haveBook[i]=have;
			status=true;
			break;
		}
	}
	return status;
}

bool Reader:: unsethaveBook(int unset)
{
	bool status=false;
	for(int i=0;i<3;i++)
	{
		if(haveBook[i]==unset)
		{
			haveBook[i]=0;
			status=true;
			break;
		}
	}
	return status;
}
void Reader::showhelper()
{
	short x=10,y=13;
	//clrscr();
	//-----------------------
	//box(1,1,40,20,'-','|');
	gotoxy(10,5);
	std::cout<<"Register User Menu";
	gotoxy(10,10);
	std::cout<<"Enter name :";
	box(23,9,15,2,'-','|');
	//-----------------------
	gotoxy(x,y);
	std::cout<<"Select user Type from below ";
	box(x+13,y+1,12,2,'-','|');
	gotoxy(x+13,y+2);
	std::cout<<"Teacher(1)";
	box(x+13,y+5,12,2,'-','|');
	gotoxy(x+13,y+6);
	std::cout<<"Student(2)";
	box(x+13,y+9,12,2,'-','|');
	gotoxy(x+13,y+10);
	std::cout<<"Other(3)";
	box(10,25,2,2,'-','|');
	
	
}

void Reader:: input()
{
	char select,a;
	//77 r 75 l
	do{
		clrscr();
		LMSMenu::border();
		showhelper();
		Person::input();
		gotoxy(10,26);
		while(1){
			select=getche();
			if (select=='1' ||select=='2' ||select=='3' )
			{
				getch();
				break;
			}
			else
			{
				gotoxy(10,26);
			//std::cout<<' ';
			}
		}

	//std::cout<<" person 't',stuent 's',other 'o':";
		switch(select)
		{
		case '1':
			setuser_type(teacher);
			break;
		case '2':
			setuser_type(student);
			break;
		case '3':
			setuser_type(other);
			break;
		}
		gotoxy(10,33);
		std::cout<<"Press Enter to save....";
		a=getkey();
	}while(a!=13);
}
void Reader:: show()
{
	clrscr();
	//const int slide_to_x=7;
	LMSMenu::border();
	gotoxy(10,4);
	std::cout<<"Member Infomation";
	short x=10,y=10;
	//box(1,1,45,20,'-','|');

	gotoxy(x,y);
	std::cout<<"Name::";
	box(x+24,y-1,27,2,'-','|');
	gotoxy(x+24,y);
	Person::show();


	gotoxy(x,y+3);
	std::cout<<"User ID::";
	box(x+24,y+2,27,2,'-','|');
	gotoxy(x+24,y+3);
	std::cout<<user_id;


	gotoxy(x,y+6);
	std::cout<<"user type::";
	switch(getuser_type())
	{
	case student:
			box(x+24,y+5,27,2,'-','|');
			gotoxy(x+24,y+6);
			std::cout<<"Student";
			break;
	case teacher:
			box(x+24,y+5,27,2,'-','|');
			gotoxy(x+24,y+6);
			std::cout<<"Teacher";
			break;
	case other:
			box(x+24,y+5,27,2,'-','|');
			gotoxy(x+24,y+6);
			std::cout<<"Other";
			break;
	}
	gotoxy(x,y+9);
	std::cout<<"Have Book(s)::";
	box(x+24,y+8,27,2,'-','|');//
	gotoxy(x+24,y+9);
	showhaveBook();
	gotoxy(x+24,y+11);
}
int* Reader::gethaveBook()const
{
	return (int *)haveBook;
}

void Reader::showhaveBook()
{
	for(int i=0;i<3 /*&& haveBook[i]!=0*/;i++)
	{
		if(haveBook[i]!=0)
			std::cout<<haveBook[i]<<" ";
	}
}
/*
void Reader::appReader()
{
	show();
	std::cout<<std::endl;
	input();

}*/

//--------------------------------------------------------------------------------------
// Start of static functions
void Reader:: addReader()
{
	using namespace std;
	Reader indata;
	indata.input();
	fstream file;
	file.open("Regusers.txt",ios::binary |ios::out|ios::app);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"File does not exist or created!"<<std::endl;
		getch();
	}
	else
		file.write(reinterpret_cast<char*>(&indata),sizeof(Reader));
	file.close();
	gotoxy(10,37);
	cout<<"New Member is Added.....";
	Sleep(2000);
}

void Reader::displayallReader()//
{
	using namespace std;
	Reader outdata;
	int a=0;
	int size=sizeof(Reader);
	char move;
	fstream file;
	file.open("Regusers.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"file does not exist!"<<std::endl;
		getch();
	}
	else
	{
		file.seekg(0,ios::end);
		int keep=static_cast<int>(file.tellg());// by placing auto warninng was gone Alas!:(
		file.seekg(0);
		do
		{
		//cout<<endl<<endl;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(Reader));
				outdata.show();
			file.seekg(-size ,ios::cur);
			//msg
			gotoxy(20,30);
			cout<<"Use Left and Right arrow keys to move";
			move=getkey();
			if(move==77)
				file.seekg(size,ios::cur);
			if(move==75)
				file.seekg(-size,ios::cur);
			if(a==-1)
				break;
			a=static_cast<int>(file.tellg());
		}while(!file.eof() && a!=keep);
	}
	file.close();

}
void Reader::displayReader(int on)
{
	using namespace std;
	if(on>-1)
	{
		Reader outdata;
		fstream file;
		file.open("Regusers.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"file does not exist!!"<<std::endl;
			getch();
		}
		else
		{
			file.seekg(on*sizeof(Reader),ios::beg);
			file.read(reinterpret_cast<char *>(&outdata),sizeof(Reader));
				outdata.show();
		}
		file.close();
	}
}

int Reader::findReaderby_ID(int find)
{
	using namespace std;
	Reader outdata;
	bool is=false;
	int a=0,re=-1;// may need long
	fstream file;
	file.open("Regusers.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"file does not exist!"<<std::endl;
		getch();
	}
	else
	{
		file.seekg(0,ios::end);
		int keep=static_cast<int>(file.tellg());
		file.seekg(0);
		while(!file.eof() && a!=keep)
		{
			re++;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(Reader));
			if (outdata.user_id==find)
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
	return re;//-sizeof(Reader);
}


int* Reader:: findReaderby_name(char* chkname)
{
	using namespace std;
	//toupper(chkname);
	int * place= new int[20];
	for(int m=0;m<20;m++)
	{
		place[m]=-1;
	}
	int i=0;
	Reader outdata;
	bool is=false;
	int a=0,re=-1;// may need long
	fstream file;
	file.open("Regusers.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"file does not exist!"<<std::endl;
		getch();
	}
	else
	{
		file.seekg(0,ios::end);
		int keep=static_cast<int>(file.tellg());
		file.seekg(0);
		while(!file.eof() && a!=keep)
		{
			re++;
			file.read(reinterpret_cast<char *>(&outdata),sizeof(Reader));
			if (strcmpi(outdata.getname(),chkname)==0)
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
int Reader:: totalReader()
{
	using namespace std;
	int keep;
	int res=0;
	fstream file;
	file.open("Regusers.txt",ios::binary |ios::in);
	if(!file)
	{
		//empty
	}
	else{
		file.seekg(0,ios::end);
		keep=static_cast<int>(file.tellg());
		res=keep/sizeof(Reader);
	}
	file.close();
	
	return res;
}
/*
void Reader::updateReader(int ofid)// still false
{
	using namespace std;
	int place=findReaderby_ID(ofid);
	if(place>-1)
	{
		fstream file;
		Reader update;
		file.open("Regusers.txt",ios::binary |ios::in);
		if(!file)
			std::cout<<"bad file!"<<std::endl;
		file.seekg(sizeof(Reader)*place,ios::beg);
		file.read(reinterpret_cast<char *>(&update),sizeof(Reader));
		file.close();

		update.appReader();//

		file.open("Regusers.txt",ios::binary |ios::out|ios::app);
		file.seekp(place,ios::beg);
		file.write(reinterpret_cast<char *>(&update),sizeof(Reader));
		file.close();

	}
}
*/
bool Reader:: setissue(int R_find,int to_book)//clear!
{
	using namespace std;
	int place=0;
	bool status;
	//place=findReaderby_ID(R_find);
	place=R_find;
	if(place>-1)
	{
		status=true;
		fstream file;
		Reader update;
		file.open("Regusers.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"file does not exist!"<<std::endl;
			getch();
		}
		else
		{
			file.seekg(sizeof(Reader)*place,ios::beg);
			file.read(reinterpret_cast<char *>(&update),sizeof(Reader));
		}
		file.close();

		status=update.sethaveBook(to_book);
		if(status==true)
		{
			file.open("Regusers.txt",ios::binary |ios::out|ios::in);
			if(!file)
			{
				gotoxy(10,45);
				std::cout<<"file does not exist!";
				getch();
			}
			else
			{
				file.seekp(sizeof(Reader)*place,ios::beg);
				file.write(reinterpret_cast<char *>(&update),sizeof(Reader));
			}
			file.close();
		}


	}
	else
	{
		status=false;
	}
	return status;
}

bool Reader:: unsetissue(int R_find,int to_book)
{
	using namespace std;
	int place=0;
	bool status;
	place=findReaderby_ID(R_find);
	if(place>-1)
	{
		status=true;
		fstream file;
		Reader update;
		file.open("Regusers.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"file does not exist!"<<std::endl;
			getch();
		}
		else
		{
			file.seekg(sizeof(Reader)*place,ios::beg);
			file.read(reinterpret_cast<char *>(&update),sizeof(Reader));
		}
		file.close();

		status=update.unsethaveBook(to_book);
		if(status)
		{
			file.open("Regusers.txt",ios::binary |ios::out|ios::in);
			if(!file)
			{
				gotoxy(10,45);
				std::cout<<"file does not exist!";
				getch();
			}
			else
			{
				file.seekp(sizeof(Reader)*place,ios::beg);
				file.write(reinterpret_cast<char *>(&update),sizeof(Reader));
			}
			file.close();
		}


	}
	else
	{
		status=false;
	}
	return status;
}

Reader::~Reader(void)
{
}
