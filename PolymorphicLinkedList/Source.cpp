#include<iostream>
using namespace std;
#include"LinkedList.h"
#include"LinkedList.cpp"

class animal:public N<animal>
{
public:
	animal()
	{

	}
	animal(string name)
	{
		this->name = name;
	}
	void display()
	{
		cout<<"In animal="<<this->name;
	}
protected:
	string name;
};
class cat:public animal
{
private:

public:
	cat(string name)
	{
		this->name = name;
	}
	void display()
	{
		cout << "In cat=" << this->name;
	}
};
class dog:public animal
{
private:
public:
};
int main()
{

	animal *anime = new animal("animal1");
	animal *anime1 = new animal("animal2");
	animal *anime2 = new cat("cat");

	LinkedList<animal> *animals = new LinkedList<animal>;
	animals->AddNode(&anime);
	animals->AddNode(&anime1);
	animals->AddNode(&anime2);

	animals->display();

	system("pause");
}