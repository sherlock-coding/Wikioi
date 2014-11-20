/* 最大公约数和最小公倍数问题 */
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int x0,y0;
	cin >> x0 >> y0;

	if(x0>y0 || y0%x0!=0)
	{
		cout << 0 << endl;
		return 0;
	}

	int n = y0/x0;
	int i;
	int count = 0;

	map<int ,int>  m;
	pair<map<int,int>::iterator,bool> ret;
     
	if(n==1)
	{
		cout << 1 <<endl;
		return 0;
	}

	while(n>1)
	{
		i = 2;
		while(1)
		{
			if(n%i==0)
			{
				n /= i;
				ret = m.insert(map<int,int>::value_type(i,1));
				if(ret.second)
					count++;
				break;
			}
			i++;
		}		
	}

	cout << pow(2,count) << endl;

	return 0;
}
