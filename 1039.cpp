/*
����:slycarl@163.com
��Ŀ:p1039 ���Ļ���
*/

// dp[i]j]��ʾ����i���ֳ�j�ݵķַ�����
// dp[i][j] = dp[i-j][j]��ÿ���ж�������1��
// 			+ dp[i-1][j-1] ������һ��Ϊ1��


#include <iostream>

using namespace std;

int dp[201][7];

int GetSum(int n, int k)
{
	int i,j,sum,p;
	for(i=1;i<=n;i++)
		dp[i][1] = 1;
	for(j=1;j<=k;j++)
		dp[j][j] = 1;
	for(j=2;j<=k;j++)
	{
		for(i=j+1;i<=n;i++)
		{
			dp[i][j] = dp[i-1][j-1];
			if(i-j>=j)
				dp[i][j] += dp[i-j][j];
		}
	}

	return dp[n][k];
}

int main()
{
	int n,k;
	cin >> n >> k;

	cout << GetSum(n,k) << endl;
}
