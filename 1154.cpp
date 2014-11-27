/*
����:slycarl@163.com
��Ŀ:p1154 ��������
*/

//dp[i][j]��ʾ������i��j�ۺϲ������������
//bdp[i][j]��ʾ������i��j�ۺϲ������µ�����
//dp[i][j] = max{dp[i][k]+dp[k+1][j]+bdp[i][k].begin*bdp[i][k].end*bdp[(k)%n+1][j].end]} k =��i��j-1��,ע��k������n��k+1 = (k)%n+1

#include <iostream>
#include <vector>

using namespace std;

typedef struct{
	int begin;
	int end;
} Ball;

int MaxEnery(vector<Ball> balls)
{
	int n = balls.size();
	int dp[n+1][n+1];
	Ball bdp[n+1][n+1];

	int i, j, k, len, maxenery, kn;
	Ball tmp;

	for(len=1;len<=n;len++)
	{
		for(i=1;i<=n;i++)
		{
			j = (i+len-1-1)%n+1;
			if(i==j)
			{
				dp[i][j] = 0;
				bdp[i][j] = balls[i-1];
			}
			else
			{
				maxenery = 0;
				k = i;
				if(i<j)
					kn = j-i;
				else
					kn = j+n-i;
				while(kn-->0)
				{
					if(dp[i][k]+dp[(k)%n+1][j]+bdp[i][k].begin*bdp[i][k].end*bdp[(k)%n+1][j].end > maxenery)
					{
						maxenery = dp[i][k]+dp[(k)%n+1][j]+bdp[i][k].begin*bdp[i][k].end*bdp[(k)%n+1][j].end;
						tmp.begin = bdp[i][k].begin;
						tmp.end = bdp[(k)%n+1][j].end;
					}
					k = (k)%n+1;
				}
				dp[i][j] = maxenery;
				bdp[i][j] = tmp;
			}
		}
	}
	maxenery = 0;
	for(i=1;i<=n;i++)
	{
		if(dp[i][(n-2+i)%n+1]>maxenery)
			maxenery = dp[i][(n-2+i)%n+1];
	}

	return maxenery;
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	int tmp,i=0;
	while(i<n&&cin>>tmp)
		arr[i++] = tmp;

	vector<Ball> balls;
	i = 0;
	while(i<n)
	{
		Ball b;
		b.begin = arr[i++];
		b.end = arr[i%n];
		balls.push_back(b);
	}

	cout << MaxEnery(balls) << endl;

	return 0;
}
