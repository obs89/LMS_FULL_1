#pragma once

enum type{
		computer=0,
		science=1,
		arts=2,
		history=3,
		technology=4,
		language=5,
		religion=6,
		student=100,
		teacher=200,
		other=300
	};
// this enum types are used to define reader and book type

class Classification
{
protected:
      type domain;// domain saves the enum type of book or reader
private:
	int genbook();// this ftn genrate ID for books 
	int genuser();// this ftn genrate ID for Readers
	//both above use files to store next to be issued ID.
public:
	Classification(void);//constuctor
	void setdomain(type);//set the domain variable to the enum type 
	int getdomain()const;//get the domain
	int IDgen();//this ftn calls genbook() or genuser() to genrate ID 
	static void createfile_user();//this ftn reset ID files to 0
	static void createfile_book();
	//Warining!!!dont call this ftn unless you reset the database!!!!
	~Classification(void);
};

