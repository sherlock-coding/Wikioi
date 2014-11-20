/* 最小数和最大数 */
#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int min=INT_MAX,max=INT_MIN;
	int n,temp;
	cin>>n;
	while(n--)
	{
		cin>>temp;
		if(temp>max)
			max = temp;
		if(temp<min)
			min = temp;
	}
	cout << min << " " << max <<endl;
	return 0;
}
