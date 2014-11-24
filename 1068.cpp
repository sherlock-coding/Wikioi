/*
����:slycarl@163.com
��Ŀ:p1068 �ڹ���
*/

// f[a][b][c][d] ��ʾ�ӵ�һ����ʼʹ�����ֿ�Ƭ��a,b,c,d�����õ��ķ���
// f[a][b][c][d] = max{f[a-1][b][c][d]+chest,f[a][b-1][c][d]+chest,f[a][b][c-1][d]+chest,f[a][b][c][d-1]+chest}

#include <iostream>
#include <vector>

using namespace std;

int f[41][41][41][41];

int MaxOfFour(int a, int b, int c, int d)
{
	int m = a;
	if(b>m)
		m = b;
	if(c>m)
		m = c;
	if(d>m)
		m = d;

	return m;
}

void MaxScore(vector<int> chest, vector<int> card)
{
	int a,b,c,d,pos;

	for(int i=0;i<=card[0];i++)
		for(int j=0;j<=card[1];j++)
			for(int k=0;k<=card[2];k++)
				for(int l=0;l<=card[3];l++)
				{
					if(!i && !j && !k && !l)
						f[i][j][k][l] = chest[0];
					else 
					{
						pos = i+j*2+k*3+l*4;
						a = 0;
						b = 0;
						c = 0;
						d = 0;
						if(i-1>=0)
						{
							a = f[i-1][j][k][l] + chest[pos];
						}
						if(j-1>=0)
						{
							b = f[i][j-1][k][l] + chest[pos];
						}
						if(k-1>=0)
						{
							c = f[i][j][k-1][l] + chest[pos];
						}
						if(l-1>=0)
						{
							d = f[i][j][k][l-1] + chest[pos];
						}
						
						f[i][j][k][l] = MaxOfFour(a,b,c,d);
					}
						
				}

}

int main()
{
	int n,m,i,temp;
	cin >> n >> m;

	i = 0;
	vector<int> chest;
	while(i++<n&&cin>>temp)
		chest.push_back(temp);
	
	i = 0;
	vector<int> card(4,0);
	while(i++<m&&cin>>temp)
		card[temp-1]++;

	MaxScore(chest,card);

	cout << f[card[0]][card[1]][card[2]][card[3]] << endl;
	
	return 0;
}
