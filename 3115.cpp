/*
作者:slycarl@163.com
题目:p3115 高精度练习之减法
*/

#include <iostream>
#include <string>

using namespace std;

string BigNumberMinus(string a, string b)
{
	string::reverse_iterator arit = a.rbegin();
	string::reverse_iterator brit = b.rbegin();

	string amb = "";

	int c = 0;
	int tmp,rel;
	int flag,i;
	if(a.length()>b.length())
		flag = 1;
	else
	{
		if(a.length()<b.length())
			flag = 0;
		else
		{
			for(i=0;i<a.length();i++)
			{
				if(a[i]>b[i])
				{
					flag = 1;
					break;
				}
				if(a[i]<b[i])
				{
					flag = 0;
					break;
				}
			}

			if(i==a.length())
				return "0";

		}
	}


	while(arit!=a.rend()&&brit!=b.rend())
	{
		if(flag)
			tmp = *arit-*brit-c;
		else
			tmp = *brit-*arit-c;
		if(tmp<0)
		{
			c = 1;
			tmp = tmp+10;
		}
		else
			c = 0;
		amb.push_back(tmp+'0');
		arit++;
		brit++;
	}

	while(arit!=a.rend())
	{
		tmp = *arit-'0'-c;
		if(tmp<0)
			c = 1;
		else 
			c = 0;
		amb.push_back(tmp+'0');
		arit++;
	}

	while(brit!=b.rend())
	{
		tmp = *brit-'0'-c;
		if(tmp<0)
			c = 1;
		else 
			c = 0;
		amb.push_back(tmp+'0');
		brit++;
	}


	if(!flag)
		amb.push_back('-');

	string t = "";
	for(i=amb.size()-1;i>=0;i--)
	{
		t.push_back(amb[i]);
	}

	return t;
}

int main()
{
	string a,b;
	cin >> a >> b;

	cout << BigNumberMinus(a,b) << endl;

	return 0;
}
