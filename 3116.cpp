/* 
 *3116 高精度练习之减法
 */

#include <iostream>
#include <string>

using namespace std;

string ABAdd(string a, string b)
{
	string::reverse_iterator arbegin, arend, brbegin, brend;
	arbegin = a.rbegin();
	arend = a.rend();
	brbegin = b.rbegin();
	brend = b.rend();

	int cadd = 0,temp;
	string c = "";
	while(arbegin!=arend && brbegin!=brend)
	{
		temp = *arbegin++ - '0' + *brbegin++ -'0' + cadd;
		c.push_back(temp%10+'0');
		cadd = temp/10;
	}

	while(arbegin!=arend)
	{
		temp = *arbegin++ -'0'+ cadd;
		c.push_back(temp%10+'0');
		cadd = temp/10;
	}

	while(brbegin!=brend)
	{
		temp = *brbegin++ - '0'+ cadd;
		c.push_back(temp%10+'0');
		cadd = temp/10;
	}

	if(cadd)
		c.push_back(cadd+'0');

	return string(c.rbegin(),c.rend());
}

int main()
{
	string a, b, c;
	cin >> a >> b;
 
	c = ABAdd(a,b);
	cout << c << endl;

return 0;	
}
