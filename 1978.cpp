/* FibonacciÊıÁĞ 3 */
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int pre = 1;
	int next = 1;
	int tmp;

	while(n-2>0)
	{
		tmp = pre + next;
		pre = next;
		next = tmp;
		n--;
	}	

	cout << next << endl;

	return 0;
}
