/*
作者:slycarl@163.com
题目:p1576 最长严格上升子序列
*/

// dp[i] 表示以A[i]结尾的最长严格上升子序列的长度

#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> v)
{
	int n = v.size();
	int dp[n];
	int max = 0;
	for(int i=0;i<n;i++)
	{
		dp[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(v[j]<v[i]&&dp[j]+1>dp[i])
			{
				dp[i] = dp[j]+1;
			}
		}
		if(dp[i]>max)
			max = dp[i];
	}

	return max;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	int temp;
	while(n-->0&&cin>>temp)
		v.push_back(temp);

	cout << LIS(v) << endl;

	return 0;

}
