/*
����:slycarl@163.com
��Ŀ:p1044 ���ص���
*/

#include <iostream>
#include <vector>

using namespace std;

//��������ݼ�������
int MaxMissile(vector<unsigned int> heights)
{
	int dp[heights.size()]; //��ʾ��h[i]��β�ĵݼ������е������
	
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

// ����������������У���Ϊ�ڵ����������У���һ�����ζ����Ҫһ��ϵͳ��������ŵ���
int MinSys(vector<unsigned int> heights)
{
	int dp[heights.size()]; //��ʾ��h[i]��β�ĵ��������е������
	
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
