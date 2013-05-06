#include "Book.h"
#include<cstring>
#include<iostream>

Book::Book(void)
{
}
Book::Book(char* isbn_in,char* pub_in,float val)
{
	strncpy(ISBN,isbn_in,15);
	strncpy(publisher,pub_in,20);
	if(val>=0.0 && val<1000.0)
		DDC=val;
}
Book::Book(char* N_in,char*A_in,char* Y_in,char*isbn_in,char* pub_in,float val): Publication(N_in,A_in,Y_in)
{
	strncpy(ISBN,isbn_in,15);
	strncpy(publisher,pub_in,20);
	if(val>=0.0 && val<1000.0)
		DDC=val;
}
char* Book:: getISBN()const
{
	return (char*)ISBN;
}
char* Book:: getpublisher()const
{
	return (char*)publisher;
}
float Book:: getDDC()const
{
	return DDC;
}
void Book:: setISBN(char* isbn_in)
{
	strncpy(ISBN,isbn_in,15);
}
void Book:: setpublisher(char* pub_in)
{
	strncpy(publisher,pub_in,20);
	toupper(publisher);
}
void Book:: setDDC(float val)
{
	if(val>=0.0 && val<1000.0)
		DDC=val;
}
void Book::input()
{
	char temp_ISBN[15];
	char temp_publisher[20];
	float temp_DDC;
	stringinput(temp_ISBN,15,37,17,19);
	setISBN(temp_ISBN);
	stringinput(temp_publisher,20,37,20,19);
	setpublisher(temp_publisher);
	numberinput(temp_DDC,37,23);
	setDDC(temp_DDC);
}

void Book:: numberinput(int& temp,short x,short y)
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
void Book:: numberinput(float& temp,short x,short y)
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
		std::cout<<"           ";
		gotoxy(x,y);
		//
		std::cin.ignore(10, '\n'); // remove newline
	}
}
void Book::show()
{
	std::cout<<"ISBN Number :"<<ISBN<<std::endl;
	std::cout<<"Publisher :"<<publisher<<std::endl;
	std::cout<<"DDC Number :"<<DDC<<std::endl;
}
Book::~Book(void)
{
}
