#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class IntList {
private:
	struct listInt {
		int integer;//the integer in this list
		struct listInt* next;//point to the next integer
	};
	listInt* head; //integer list head pointer.
public:
	//constructor
	IntList()
	{
		head = nullptr;
	}
	//destructor
	~IntList();
	//append, insert, delete, display member functions
	void appendInt(int);
	void insertInt(int);
	void deleteInt(int);
	void displayInt() const;
};
#endif