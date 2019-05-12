#pragma once
#include<iostream>
using namespace std;
#include"AVLTree.h"

template<class NODE> void AVLTree<NODE>::insert(NODE* data)
{
	AVLTree<NODE> *ptr = new AVLTree<NODE>;
	ptr->value = data;
	ptr->LeftChild = NULL;
	ptr->RightChild = NULL;
	cout << endl << "ptr before" << *(ptr->value) << endl;
	if (this->value == NULL)
	{
		cout << "is null      " << endl << endl << endl << endl << endl << endl << endl << endl;
		this->value = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
		this->height = 0;
	}
	else
	{
		AVLTree<NODE> *CURR = this;
		while (CURR != NULL)
		{
			if (*(ptr->value) >= *(CURR->value))
			{
				if (CURR->RightChild == NULL)
				{
					CURR->RightChild = ptr;
					CURR->RightChild->height = 0;

					break;
				}
				else if (CURR->RightChild != NULL)
				{
					CURR = CURR->RightChild;
				}
			}
			else if (*(ptr->value) < *(CURR->value))
			{
				if (CURR->LeftChild == NULL)
				{
					CURR->LeftChild = ptr;
					CURR->LeftChild->height = 0;

					break;
				}
				else if (CURR->LeftChild != NULL)
				{
					CURR = CURR->LeftChild;
				}
			}
		}
		cout << endl <<"ptr"<< *(ptr->value) << endl << endl;
		cout << endl <<"curr"<< *(CURR->value) << endl << endl;

		while (1)
		{
			if ((CURR->RightChild)->getheight() > CURR->LeftChild->getheight())
			{
				cout << endl << "CURR->RightChild->getheight()" << CURR->RightChild->getheight() << endl;
				cout << endl << "CURR->LeftChild->getheight()" << CURR->LeftChild->getheight() << endl;
				CURR->height = (CURR->RightChild->height) + 1;

				if ((abs(CURR->LeftChild->getheight() - CURR->RightChild->getheight())) > 1)
				{
					cout << endl << *(CURR->value) << "UNBALA" << endl;
					if (CURR->RightChild->LeftChild->getheight() > CURR->RightChild->RightChild->getheight())
					{
						AVLTree<NODE> *nodeparent = this->findparent( CURR->RightChild);
						(CURR->RightChild)->ShiftRight();
					}
					if (CURR->RightChild->getheight() > CURR->LeftChild->getheight())
					{
						cout << endl << "Normal case" << endl;
						if (CURR == this)
						{
							this->shiftleft();
							CURR = (this);
						}
						else
						{
							AVLTree<NODE> *nodeparent = this->findparent( CURR);
							if(nodeparent->LeftChild!=NULL)
							if (*(CURR->value) == *(nodeparent->LeftChild->value))
							{
								CURR->shiftleft();
								nodeparent->LeftChild = CURR;
							}
							else if (CURR->value == nodeparent->RightChild->value)
							{
								CURR->shiftleft();
								nodeparent->RightChild = CURR;
							}
							break;
						}
					}
				}
				if (CURR != this)
				{
					CURR = this->findparent(CURR);
				}
				else
				{
					cout << endl << "balanced" << endl;
					break;
				}
			}
			else
			{
				cout << endl << "CURR->RightChild->getheight()" << CURR->RightChild->getheight() << endl;
				cout << endl << "CURR->LeftChild->getheight()" << CURR->LeftChild->getheight() << endl;


				CURR->height = (CURR->LeftChild->height) + 1;

				if ((abs(CURR->LeftChild->getheight() - CURR->RightChild->getheight())) > 1)
				{
		
					if (CURR->LeftChild->RightChild->getheight() > CURR->LeftChild->LeftChild->getheight())
					{
						cout << endl << "typical sr case" << endl;
						(CURR->LeftChild)->shiftleft();
					}
					if (CURR->RightChild->getheight() < CURR->LeftChild->getheight())
					{
						cout << endl << "Normal sr case" << endl;
						if (CURR == this)
						{
							cout << endl << "curr is start" << endl;
							CURR->ShiftRight();
							cout << "curr inorder" << endl;
							CURR->InOrder();
						}
						else
						{
							AVLTree<NODE> *nodeparent = this->findparent( CURR);
							if(nodeparent->LeftChild!=NULL)
							if (CURR->value == nodeparent->LeftChild->value)
							{
								CURR->ShiftRight();
								nodeparent->LeftChild = CURR;
							}
							else if (CURR->value == nodeparent->RightChild->value)
							{
								CURR->ShiftRight();
								nodeparent->RightChild = CURR;
							}
							break;
						}
					}
				}
				if (CURR != this)
				{
					cout << endl << "Curr != this" << endl;
					cout << "this ki value" << *(this->value) << endl;
					CURR = this->findparent(CURR);
				}
				else
				{
					break;
				}
			}
		}
	}
}
template<class NODE>
int AVLTree<NODE>::getheight()
{
	if (this == NULL)
	{
		return -1;
	}
	else
	{
		return this->height;
	}
}
template<class NODE>
int AVLTree<NODE>::abs(int a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}
template<class NODE>
void AVLTree<NODE>::shiftleft()
{
	AVLTree<NODE> *CURR = new AVLTree<NODE>;

	CURR->value = this->value;
	CURR->height = (this->RightChild->height) - 1;
	CURR->LeftChild = this->LeftChild;
	CURR->RightChild = this->RightChild->LeftChild;

	this->RightChild->LeftChild = CURR;
	this->value = this->RightChild->value;
	this->LeftChild = CURR;
	this->RightChild = this->RightChild->RightChild;
	
}
template<class NODE>
void AVLTree<NODE>::ShiftRight()
{
	AVLTree<NODE> *CURR = new AVLTree<NODE>;


	CURR->value = this->value;
	CURR->height = (this->LeftChild->height) - 1;
	CURR->LeftChild = (this)->LeftChild->RightChild;
	CURR->RightChild = this->RightChild;
	
	this->LeftChild->RightChild = CURR;
	this->value = this->LeftChild->value;
	this->LeftChild = this->LeftChild->LeftChild;
	this->RightChild = CURR;
	
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::findparent(AVLTree<NODE>* CURR)
{
	if (this->RightChild != NULL && (*(this->RightChild->value) == *(CURR->value)))
	{
		return this;
	}
	if (this->LeftChild != NULL && (*(this->LeftChild->value) == *(CURR->value)))
	{
		return this;
	}

	else if (*(CURR->value) > *(this->value))
	{
		this->RightChild->findparent(CURR);
	}
	else if (*(CURR->value) < *(this->value))
	{
		this->LeftChild->findparent(CURR);
	}
	
}
template<class NODE>
void AVLTree<NODE>::InOrder()
{
	if (this != NULL && this->value!=NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->InOrder();
		}
		cout << *(this->value) << endl;
		this->RightChild->InOrder();
	}
}

template<class NODE>
void AVLTree<NODE>::PostOrder()
{
	if (this != NULL && this->value != NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->PostOrder();
		}
		this->RightChild->PostOrder();
		cout << *(this->value) << endl;
	}
}

template<class NODE>
void AVLTree<NODE>::PreOrder()
{
	if (this != NULL && this->value != NULL)
	{
		cout << *(this->value) << endl;
		if (this->LeftChild != NULL)
		{
			this->LeftChild->PreOrder();
		}
		this->RightChild->PreOrder();
	}
}