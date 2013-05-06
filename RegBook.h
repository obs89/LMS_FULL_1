#pragma once
#include "book.h"
#include "classification.h"

//child of Book and Grandchild of Publication

class RegBook :public Book
{
private:
	int copies;//total no of copies library have 
	int ID;// id of book
	Classification type;// type of book
	bool issue_state;// if true, it means book can be issued
	int issued_copies;//keep record of how many copies have been issued

	//Issue_status state;
	void inputcatagory();
public:
	RegBook(void);
	void setcopies(int);
	void setID(int);
	void setissue_state();
	//void setissued_copies();
	int getcopies()const;
	int getID()const;
	int getissued_copies()const;
	void addissued_copies();
	void subissued_copies();
	bool getissue_state()const;
	//--------------------------------
	//I/O needs work
	void input();
	void show();
	void showhelper();
	void showhelper_out();
	//----------------------------
	static void addBook();
	static void displayallBooks();
	static int findBookby_ID(int find);
	static int* findBookby_Title(char *);
	static int* findBookby_Author(char *);
	static void displayBook(int on);
	static bool setissue(int);
	static bool unsetissue(int);//made
	static int totalBook();
	//list of static is not complete
	~RegBook(void);
};

