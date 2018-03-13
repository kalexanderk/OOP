#include <queue>  
#include <iostream>  
#include "QueueMember.h"
#include "Queue.h"

using namespace std;

int main() {

	QueueMember array_mem[3];
	array_mem[0] = QueueMember("Andrew", "Hawkings", 2012);
	array_mem[1] = QueueMember("Zlata", "Lilkavich", 2001);
	array_mem[2] = QueueMember("Alexander", "Zolochevsky", 1989);

	Queue<QueueMember> MyQueue(array_mem, 3);
	MyQueue.Print();

	try {
		string name;
		string surname;
		int year;
		cout << "\nEnter name : "; cin >> name;
		cout << "\nEnter surname : "; cin >> surname;
		cout << "\nEnter year : "; cin >> year;
		
		if (year<=1500)
			throw (1);
		else if (year>=3000)
			throw ('z');

		QueueMember NewMember(name, surname, year);

		MyQueue.Push(NewMember);
		cout << "\n\nThe renewed Priority Queue:\n ";
		MyQueue.Print();

	}
	catch (int) {cout << "Letter||Less than 1500.\n";}
	catch (char) {cout << "More than 3000.\n";}
	catch (...) {cout << "Error. :)\n";}

	int n;
	cout << "\nEnter number of members to delete : "; cin >> n;
	for (int i = 0; i < n; i++)
		MyQueue.Delete();
		cout << "\n\nThe renewed Priority Queue:\n ";
	MyQueue.Print();
	
	return 0;
}




