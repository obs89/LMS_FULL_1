#pragma once
class Publication
{
private:
	char title[50];// name of  the book
	char author[30];// writter
	char pubYear[6];// year of publication
public:
	Publication(void);
	Publication(char*,char*,char*);
	//-------------------------------------------------
	//Publication(const &)
	void toupper(char []);// converte string to upper case
	//--------------------------------------------------
	void settitle(char*);
	void setauthor(char*);
	void setpubYear(char*);
	char* getpubYear()const;
	char* getauthor()const;
	char* gettitle()const;
	//----------------------------------------------------
	// I/O need work
	friend void stringinput(char*,int,int,int,int);
	friend void gotoxy(short,short);
	friend void box(int,int,int,int,char,char);
	friend void clrscr();
	friend char getkey();

	void input();
	void show();
	~Publication(void);
};

