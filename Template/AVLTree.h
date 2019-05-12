#pragma once

template <class NODE> class AVLTree
{
public:

	void insert(NODE *data);
	
	void InOrder();
	void PostOrder();
	void PreOrder();
	
	void deleteNode(NODE * ptr)
	{
		AVLTree<NODE> *CURR = this, *parent = new AVLTree<NODE>;

		while (CURR != NULL && CURR->value != NULL)
		{
			if (ptr < CURR->value)
			{
				parent->value = CURR->value;
				parent->RightChild = CURR->RightChild;
				parent->LeftChild = CURR->LeftChild;
				CURR = CURR->LeftChild;
			}
			else if (ptr > CURR->value)
			{
				parent->value = CURR->value;
				parent->RightChild = CURR->RightChild;
				parent->LeftChild = CURR->LeftChild;
				CURR = CURR->RightChild;
			}
			if (CURR->value == ptr)
			{
				break;
			}

		}
		if (CURR->RightChild == NULL && CURR->LeftChild == NULL)
		{
			cout << "both null"<<endl;
			if (CURR == this)
			{
				this->value = NULL;
			}
			else if (CURR == parent->LeftChild)
			{
				parent->LeftChild = NULL;
				free(CURR);
			}
			else if (CURR == parent->RightChild)
			{
				parent->RightChild = NULL;
				free(CURR);
			}
		}
		else if (CURR->RightChild == NULL && CURR->LeftChild != NULL)
		{
			cout << "left NULL"<<endl;
			if (CURR == this)
			{
				this->value = CURR->LeftChild->value;
				this->RightChild = CURR->LeftChild->RightChild;
				this->LeftChild = CURR->LeftChild->LeftChild;
			}
			else if (CURR == parent->LeftChild)
			{
				parent->LeftChild = CURR->LeftChild;
				free(CURR);
			}
			else if (CURR == parent->RightChild)
			{
				parent->RightChild = CURR->LeftChild;
				free(CURR);
			}
		}
		else if (CURR->RightChild != NULL && CURR->LeftChild == NULL)
		{
			cout << "Right NULL" << endl;
			if (CURR->value == this->value)
			{
				this->value = CURR->RightChild->value;
				this->RightChild = CURR->RightChild->RightChild;
				this->LeftChild = CURR->RightChild->LeftChild;
			}
			else if (CURR->value == parent->LeftChild->value)
			{
				parent->LeftChild = CURR->RightChild;
				free(CURR);
			}
			else if (CURR->value == parent->RightChild->value)
			{
				parent->RightChild = CURR->RightChild;
				free(CURR);
			}
		}
		else if (CURR->RightChild != NULL && CURR->LeftChild != NULL)
		{

			AVLTree<NODE> *Max = CURR->FindMax();
			cout << "MAX" << *(Max->value) << endl;
			cout << "MAX R" << *(Max->RightChild->value) << endl;

			int K = 0;
			AVLTree<NODE>* left = new AVLTree<NODE>;
			if (Max->RightChild->LeftChild != NULL)
			{
				cout << "is NULL";
				left->value = Max->RightChild->LeftChild->value;
				left->RightChild = Max->RightChild->LeftChild->RightChild;
				left->LeftChild = Max->RightChild->LeftChild->LeftChild;
				K = 1;

				cout << "LEFT" << *(left->value) << endl;
			}

			if (CURR->value == this->value)
			{
				*(this->value) = *(Max->RightChild->value);

			}
			else if (CURR->value == parent->LeftChild->value)
			{
				*(parent->LeftChild->value) = *(Max->RightChild->value);
			}
			else if (CURR->value == parent->RightChild->value)
			{
				*(parent->RightChild->value) = *(Max->RightChild->value);

			}

			if (K == 0)
			{
				Max->RightChild->value = NULL;
				Max->RightChild->RightChild = NULL;
				Max->RightChild->LeftChild = NULL;
				Max->RightChild = NULL;
			}
			if (K == 1)
			{
				cout << "K=1" << endl;
				cout << *(left->value) << endl;
				//Max->RightChild=new AVLTree<NODE>;
				Max->RightChild->value = left->value;
				Max->RightChild->RightChild = left->RightChild;
				Max->RightChild->LeftChild = left->LeftChild;
			}
		}
	}
	AVLTree<NODE>* FindParent(AVLTree<NODE>* child)
	{
		if (this->LeftChild->value == child->value || this->RightChild->value == child->value)
		{
			AVLTree<NODE>* CURR = new AVLTree<NODE>;
			CURR->value = this->value;
			CURR->RightChild = this->RightChild;
			CURR->LeftChild = this->LeftChild;
			return CURR;
		}
		if (*(this->value) > *(child->value))
		{
			this->LeftChild->FindParent(child);
		}
		if (*(this->value) < *(child->value))
		{
			this->RightChild->FindParent(child);
		}
	}

	AVLTree<NODE>* FindMax()
	{
		if ( this->RightChild->RightChild == NULL || this->RightChild->RightChild->value == NULL)
		{
			AVLTree<NODE>* CURR = new AVLTree<NODE>;
			CURR->value = this->value;
			CURR->RightChild = this->RightChild;
			CURR->LeftChild = this->LeftChild;
			return CURR;
		}
		else if (this->RightChild != NULL)
		{
			cout << "1ST TIME NULL";
			this->RightChild->FindMax();
		}
	}


private:
	int height;
	AVLTree *RightChild = NULL;
	AVLTree *LeftChild = NULL;
	NODE *value = NULL;

	int getheight();
	int abs(int a);
	void shiftleft();
	void ShiftRight();
	AVLTree<NODE>* findparent(AVLTree<NODE> *CURR);

	
	
};