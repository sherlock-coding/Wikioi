/*
作者:slycarl@163.com
题目:p1048 石子归并
*/

// dp[i][j]表示从i堆开始到j堆结束合并的最小代价i<=j
// wdp[i][j]表示从i堆开始到j堆结束合并的堆的重量
// dp[i][j] = min{dp[i][k]+dp[k+1][j]+wdp[i][k]+wdp[k+1][j]} i=<k<j

#include <iostream>
#include <vector>
#include <limits>

using namespace std;



int MinCost(const vector<int> &w)
{
	int n = w.size();
	int dp[n+1][n+1];
	int wdp[n+1][n+1]; // 表示i到j合并后的堆的重量
	int i, j, len, k, mincost, weight; 

	for(len=1;len<=n;len++)
	{
		for(i=1;i+len-1<=n;i++)
		{
			j=i+len-1;
			if(i==j)
			{
				dp[i][j] = 0;
				wdp[i][j] = w[i-1];
			}
			else
			{
				mincost = numeric_limits<int>::max();
				weight = 0;
				for(k=i;k<j;k++)
				{
					if(dp[i][k]+dp[k+1][j]+wdp[i][k]+wdp[k+1][j]<mincost)
					{
						weight = wdp[i][k]+wdp[k+1][j];
						mincost = dp[i][k]+dp[k+1][j] + weight;	
					}
				}
				dp[i][j] = mincost;
				wdp[i][j] = weight;
			}
		}
	}

	return dp[1][n];
}

int main()
{
	int n;
	cin >> n;

	vector<int> w;
	int tmp;
	while(n-->0 && cin>>tmp)
		w.push_back(tmp);

	cout << MinCost(w) << endl;

	return 0;
}
