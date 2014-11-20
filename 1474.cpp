/* 十进制转m进制 */
#include <iostream>
#include <vector>

using namespace std;

char table[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main()
{
	int n,m;
	cin >> n >> m;

	int a[8];

	int r = n;
	int i = 0;
	while(r>0)
	{
		a[i++] = r % m;
		r = r / m;
	}

	for(;i>0;i--)
		cout << table[a[i-1]];
	cout << endl;

	return 0;
}
