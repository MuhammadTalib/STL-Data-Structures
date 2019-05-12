#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include<string.h>
#include <stdexcept>
using namespace std;
class point {
public:
	point(string name,int x,int y)
	{
		this->name = name;
		this->x = x;
		this->y = y;
	}
	friend ostream& operator <<(ostream& o, point &p)
	{
		return o << p.name<<endl<<p.x<<endl<<p.y<<endl<<endl;
	}
	string name;
	int x;
	int y;
};
using namespace std;

template <class NODE> class LinkedList {

private:

	NODE *value = NULL;
	LinkedList *Next = NULL;


public:

	void AddNode(NODE*  ptr);
	LinkedList* getNext();
	NODE* getValue();
	void display();

	bool empty() const {
		return value.empty();
	}
};


template <class NODE> LinkedList<NODE>* LinkedList<NODE>::getNext()
{
	return this->Next;
}
template<class NODE> NODE* LinkedList<NODE>::getValue()
{
	return this->value;
}
template<class NODE> void LinkedList<NODE>::AddNode(NODE*  ptr)
{
	if (this->value == NULL)
	{
		this->value = ptr;
		this->Next = NULL;
	}
	else
	{
		LinkedList *ptr1 = new LinkedList<NODE>;
		ptr1->value = ptr;
		ptr1->Next = NULL;

		LinkedList *CURR = this;
		while (CURR->Next != NULL)
		{
			CURR = CURR->Next;
		}
		CURR->Next = ptr1;
	}
}
template <class NODE> void LinkedList<NODE>::display()
{
	LinkedList *CURR = this;
	while (CURR != NULL)
	{
		cout << *(CURR->value) << endl;
		CURR = CURR->Next;
	}
}

int main()
{
	point *a=new point("Talib",2,3);
	point *b = new point("Talib",4,5);
	
	LinkedList<point> *list = new LinkedList<point>;
	list->AddNode(a);
	list->AddNode(b);

	list->display();

	system("Pause");
}

