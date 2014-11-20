/* 判断浮点数是否相等  */
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b;
	cin >> a >> b;
	double c = fabs(a-b);
	if(c <= pow(10,-8))
		cout << "yes" << endl;
	else
		cout << "no" <<endl;
	return 0;
}
