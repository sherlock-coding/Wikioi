/* 
作者:slycarl@163.com
题目:p3117 高精度练习之乘法
 */

#include <iostream>
#include <string>

using namespace std;

string ABMultiply(string a, string b)
{
	string::reverse_iterator arbegin, arend, brbegin, brend, crbegin, crend;
	arbegin = a.rbegin();
	arend = a.rend();
	brbegin = b.rbegin();
	brend = b.rend();

	string c(a.size()+b.size(),'0');
	crbegin = c.rbegin();
	crend = c.rend();
	int temp ;

	while(arbegin!=arend)
	{
		brbegin = b.rbegin();
		while(brbegin!=brend)
		{
			temp =  (*arbegin-'0')*(*brbegin -'0');
			temp += *(crbegin+ (brbegin-b.rbegin())+(arbegin-a.rbegin())) - '0'  ;
			*(crbegin+ (brbegin-b.rbegin())+(arbegin-a.rbegin())+1) += temp/10;
			*(crbegin+ (brbegin-b.rbegin())+(arbegin-a.rbegin())) = temp%10+'0';
			brbegin++;
		}
		arbegin++;
	}

	if(*c.begin()=='0')
		return c.substr(1,c.size()-1);

	return c;
	
}


int main()
{
	string a,b;
	cin >> a >> b;
	cout << ABMultiply(a,b) << endl;
}
