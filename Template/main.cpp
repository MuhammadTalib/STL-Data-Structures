#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "LinkedList.h"
#include"LinkedList.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include"Point.h"
#include"Point.cpp"
#include"BinaryTree.h"
#include"BinaryTree.cpp"
#include"AVLTree.h"
#include"AVLTree.cpp"
#include"Queue.h"
#include"Queue.cpp"
#include"ExpressionTree.h"
#include"ExpressionTree.cpp"
using namespace std;

int main() 
{
	
	int *a = new int;
	*a = 10;
	int *b = new int;
	*b = 11;
	int *c = new int;
	*c = 12;
	int *d = new int;
	*d = 13;
	int *e = new int;
	*e = 14;
	int *f = new int;
	*f = 15;
	int *g = new int;
	*g = 16;



	/*
	point* p = new point , *q= new point , *r= new point;

	Stack<point> *intStacck = new Stack<point>;
	intStacck->push(p);
	intStacck->push(q);
	intStacck->push(r);

	
	while (intStacck->empty()!=1)
	{
		cout << *(intStacck->pop()) << endl;
	}
	
	
	BinaryTree<int> *BT = new BinaryTree<int>;
	BT->insert(a);
	BT->insert(b);
	BT->insert(c);
	BT->insert(d);

	BT->InOrder();
	cout << endl;
	BT->PreOrder();
	cout << endl;
	BT->PostOrder();
	
	
	*/
	AVLTree<int> *root = new AVLTree<int>;
	

	root->insert(a);
	root->insert(b);
	root->insert(c);
	root->insert(d);
	root->insert(e);
	root->insert(f);
	root->insert(g);
	//root->insert(h);
	
	root->deleteNode(f);
	//root->deleteNode(b);
	root->deleteNode(d);

	cout << endl<<"InOrder" << endl;
	root->InOrder();
	cout << endl << "PreOrder" << endl;
	cout << endl;
	root->PreOrder();
	cout << endl << "PostOrder" << endl;
	cout << endl;
	root->PostOrder();
	system("pause");
	/*
	Queue<int> *intQueue = new Queue<int>;
	intQueue->enQueue(a);
	intQueue->enQueue(b);

	while (intQueue->empty() != 1)
	{
		cout << *(intQueue->deQueue())<<endl;
	}
	system("pause");
	
		LinkedList<char>* Infix = NULL, *Postfix = (NODE*)malloc(sizeof(NODE)), *Prefix = (NODE*)malloc(sizeof(NODE));
		BinaryTree<char> *root = new BinaryTree<char>;
		insert(&Infix);
		insert(&Infix);
		insert(&Infix);
		insert(&Infix);
		insert(&Infix);
		insert(&Infix);
		insert(&Infix);

		InfixToPostfixConversion(Infix, &Postfix);
		//cout<<endl<<"Postfix"<<endl;

		//display(Postfix);

		PostfixtoTreeConversion(&root, Postfix);
		//cout<<endl<<"InOrder Tree"<<endl;

		//InOrder(root);

		cout << "Evaluated Value=" << Evaluate(Postfix) << endl;
		cout << endl << "Infix=";
		display(Infix);


		cout << endl;
	

	

	LinkedList<char> *infix = new LinkedList<char>, *postfix = new LinkedList<char>;

	char *value=new char;
	*value = getchar();
	while ( *value != '\n')
	{
		infix->AddNode(value);
		value = new char;
		 *value=getchar();
	}
	
	ExpressionTree *tree = new ExpressionTree(infix);
	LinkedList<char> *post=tree->Infix_ToPostfixConversion();
	if (tree->postfix->value == NULL)
	{
		cout << "NULL";
	}
	tree->postfix->display();
	float *a = new float;*a=1.1;
	cout << tree->Evaluate(a);
	system("pause");*/

}
