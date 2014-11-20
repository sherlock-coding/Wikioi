/* ����������Ⱥ͸߶� */
#include <iostream>

using namespace std;

int node[1000][2]={{0,0}};
int width[1000]={0}; // ÿ��Ŀ��
int maxh = 0;
int maxw = 0;

void dfs(int id, int h) // idΪ����ţ�hΪ������ڲ�
{
	width[h]++;
	if(h>maxh)
		maxh = h;
	if(node[id][0]!=0) 
		dfs(node[id][0],h+1);
	if(node[id][1]!=0)
		dfs(node[id][1],h+1);
}

int main()
{
	int n;
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> node[i][0] >> node[i][1];
	}

	dfs(1,1);

	for(int i=1;i<=maxh;i++)
	{
		if(width[i]>maxw)
			maxw = width[i];
	}

	cout << maxw << " " << maxh << endl;

	return 0;
}
