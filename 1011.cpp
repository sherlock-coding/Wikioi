/* ÊıµÄ¼ÆËã */
#include <iostream>

using namespace std;

int getNum(int n)
{
	int num = 1;
	for(int i=1;i*2<=n;i++)
	{
		num += getNum(i);
	}

	return num;
}

int main()
{
	int n;
	cin >> n;
	
	cout << getNum(n) << endl;

	return 0;
}
