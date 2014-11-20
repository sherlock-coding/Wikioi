/* ËØÊıÅĞ¶¨ */
#include <iostream>

using namespace std;

bool isPrime(int a)
{
	if(a<2)
		return false;
	if(a==2||a==3)
		return true;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}

int main()
{	
	int n;
	cin >> n;

	if(isPrime(n))
		cout << "\\t" << endl;
	else
		cout << "\\n" << endl;

	return 0;
}
