/*
作者:slycarl@163.com
题目:p1017 乘积最大
*/

//dp[j][k] 表示从1到j个数字插入k个乘号所得到的最大值
//dp[j][k] = max(dp[i][k-1]*A[i+1][j]) k=<i<j
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long strtol(string s)
{
	string::reverse_iterator it = s.rbegin();
	int i = 0;
	long sum = 0;
	while(it!=s.rend())
	{
		sum += (*it++-'0')*pow(10,i);
		i++;
	}

	return sum;
}

long dp[41][7];

int GetMax(int n, int k, string s)
{
	int i,j,m,maxnum,temp;
	for(i=1;i<=n;i++)
		dp[i][0] = strtol(s.substr(0,i));
	for(j=1;j<=k;j++)
	{
		maxnum = 0;
		for(i=j+1;i<=n;i++)
		{
			for(m=j;m<i;m++)
			{
				temp = dp[m][j-1]*strtol(s.substr(m,i-m));
				if(temp>maxnum)
					maxnum = temp;
			}
			dp[i][j] = maxnum;
		}
	}

	return dp[n][k];
}


int main()
{
	int n,k;
	string s;

	cin >> n >> k >> s;

	cout << GetMax(n,k,s) << endl;

	return 0;
}
