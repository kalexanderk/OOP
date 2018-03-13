#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>

using namespace std;

Date::Date() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	day = ltm->tm_mday;
	month = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;

}

Date::Date(int day, int month, int year) {
	(*this).day = day;
	(*this).month = month;
	(*this).year = year;

}

Date::Date(const Date &object) {
	(*this).day = object.day;
	(*this).month = object.month;
	(*this).year = object.year;
}

Date& Date::operator=(Date& object) {
	(*this).day = object.day;
	(*this).month = object.month;
	(*this).year = object.year;
	return *this;
}

Date& Date::operator +(Date& object) {
	(*this).day += object.day;
	(*this).month += object.month;
	(*this).year += object.year;
	return *this;
}

bool Date::operator >(Date& object) {
	if ((*this).year == object.year)
		if ((*this).month == object.month)
			if ((*this).day > object.day)
				return true;
			else
				return false;
		else
			if ((*this).month > object.month)
				return true;
			else
				return false;
	else
		if ((*this).year > object.year)
			return true;
		else
			return false;

};

bool Date::operator <(Date& object) {
	if ((*this).year == object.year)
		if ((*this).month == object.month)
			if ((*this).day < object.day)
				return true;
			else
				return false;
		else
			if ((*this).month < object.month)
				return true;
			else
				return false;
	else
		if ((*this).year < object.year)
			return true;
		else
			return false;

};

bool Date::operator==(Date & object) {
	if (((*this).year == object.year) && ((*this).month == object.month) && ((*this).day == object.day))
		return true;
	else
		return false;
}

Date::~Date() {

};

int Date::GetDay() {
	return (*this).day;
}

int Date::GetMonth() {
	return (*this).month;
}

int Date::GetYear() {
	return (*this).year;
}

Date& Date::GetDate() {
	return *this;
}

void Date::ShowDataClass() {
	cout << "DATE: " << day << "." << month << "." << year << "\n";
}

Date& Date::SetDay(int day) {
	(*this).day = day;
	return *this;
}

Date& Date::SetMonth(int month) {
	(*this).month = month;
	return *this;
}

Date& Date::SetYear(int year) {
	(*this).year = year;
	return *this;
}