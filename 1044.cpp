/*
作者:slycarl@163.com
题目:p1044 拦截导弹
*/

#include <iostream>
#include <vector>

using namespace std;

//就是求最长递减子序列
int MaxMissile(vector<unsigned int> heights)
{
	int dp[heights.size()]; //表示以h[i]结尾的递减子序列的最长长度
	
	int i,j;
	for(i=0;i<heights.size();i++)
	{
		dp[i] = 1;
		for(j=0;j<i;j++)
		{
			if(heights[j]>=heights[i]&&dp[j]+1>dp[i])
				dp[i] = dp[j]+1;
		}
	}

	int max = 0;
	for(i=0;i<heights.size();i++)
	{
		if(dp[i]>max)
			max = dp[i];
	}

	return max;
}

// 就是求最长递增子序列，因为在递增子序列中，有一项，就意味着需要一个系统来拦截这颗导弹
int MinSys(vector<unsigned int> heights)
{
	int dp[heights.size()]; //表示以h[i]结尾的递增子序列的最长长度
	
	int i,j;
	for(i=0;i<heights.size();i++)
	{
		dp[i] = 1;
		for(j=0;j<i;j++)
		{
			if(heights[j]<heights[i]&&dp[j]+1>dp[i])
				dp[i] = dp[j]+1;
		}
	}

	int max = 0;
	for(i=0;i<heights.size();i++)
	{
		if(dp[i]>max)
			max = dp[i];
	}

	return max;
}

int main()
{
	vector<unsigned int> heights;
	int temp;
	while(cin>>temp)
		heights.push_back(temp);
	
	cout << MaxMissile(heights) << endl;

	cout << MinSys(heights) << endl;

	return 0;
}
