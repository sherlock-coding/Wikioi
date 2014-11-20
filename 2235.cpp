/* »úÆ±´òÕÛ  */
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double price,discount;
	cin >> price >> discount;
	cout << round(price * discount/100.0)*10 <<endl;
	return 0;
}
