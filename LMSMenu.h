#pragma once
#include <fstream>
#include "Classification.h"
#include "Date.h"
#include"RegBook.h"
#include"Reader.h"
#include "IR_handler.h"


class LMSMenu
{
public:
	LMSMenu(void);
	//void intro();
	//void welcome(int,int,int);
	static void border();
	void install();
	void numberinput(int&,short,short);
	bool isfile_book();
	bool isfile_reader();
	void mainmenu();
	void addmenu();
	void irmenu();
	void searchmenu();
	void searchbook();
	void searchmember();
	void helper_searchmemberID();
	void helper_searchmemberNAME();
	void helper_searchbookID();
	void helper_searchbookTITLE();
	void helper_searchbookAUTHOR();
	int helper_noofresults(int*);
	//bool password();



	friend char getkey();
	friend void stringinput(char*,int,int,int,int);
	friend void gotoxy(short,short);
	friend void box(int,int,int,int,char,char);
	friend void clrscr();
	~LMSMenu(void);
};

