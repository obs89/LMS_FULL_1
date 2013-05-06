#include "Classification.h"
#include <fstream>
#include<iostream>
using namespace std;
Classification::Classification(void)
{
}
//======================Setter and Getters===============================
void Classification:: setdomain(type in)
{
	domain=in;
}
int Classification:: getdomain()const
{
	return domain;
}
//=======================================================================
/*	computer=0,
science=1,
arts=2,
history=3,
technology=4,
language=5,
religion=6,
student=100,
teacher=200,
other=300*/
//enum types!!
int Classification:: IDgen()
{
	int ret;
	switch(domain)
	{
	case computer:// cases for Book
	case science:
	case arts:
	case history:
	case technology:
	case language:
	case religion:
		ret=genbook();
		break;
	case student:// cases for Reader
	case teacher:
	case other:
		ret=genuser();
		break;
	}
	return ret;
}

int Classification::genbook()
{

		fstream file;
		int temp,send;
		file.open("total.txt",ios::in);
		if(!file)
				cout<<"File does not exist or file is corrupted!"<<endl;
		else
			file>>temp;

		send=temp+1;
		file.close();
		file.open("total.txt",ios::out);
		if(!file)
			cout<<"File does not exist or file is corrupted!"<<endl;
		else
			file<<send;
		return send;

}

int Classification::genuser()
{
	fstream file;
		int temp,send;
		file.open("user.txt",ios::in);
		if(!file)
			cout<<"File does not exist or file is corrupted!"<<endl;
		file>>temp;
		send=temp+1;
		file.close();
		file.open("user.txt",ios::out);
		if(!file)
			cout<<"File does not exist or file is corrupted!"<<endl;
		file<<send;
		return send;
}
//=========================================================================
// USE WITH CARE!!!!!!!!!!!!!!!!!
void Classification::createfile_book()
{
	fstream create;
	int a=0;
	create.open("total.txt",ios::out);
	if(!create)
		cout<<"File cannot be created!";
	else
		create<<a;
	create.close();
}

void Classification::createfile_user()
{
	fstream create;
	int a=0;
	create.open("user.txt",ios::out);
	if(!create)
		cout<<"File cannot be created!"<<endl;
	else
		create<<a;
	create.close();
}

Classification::~Classification(void)
{
}
