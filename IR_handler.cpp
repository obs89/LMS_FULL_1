#include "IR_handler.h"
#include <iostream>
#include <fstream>
#include "LMSMenu.h"
#include <conio.h>

int IR_handler::keepperday_T=30;
int IR_handler:: keepperday_S=15;
int IR_handler:: keepperday_O=7;

IR_handler::IR_handler(void):del_flag(true)
{
}
void IR_handler::input()
{
	//int x,y;
	
	box(30,10,5,2,'-','|');
	gotoxy(10,11);
	std::cout<<"Enter Book ID ";
	box(30,14,5,2,'-','|');
	gotoxy(10,15);
	std::cout<<"Enter Reader ID ";
	numberinput(book_id,30,11);
	//std::cin>>book_id;
	
	numberinput(reader_id,30,15);
	//std::cin>>reader_id;
}
void IR_handler:: numberinput(int& temp,short x,short y)
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
		std::cout<<"    ";
		gotoxy(x,y);
		//
		std::cin.ignore(10, '\n'); // remove newline
	}
}

void IR_handler::show()
{
	std::cout<<"book is "<<book_id<<std::endl;
	std::cout<<"user is "<<reader_id<<std::endl;
	issue_date.showdate();
	if(del_flag)
		std::cout<<"book is returned del it "<<std::endl;
	else
		std::cout<<"book is not yet returned "<<std::endl;
	std::cout<<std::endl;
}

int IR_handler:: fine(int hadbook){

	using namespace std;
	int fined=0;
	int pos=Reader::findReaderby_ID(reader_id);
	if(pos>-1)
	{
		Reader outdata;
		fstream file;
		file.open("Regusers.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"bad file!"<<std::endl;
			getch();
		}
		else
		{
			file.seekg(pos*sizeof(Reader),ios::beg);
			file.read(reinterpret_cast<char *>(&outdata),sizeof(Reader));
			file.close();
			if(outdata.getuser_type()==student)
			{
				if (hadbook>keepperday_S)
				{
					int temp;
					temp=hadbook-keepperday_S;
					fined=temp*10;
				}
			}
			if(outdata.getuser_type()==teacher)
			{
				if (hadbook>keepperday_T)
				{
					int temp;
					temp=hadbook-keepperday_T;
					fined=temp*5;
				}
			}
			if(outdata.getuser_type()==other)
			{
				if (hadbook>keepperday_O)
				{
					int temp;
					temp=hadbook-keepperday_O;
					fined=temp*10;
				}
			}
		}
	}

	return fined;
}
//--------------------------------------------------------------------------
void IR_handler::Issue()
{
	using namespace std;
	bool reader_side;
	bool Book_side;
	IR_handler handle;
	handle.issue_date.getsystemdate();
	clrscr();
	LMSMenu::border();
	gotoxy(15,5);
	std::cout<<"Issue Book Menu";
	handle.input();
	//find book if no book break
	//then pass id to issue
	int pofB=RegBook::findBookby_ID(handle.book_id);
	int pofR=Reader::findReaderby_ID(handle.reader_id);
	if (pofB>-1)
	{
		if(pofR>-1)
		{
			Book_side = RegBook::setissue(pofB);
			if(Book_side==false)
			{
				gotoxy(25,30);
				std::cout<<"Sorry! This book can't be issued right now!"<<std::endl;
				getch();
			}
			else
			{
				reader_side = Reader::setissue(pofR,handle.book_id);
				if(reader_side==false)
				{
					gotoxy(30,31);
					std::cout<<"Members book issue limit excceded "<<std::endl;
					getch();

				}
			}
			if (reader_side==true && Book_side==true)
			{
				handle.del_flag=false;
				fstream file;
				file.open("IRrecord.txt",ios::binary| ios::out|ios::app);
				if(!file)
				{
					gotoxy(10,45);
					std::cout<<"bad file!"<<std::endl;
					getch();
				}
				else
					file.write(reinterpret_cast<char *>(&handle),sizeof(IR_handler));
				gotoxy(30,25);
				cout<<"Book has been Issued";
				gotoxy(30,26);
				cout<<"Press any to continue";
				getch();
			}
		}
		else
		{
			gotoxy(30,31);
			cout<<"Member not found!";
			getch();
		}
	}
	else
	{
		gotoxy(30,30);
		cout<<"Book not found!";
		getch();
	}
	//else
		//no
}

void IR_handler:: Return()
{
	using namespace std;
	Date current;
	current.getsystemdate();
	bool r,b;
	IR_handler retiver;
	clrscr();
	LMSMenu::border();
	gotoxy(15,5);
	std::cout<<"Return System"<<std::endl;
	retiver.input();
	//retiver.issue_date.getsystemdate();
	int pos=IR_handler::findrecord(retiver);// if no record no book/reader or not issued
	if (pos>-1)
	{
		fstream file;
		IR_handler infile;
		file.open("IRrecord.txt",ios::binary |ios::in);
		if(!file)
		{
			gotoxy(10,45);
			std::cout<<"bad file!"<<std::endl;
			getch();
		}
		else
		{
			file.seekg(pos*sizeof(IR_handler),ios::beg);
			file.read(reinterpret_cast<char *>(&infile),sizeof(IR_handler));
			file.close();
			int haddays,is_fine;
			haddays=current.diffindays(infile.issue_date);
			is_fine=infile.fine(haddays);
			if(is_fine>0)
			{
				gotoxy(30,31);
				cout<<"Please pay "<<is_fine<<"  fine"<<endl;
				getch();
				//cout<<"Enter amount of fine u are paying ::";
				//cin>>is_fine;
			}
			r=Reader:: unsetissue(infile.reader_id,infile.book_id);
			b=RegBook:: unsetissue(infile.book_id);
			if(r==true && b==true )
			{
				infile.del_flag=true;
				file.open("IRrecord.txt",ios::binary |ios::out|ios::in);
				if(!file)
				{
					gotoxy(10,45);
					cout<<"Bad file"<<endl;
					getch();
				}
				file.seekp(sizeof(IR_handler)*pos,ios::beg);
				file.write(reinterpret_cast<char *>(&infile),sizeof(IR_handler));
				file.close();
				gotoxy(30,25);
				cout<<"Book has been Returned";
				gotoxy(30,26);
				cout<<"Press any to continue";
				getch();
			}
		}
	}
	else
	{
		gotoxy(30,30);
		std::cout<<"Issue record not found!";
		getch();
	}
	//else no record found!
}

int IR_handler:: findrecord(IR_handler obj)
{
	using namespace std;
	bool is=false;
	IR_handler infile;
	fstream file;
	file.open("IRrecord.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"bad file!"<<std::endl;
		getch();
	}
	file.seekg(0,ios::end);
	int keep=static_cast<int>(file.tellg());
	int a=0,re=-1;// may need long
	file.seekg(0);
	while(!file.eof() && a!=keep)
	{
		re++;
		file.read(reinterpret_cast<char *>(&infile),sizeof(IR_handler));
		if (infile.del_flag==false)
		{
			if(infile.reader_id==obj.reader_id && infile.book_id==obj.book_id)
			{
				is=true;
				break;

			}
		}  
		a=static_cast<int>(file.tellg());
	}
	file.close();
	if(is==false)
		re=-1;
	return re;
}

void IR_handler:: displayall()
{
	using namespace std;
	IR_handler outdata;
	fstream file;
	file.open("IRrecord.txt",ios::binary |ios::in);
	if(!file)
	{
		gotoxy(10,45);
		std::cout<<"bad file!"<<std::endl;
		getch();
	}
	int a;
	file.seekg(0,ios::end);
	int keep=static_cast<int>(file.tellg());// by placing auto warninng was gone Alas!:(
	file.seekg(0);
	do
	{
		cout<<endl<<endl;
		file.read(reinterpret_cast<char *>(&outdata),sizeof(IR_handler));
			outdata.show();
		a=static_cast<int>(file.tellg());
	}while(!file.eof() && a!=keep);
	file.close();

}

IR_handler::~IR_handler(void)
{
}
