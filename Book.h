#pragma once
#include "publication.h"
class Book : public Publication
{
private:
	char ISBN[15];// isbn no
	char publisher[20];// name of publisher
	float DDC;// world standred for sorting books in library
public:
	Book(void);
	Book(char*,char*,float);
	Book(char*,char*,char*,char*,char*,float);
	//--------------------------
	char* getISBN()const;
	char* getpublisher()const;
	float getDDC()const;
	void setISBN(char*);
	void setpublisher(char*);
	void setDDC(float);
	//---------------------------
	//I/O needs work
	void numberinput(int&,short,short);
	void numberinput(float&,short,short);
	void input();
	void show();
	~Book(void);
};

