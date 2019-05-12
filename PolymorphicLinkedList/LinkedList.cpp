#pragma once
#include"LinkedList.h"
template <class NODE> LinkedList<NODE>* LinkedList<NODE>::getNext()
{
	return this->Next;
}
template<class NODE> NODE* LinkedList<NODE>::getValue()
{
	return this->value;
}

template<class NODE> void LinkedList<NODE>::AddNode(NODE**  ptr)
{
	if(this->value!=NULL)
	if (this->value->value == NULL)
	{
		this->value->value = *ptr;
		this->Next = NULL;
	}
	else
	{
		LinkedList *ptr1 = new LinkedList<NODE>;
		ptr1->value->value = *ptr;
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
	while (CURR!=NULL)
	{
		(CURR->value)->display();
		cout << endl;
		CURR = CURR->Next;
	}
}

