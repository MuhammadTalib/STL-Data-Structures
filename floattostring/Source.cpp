#include<iostream>
#include <sstream>     // for ostringstream
#include <string>

using namespace std;
int main()
{
	 float fltValue = 1234.567890f;
	ostringstream ostr;

	ostr << fltValue;

	string strValue = ostr.str();

	std::cout << "fltValue = " << fltValue << std::endl;
	std::cout << "strValue = " << strValue << std::endl;

	system("pause");
}