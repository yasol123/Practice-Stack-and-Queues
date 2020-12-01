#include <iostream>
#include "LinkedList.h"
using namespace std;
void IntList::appendInt(int num) {
	listInt* newNode;
	listInt* nodePtr;
	newNode = new listInt;
	newNode->integer = num;
	newNode->next = nullptr;
	if (!head) {//if there is no integer in the list, make newNode the first node.
		head = newNode;
	}
	else {//initialize nodePtr to head of list.
		nodePtr = head;
		//find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		//insert newNode as the last node.
		nodePtr->next = newNode;
	}
}
void IntList::insertInt(int num) {
	listInt* newNode; //a new int
	listInt* nodePtr;//to traverse the list.
	listInt* previousNode = nullptr;//previous int
	//allocate & store a num
	newNode = new listInt;
	newNode->integer = num;
	if (!head) {//if there is no int, make the first node.
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		nodePtr = head;
		//initialize previousNode to nullptr.
		previousNode = nullptr;
		//skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->integer < num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if the new node is to be the 1st in the last, insert it before all other nodes.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
void IntList::deleteInt(int num) {
	listInt* nodePtr;
	listInt* previousNode;
	//determine if the first node is the one.
	if (head->integer == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		//initialize nodePtr to head of list.
		nodePtr = head;
		//skip all nodes whose value number is not equal to num.
		while (nodePtr != nullptr && nodePtr->integer != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if nodePtr is not at the end of the list, 
		//link the previous node to the node after nodePtr, then delete nodePtr
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
void IntList::displayInt()const {
	listInt* nodePtr;
	nodePtr = head;
	while (nodePtr) {
		cout << nodePtr->integer << endl;
		nodePtr = nodePtr->next;
	}
}
IntList::~IntList() {
	listInt* nodePtr;
	listInt* nextNode;
	//position nodePtr at the head of the list.
	nodePtr = head;
	//while nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		//save a pointer to the next node.
		nextNode = nodePtr->next;
		//delete the current node.
		delete nodePtr;
		//position nodePtr at the next node.
		nodePtr = nextNode;
	}
}