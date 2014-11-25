/*
作者:slycarl@163.com
题目:p3027 线段覆盖 2
*/

// dp[i] 表示以第i个线段结尾的最大价值

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
	int ai;
	int bi;
	int ci;
} edge;

bool cmp(edge l1, edge l2)
{
	if(l1.bi<=l2.bi)
		return true;
	return false;
}

int MaxValue(vector<edge> v)
{
	int n = v.size();
	sort(v.begin(),v.end(),cmp);
	int dp[n];
	int max_value = 0;
	for(int i=0;i<n;i++)
	{
		dp[i] = v[i].ci;
		for(int j=0;j<i;j++)
		{
			if(v[j].bi<=v[i].ai&&dp[j]+v[i].ci>dp[i])
				dp[i] = dp[j]+v[i].ci;
		}
		if(dp[i]>max_value)
			max_value = dp[i];
	}

	return max_value;
}

int main()
{
	int n;
	cin >> n;
	
	int a, b, c;
	edge temp;
	vector<edge> v;
	while(n-->0&&cin>>a>>b>>c)
	{
		temp.ai = a;
		temp.bi = b;
		temp.ci = c;
		v.push_back(temp);
	}

	cout << MaxValue(v) << endl;

	return 0;
}
