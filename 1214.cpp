/*
作者:slycarl@163.com
题目:p1214 线段覆盖
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct 
{
	int begin;
	int end;
} Segment;

Segment L[100];

int cmp(Segment l1, Segment l2)
{
	if(l1.end<l2.end)
		return 1;
	return 0;
}

void change(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int n,tmp,i;
	cin >> n;

	for(i=0;i<n;i++)
	{
		 cin >> L[i].begin >> L[i].end;
		 if(L[i].begin>L[i].end)
		 {
			change(L[i].begin, L[i].end);
		 }
	}

	sort(L,L+n,cmp);
	
	int count = 1;
	int index = 0;

	for(i=1;i<n;i++)
	{
		if(L[index].end<=L[i].begin)
		{
			count++;
			index = i;
		}
	}

	cout << count << endl;

	return 0;
}
