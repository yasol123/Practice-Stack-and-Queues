//Implementation file for the IntStack class
#include <iostream>
#include "IntStack.h"
using namespace std;
//Constructor - creates an empty stack. the size parameter is the size of the stack.
IntStack::IntStack(int size) {
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}
//Copy Constructor
IntStack::IntStack(const IntStack& obj) {
	//Create the stack array.
	if (obj.stackSize > 0)
		stackArray = new int[obj.stackSize];
	else
		stackArray = nullptr;
	//Copy the stackSize attribute.
	stackSize = obj.stackSize;
	//Copy the stack content
	for (int count = 0;count < stackSize;count++)
		stackArray[count] = obj.stackArray[count];
	//set the top of the stack.
	top = obj.top;
}
//Destructor
IntStack::~IntStack() {
	delete[] stackArray;
}
//Member Function push pushes the argument onto the stack.
void IntStack::push(int num) {
	if (isFull()) {
		cout << "The stack is FULL.\n";
	}
	else {
		top++;
		stackArray[top] = num;
	}
}
//Member function pop pops the value at the top of the stack off.
//And copies it into the variable passed as an argument.
void IntStack::pop(int& num) {
	if (isEmpty()) {
		cout << "The stack is EMPTY.\n";
	}
	else {
		num = stackArray[top];
		top--;
	}
}
//Member function isFull returns true if the stack is full, or false otherwise.
bool IntStack::isFull() const {
	bool status;
	if (top == stackSize - 1)
		return true;
	else
		return false;
	return status;
}
//Member Function isEmpty returns true if the stack is empty, or false otherwise.
bool IntStack::isEmpty() const {
	bool status;
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}