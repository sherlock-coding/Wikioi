/* µ¥´Ê·­×ª */
#include <iostream>
#include <string>

using namespace std;


int main()
{
    string sa[1000];
	char tmp;
	int i =0;
	while(cin)
	{
		cin >> sa[i++];
		if (cin.get()=='\n')
			break;
	} 

	for(int k=i-1;k>=0;k--)
	{
		cout << sa[k] << " ";
	}

	return 0;
}

