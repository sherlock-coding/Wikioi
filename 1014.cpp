/*
作者:slycarl@163.com
题目:p1014 装箱问题
*/

// c[i][j]表示前i个物品放入容量为j的箱子中,最小的箱子剩余空间
// c[i][j] = min(c[i-1][j],c[i-1][j-vi]) if j-vi>=0

#include <iostream>
#include <vector>

using namespace std;

int c[31][20001];

int MinRestVolumn(vector<int> volumn, int v)
{
	int n = volumn.size();
	int c[n+1][v+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=v;j++)
		{
			if(j==0)
				c[i][j] = 0;
			else if(i==0)
				c[i][j] = j;
			else
			{
				// 当物品体积大于当前箱子容量，则不考虑放入物品的情况
				if(j-volumn[i-1]<0 || c[i-1][j]<c[i-1][j-volumn[i-1]])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i-1][j-volumn[i-1]];
			}
		}

	return c[n][v]; 
}

int main()
{
	int v,n,i=0,temp;
	cin >> v >> n;

	vector<int> volumn;
	while(i++<n&&cin>>temp)
	{
		volumn.push_back(temp);
	}

	cout << MinRestVolumn(volumn,v);
	
	return 0;
}
