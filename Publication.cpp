#include "Publication.h"
#include<iostream>
#include <cstring>
//using namespace std::strcpy_s;

Publication::Publication(void)
{ /* this is empty */}

Publication::Publication(char* t_in,char*a_in,char*y_in)
{
		strncpy(title,t_in,50);
		strncpy(author,a_in,30);
		strncpy(pubYear,y_in,6);
}
void Publication:: settitle(char* t_in)
{
	strncpy(title,t_in,50);
	toupper(title);
}
void Publication:: setauthor(char* a_in)
{
	strncpy(author,a_in,30);
	toupper(author);
}
void Publication:: setpubYear(char* y_in)
{
	strncpy(pubYear,y_in,6);
}
char* Publication:: getpubYear()const
{
	return (char*)pubYear;
}
char* Publication:: getauthor()const
{
	return (char*)author;
}
char* Publication:: gettitle()const
{
	return (char*)title;
}
void Publication::input()
{
	char temp_title[50];
	char temp_author[30];
	char temp_pubyear[6];
	//std::cout<<"Enter Title :";
	//std::cin>>temp_title;
	stringinput(temp_title,50,37,8,19);
	settitle(temp_title);
	//std::cout<<"Enter name of the author :";
	//std::cin>>temp_author;
	stringinput(temp_author,30,37,11,19);
	setauthor(temp_author);
	//std::cout<<"Enter year of publication :";
	//std::cin>>temp_pubYear;
	stringinput(temp_pubyear,6,37,14,19);
	setpubYear(temp_pubyear);
}
void Publication::show()
{
	std::cout<<"Title : "<<title<<std::endl;
	std::cout<<"Author : "<<author<<std::endl;
	std::cout<<"Year of publication :"<<pubYear<<std::endl;
}

void Publication::toupper(char get[])
{
	int to=strlen(get);
	for(int i=0;i<to;i++)
	{
		if(get[i]>='a' && get[i]<='z')
			get[i]-=(char)32;
	}
}
Publication::~Publication(void)
{
}
