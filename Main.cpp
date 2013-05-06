#include<iostream>
//#include"RegBook.h"
#include"Reader.h"
#include "IR_handler.h"
#include <windows.h>
#include<conio.h>
//#include <fstream>
#include"LMSMenu.h"
using namespace std;

//void gotoxy(short,short);

int main ()
{
	//system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	LMSMenu a;
	a.install();
	a.mainmenu();
	return 0;
}


	//a.border();/*
	//bool a=isfile_book();
	//bool b=isfile_reader();
	//int handle=0,test_a=0,test_id=0;
	/*cout<<"Use with caution"<<endl;
	cout<<"IF u want to reset ftns that genrate id's press 1 :: ";
	cin>>handle;
	if (handle==1)
		//	Classification::createfile();
	clrscr();
	do{
		clrscr();
		cout<<"Press 1 to add new Reader ";
		cout<<"\n Press 2 to add new Book ";
		cout<<"\nPress 3 to see all current user ";
		cout<<"\n press 4 to see all books in the Library ";
		cout<<"\n press 5 to Check issue method in IR_handle Class";
		cout<<"\n Press 6 Search and display book using ID ";
		cout<<"\n Press 7 Search and display user using ID ";
		cout<<"\n Press 8 to see IR LOG ";
		cout<<"\n press 9 to return book";
		cout<<"\n press 0 to see the search by name function ";
		cout<<endl;
		std::cin.ignore(10, '\n');
		cin>>handle;
		switch(handle)
		{
		case 1:
			Reader::addReader();
			break;
		case 2:
			RegBook::addBook();
			break;
		case 3:
			Reader::displayallReader();
			break;
		case 4:
			RegBook::displayallBooks();
			break;
		case 5:
			IR_handler::Issue();
			break;
		case 6:
			cout<<"\n Enter id to search for ::";
			cin>>test_id;
			test_a=RegBook::findBookby_ID(test_id);
			if(test_a>-1)
					RegBook::displayBook(test_a);
			else
				cout<<"Book not Found"<<endl;
			break;
		case 7:
			cout<<"\n Enter id to search for ::";
			cin>>test_id;
			test_a=Reader::findReaderby_ID(test_id);
			if(test_a>-1)
					Reader::displayReader(test_a);
			else
				cout<<"User not Found"<<endl;
			break;
		case 8:
			IR_handler:: displayall();
			break;
		case 9:
			IR_handler::Return();
			break;
		case 0:
			int i=0;
		int * get =Reader::findReaderby_name("omer bin sohail");
		do{
			Reader::displayReader(get[i]);
			i++;
			cout<<"press enter to c the next";
			getch();
			//Reader::displayReader(get[1]);
		}while(get[i]!=0);
		delete [] get;
		}
		cout<<endl<<endl;
	cout<<"To Test again press 0 ";
	cin>>handle;
	test_a=0;
	test_id=0;
	}while(handle==0);*/