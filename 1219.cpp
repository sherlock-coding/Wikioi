/*
����:slycarl@163.com
��Ŀ:p1219 ��ʿ����
*/


//��̬�滮
//dp[i][j]��ʾ����㵽��i��j����·����


#include <iostream>

using namespace std;

/* //�������̫��
int n,m;
int xd,yd;
int routes = 0;

void ReachDst(int x, int y) //��x,y����ʾ��ǰ��λ��
{
	if(x==xd&&y==yd)
		++routes;
	else 
	{
		if(x>=xd)
			return;
		// �ߺ���
		if(x+2<=m&&y+1<=n)
			ReachDst(x+2, y+1);
		if(x+2<=m&&y>=0)
			ReachDst(x+2, y-1);
		//������
		if(x+1<=m&&y+2<=n)
			ReachDst(x+1, y+2);
		if(x+1<=m&&y-2>=1)
			ReachDst(x+1, y-2);
	}
}
*/

long long dp[100][100];
int n, m;
int xd,yd;

void GetRoutes(int x , int y)
{
	dp[x][y] = 1;

	long long cnt;

	for(int i=x+1;i<=xd;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt = 0;
			if(j+2<=n)
				cnt += dp[i-1][j+2];
			if(j-2>=1)
				cnt += dp[i-1][j-2];
			if(j+1<=n)
				cnt += dp[i-2][j+1];
			if(j-1>=1)
				cnt += dp[i-2][j-1];
			dp[i][j] = cnt;
		}
	}

}

int main()
{
	cin >> n >> m;

	int x1,y1;
	cin >> x1 >> y1 >> xd >> yd;

	GetRoutes(x1, y1);
	cout << dp[xd][yd] << endl;

	return 0;

}

