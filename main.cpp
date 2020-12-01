#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	IntList intlist;
	intlist.appendInt(1);
	intlist.appendInt(4);
	intlist.appendInt(3);
	intlist.appendInt(8);
	intlist.appendInt(13);
	//display the current appended integers.
	cout << "Current integers list: " << endl;
	intlist.displayInt();
	//insert an integer element.
	intlist.insertInt(10);
	//display the integers list after inserting.
	cout << "After inserting an integer.." << endl;
	intlist.displayInt();
	//delete the last integer element.
	cout << "Now deleting the rear integer.\n";
	intlist.deleteInt(13);
	//display the list
	cout << "Here are the integers left.\n";
	intlist.displayInt();
	cout << endl;
	//remove a front integer element.
	cout << "Remove a front integer.\n";
	intlist.deleteInt(1);
	//display the list.
	cout << "Here are the nodes left.\n";
	intlist.displayInt();
	return 0;
}