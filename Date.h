#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
	static Date defultdate;
	bool isleapyear(int)const;
public:
	Date(void);
	Date(int,int,int);
	int getday()const;
	int getmonth()const;
	int getyear()const;
	void setday(int);
	void setmonth(int);
	void setyear(int);
	void addday(int);//
	void addmonth(int);//
	void addyear(int);//
	//--------------------------------------------------------------------------
	void getsystemdate();// gets the current system date
	int diffindays(const Date);// return difference in days from the current date to issued date!
	//--------------------------------------------------------------------------
	static void setdefultdate(int,int,int);
	bool operator ==(Date);
	void showdefult();
	void showdate();
	~Date(void);
};

