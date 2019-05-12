#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<class NODE> class N
{
public:
	NODE *value = NULL;
	N(){}
	void display() { 
		if(this!=NULL) 
			this->value->display(); 
	};
};


template <class NODE>
class LinkedList {

private:



public:
	N<NODE> *value = NULL;
	LinkedList<NODE> *Next = NULL;

	void AddNode(NODE**  ptr);
	LinkedList* getNext();
	NODE* getValue();
	void display();

	bool empty() const {
		return value.empty();
	}
};

