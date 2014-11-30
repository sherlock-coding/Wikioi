/*
作者:slycarl@163.com
题目:p1010 过河卒
*/

// dp[i][j] 表示从A点到B(i，j)点的路径数
// dp[i][j] = dp[i-1][j]+dp[i][j-1]  if i-1>=0 and j-1>=0 and 且不是马的控制点

#include <iostream>
#include <cmath>

using namespace std;

int dp[20][20];

bool ControlledByHorse(int i, int j, int X, int Y)
{
	if(i==X&&j==Y)
		return true;
	if(abs(i-X)+abs(j-Y)==3)
	{
		if(i-X!=0 && j-Y!=0)
			return true;
	}
	
	return false;
}

void GetRoutes(int n, int m, int X, int Y)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(!i && !j)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = 0;
				if(ControlledByHorse(i,j,X,Y))
					continue;
				if(i-1>=0)
					dp[i][j] += dp[i-1][j];
				if(j-1>=0)
					dp[i][j] += dp[i][j-1];
			}
		}
	}
}

int main()
{
	int n,m,X,Y;

	cin >> n >> m >> X >> Y;

	GetRoutes(n,m,X,Y);

	cout << dp[n][m] << endl;

	return 0;
}
