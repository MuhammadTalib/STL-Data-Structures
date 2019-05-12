#include<iostream>
using namespace std;
#include <math.h>

int main()
{

	float val = 2.000005;

	float rounded_down = floorf(val * 1000) / 1000;   /* Result: 37.77 */
	float nearest = roundf(val*1000 )/1000  ;  /* Result: 37.78 */
	float rounded_up = ceilf(val*1000 )/1000;      /* Result: 37.78 */
	cout <<val<<" = " <<"rounded_down"<<rounded_down<<endl<<"nearest"<<nearest<<endl<<"rounded_up"<< rounded_up;
	system("pause");
}