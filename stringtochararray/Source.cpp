#include <iostream>
#include<string>

using namespace std;


int main()
{

	string s ;
	cin >> s;
	char *i = new char;
	*i=s[0];
	int j = 1;
	while (*i != '\0')
	{
		cout << *i;
		*i = s[j];
		j++;
	}
	
	
	//for (int i = 0; i < n; i++)
		//cout << char_array[i];

	system("pause");
}