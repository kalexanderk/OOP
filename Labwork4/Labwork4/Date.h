#pragma once
#pragma once
#include <time.h>

class Date
{
private:
	int day, month, year;

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date &object);
	Date& operator =(Date& object);
	Date& operator +(Date& object);
	bool operator >(Date& object);
	bool operator <(Date& object);
	bool operator ==(Date& object);

	~Date();

	int GetDay();
	int GetMonth();
	int GetYear();
	Date& GetDate();

	void ShowDataClass();

	Date& SetDay(int day);
	Date& SetMonth(int month);
	Date& SetYear(int year);
};
