/* 3n+1Œ Ã‚ */
#include <iostream>

using namespace std;

int n[100] = {0};

int countStep(int n)
{
	int num = 0;
	
	if(n>1)
	{
		if(n%2!=0)
		{
			num += 1 + countStep(3*n+1);
		}
		else
		{
			num += 1 + countStep(n/2);
		}
	}

	return num;
}

int main()
{
	int T;
	cin >> T;

	for(int i=0;i<T;i++)
	{
		cin >> n[i];
	}
	for(int j=0;j<T;j++)
		cout << countStep(n[j]) << endl;
	return 0;
}
