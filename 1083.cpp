/* Cantor±í */
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = 1,s=0;

	while(1)
	{
		s += k;
		if(n<=s)
			break;
		k++;
	}

	int numerator,denominator;
	if(k%2==0)
	{
		numerator = n - s + k;
		denominator = k + 1 - numerator;
	}
	else
	{
		denominator = n - s + k;
		numerator = k + 1 - denominator;
	}

	cout << numerator << "/" << denominator <<endl;

	return 0;
}
