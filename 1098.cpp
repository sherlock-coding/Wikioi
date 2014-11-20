/* ¾ù·ÖÖ½ÅÆ */
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a[100]={0};
	int average  = 0;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		average += a[i];
	}
	average /= n;

	int count = 0;
	for(i=0;i<n-1;i++)
	{
		if(a[i]!=average)
		{
			a[i+1] += a[i] - average;
			a[i] = average;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}
