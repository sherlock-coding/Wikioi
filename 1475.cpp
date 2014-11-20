/* m进制转十进制 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int m;
	string n;
	cin >> n >> m;

	int len = n.size();
	int sum = 0,i=0;
	while(i<len)
	{
		if(n[len-1-i]>='A'&&n[len-1-i]<='F')
			sum += (n[len-1-i]-'A'+10) * pow(m,i);
		else
			sum += (n[len-1-i]-'0') * pow(m,i);
		i++;
	}

	cout << sum << endl;

	return 0;
}
