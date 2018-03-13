#include "QueueMember.h"
#include <iostream>  
using namespace std;

QueueMember::QueueMember() {
	name = "NoName";
	surname = "NoSurname";
	yearentry = 2000;
}

QueueMember::QueueMember(string name, string surname, int yearentry) {
	this->name = name;
	this->surname = surname;
	this->yearentry = yearentry;
}

ostream& operator <<(ostream & os, QueueMember& o) {	
	os << "name : " << o.name << "\n";
	os << "surname : " << o.surname << "\n";
	os << "year_start : "<< o.yearentry << "\n";
	return os;
}


istream& operator >>(istream & is, QueueMember& o) {
	cout << "Enter Name : "; is >> o.name;
	cout << "Enter Surname : "; is >> o.surname;
	int temp;
	cout << "Enter Year"; is >> temp;
	if (temp>1500 && temp <3000) o.yearentry = temp;
	else o.yearentry = 0;
	return is;
}

int QueueMember::GetYearOfEntry() {
	return this->yearentry;
}


