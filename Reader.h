#pragma once
#include "person.h"
#include "Classification.h"


class Reader : public Person
{
private:
	Classification user_type;// save the type of user
	int user_id;// save the ID this members is auto genrated base on the user type
				// see Class of Classification for more details 
	int haveBook[3];//an array to store issued books,one user can be issue more then 3 books
	void setuser_id();// this ftn does not interact with the world base on Classification

public:
	Reader(void);
	//-------------------------
	void setuser_type(type);
	int getuser_type()const;
	int getuser_id()const;
	bool sethaveBook(int);// this seter has bool return type so that it can determin
	                      //can more books be issued
	int* gethaveBook()const;//
	bool unsethaveBook(int);// to make

	//--------------------------
	void showhaveBook();//display current holding books
	void input();// class I/O
	void show();//
	//void appReader();// under conctruction
	friend char getkey();
	void showhelper();
	//----------------------------------
	//class inferface-----------------static ftn----------------- 
	static void addReader();
	static void displayallReader();
	static void displayReader(int);// display user based on the ID in paramerter
	static void delReader();// under conctruction
	static int findReaderby_ID(int);//
	static int* findReaderby_name(char*);
	//static void updateReader(int);//update by id under construction
	static bool setissue(int,int);//works fine now.....
	static bool unsetissue(int,int);
	static int totalReader();


	~Reader(void);
};