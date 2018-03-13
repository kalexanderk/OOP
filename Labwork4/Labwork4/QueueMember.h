#pragma once
#include <string>

using namespace std;

class QueueMember {

private:
	string name;
	string surname;
	int yearentry;

public:
	QueueMember();
	QueueMember(string name, string surname, int yearentry);

	friend ostream& operator <<(ostream & os, QueueMember& o);
	friend istream& operator >>(istream & is, QueueMember& o);

	int GetYearOfEntry();

};
