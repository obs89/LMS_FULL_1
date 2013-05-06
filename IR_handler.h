#pragma once
#include"Date.h"
#include"Reader.h"
#include"RegBook.h"

class IR_handler
{
private:
	Date issue_date;
	int reader_id;
	int book_id;
	bool del_flag;//if false can't be deleted
	static int keepperday_T;
	static int keepperday_S;
	static int keepperday_O;

public:
	int fine(int);// made
	void input();
	void show();
	void numberinput(int&,short,short);
	static void Issue();// rearrange
	static void Return();//
	static int findrecord(IR_handler);
	static void Book_return();
	static void displayall();
	//geters and setters
	friend char getkey();
	friend void stringinput(char*,int,int,int,int);
	friend void gotoxy(short,short);
	friend void box(int,int,int,int,char,char);
	friend void clrscr();
	IR_handler(void);
	~IR_handler(void);
};















/*#pragma once
class Issue_status
{
protected:

	

public:
	Issue_status(void);
	void setissue_status(); 
	static saveissue
	~Issue_status(void);
};

*/