#include "Date.h"
#include <iostream>
#include <Windows.h>

Date Date::defultdate(3,12,2010);

Date::Date(void):day(0),month(0),year(0)
{/*empty*/}
Date::Date(int INday,int INmonth,int INyear)
{
	(INday==0)?this->day=defultdate.day:setday(INday);
	(INmonth==0)?this->month=defultdate.month:setmonth(INmonth);
	(INyear==0)?this->year=defultdate.year:setyear(INyear);
}
int Date::getday()const
{
	return day;
}

int Date::getmonth()const
{
	
	return month;
}

int Date::getyear()const
{
	return year;
}

void Date::setday(int set)
{
	if(set>0 && set<=31)
		day=set;
}
void Date::setmonth(int set)
{
	if(set > 0 && set <= 12)
	{
		if (day==29 && month==2 && !isleapyear(year))
		{
			day=1;
			month=3;
		}
		else
		{
			month=set;
		}
	}
}

void Date::setyear(int set)
{
	year=set;
}
void Date::setdefultdate(int setd,int setm,int sety)
{
	
	if(setd>0 && setd<=31)
		defultdate.day=setd;
	if(setm > 0 && setm <= 12)
		defultdate.month=setm;
	defultdate.year=sety;
}
bool Date::isleapyear(int is)const// returns true if leapyear
{
	if((is%4==0 && is%100!=0) || (is%400==0))
		return true;
	return false;
}

void Date::addday(int add)
{
	day +=add;
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
		{
			day -=31;
			addmonth(1);
		}

		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if(day > 30)
		{
			day-=30;
			addmonth(1);
		}
		break;
	case 2:
		if (isleapyear(year) && day > 29)
		{
			day -=29;
			addmonth(1);
		}
		else if (!isleapyear(year) && day >28)
		{
			day-=28;
			addmonth(1);
		}
		break;
	}

}
void Date::addmonth(int add)
{
	month += add;
	if (month>12)
	{
		month -=12;
		addyear(1);
	}
	if (day==29 && month==2 && !isleapyear(year))
	{
		day=1;
		month=3;
	}
}
void Date::addyear(int add)
{
	year += add;
	if(day==29 && month ==2 && !isleapyear(year))
	{
		day=1;
		month=3;
	}
}

void Date::showdefult()
{
	std::cout<<defultdate.day<<"  "<<defultdate.month<<"  "<<defultdate.year<<std::endl;
}

void Date::getsystemdate()
{
	SYSTEMTIME Cur_time;
	GetSystemTime(&Cur_time);
	day=Cur_time.wDay;
	month=Cur_time.wMonth;
	year=Cur_time.wYear;
}

bool Date::operator ==(Date with)
{
	if(year==with.year)
	{
		if(month==with.month)
		{
			if (day==with.day)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	else
		return false;
}

int Date::diffindays(const Date check)
{
	Date temp=check;
	int redays=0;
	for(int i=0;;i++)
	{
		if(*this==temp)
			break;
		temp.addday(1);
		redays=i;
		
	}
	return redays;
}
void Date::showdate()
{
	std::cout<<day<<" / "<<month<<" / "<<year<<std::endl;
}
Date::~Date(void)
{
}
