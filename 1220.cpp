/*
作者:slycarl@163.com
题目:p1220 数字三角形
*/

// dp[i][j]表示到达i行j列的点的最大值
// dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+chest[i][j]


#include <iostream>
#include <algorithm>

using namespace std;

int dp[100][100];
int chest[100][100];

void GetMax(int n)
{
	int tmp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{	
			tmp = max(dp[i-1][j-1],dp[i-1][j]);
			if(i==1)
				tmp = 0;
			else 
			{
				if(i==j)
					tmp = dp[i-1][j-1];
				else if(j==1)
					tmp = dp[i-1][j];
			}

			dp[i][j] = tmp + chest[i][j];
		}
}

int main()
{
	int n;
	cin >> n;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin >> chest[i][j];

	GetMax(n);

	int maxs = (1<<31);
	for(int j=1;j<=n;j++)
		if(dp[n][j]>maxs)
			maxs = dp[n][j];

	cout << maxs << endl;

	return 0;

}
