/* 最大公约数 */

#include <iostream>

using namespace std;

int gcd(int a, int b) // a>=b
{
	int r;

	while(b>0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int a,b;
	cin >> a >> b;

	int result;
	if(a>=b)
	{
		result = gcd(a,b);
	}
	else
	{
		result = gcd(b,a);
	}

	cout << result << endl;

	return 0;
}
