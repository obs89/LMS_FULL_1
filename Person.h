#pragma once

// this is the base class of Reader!!!
class Person
{
	char name[30];
	//more data members can be added.......
	// 
public:
	Person(void);
	void setname(char *);
	char* getname();
	void toupper(char[]);// convert the string to upper case
	void input();//input of the class
	void show();//outpt of the class
	//-------------------FRIEND----------------------
	friend void stringinput(char*,int,int,int,int);
	friend void gotoxy(short,short);
	friend void box(int,int,int,int,char,char);
	friend void clrscr();
	//-----------------------------------------------
	//input() and show() needs work.!!!!!!!!!!!big time
	~Person(void);
};

