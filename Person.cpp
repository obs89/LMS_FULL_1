#include "Person.h"
#include <cstring>
#include <iostream>
Person::Person(void)
{
}

void Person::setname(char *in)
{
	//toupper(in); bad pointer
	strncpy(name,in,30);	
	toupper(name);
}
char* Person::getname()
{
	return (char*)name;
}
void Person:: input()
{
	char temp_name[30];
	//clrscr();
	stringinput(temp_name,30,23,10,15);
	//std::cin>>temp_name;
	//std::cout<<"\n";
	setname(temp_name);

}
void Person:: show()
{
	std::cout<<name<<std::endl;
}

void Person::toupper(char get[])
{
	int to=strlen(get);
	for(int i=0;i<to;i++)
	{
		if(get[i]>='a' && get[i]<='z')
			get[i]-=(char)32;
	}
}
Person::~Person(void)
{
}
