#include <string>

template<class T>
class Node {
public:
	Node* next;
	T datum;
	T& GetDatum() { return datum; }
};
template<class T>
class List {
public:
	Node<T>* head;
	int Count();
};
template<class T>
int List<T>::Count() 
{ /*...*/; return length; }
int main() 
{
	List<int> a;
	List<std::string> b;
	return a.Count(); 
}