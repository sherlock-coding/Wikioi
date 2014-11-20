/* 明明的随机数  */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,tmp;
	int m[1000] = {0};
	cin>>n;

	vector<int> a;

	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		if(m[tmp-1]==0)
		{
			m[tmp-1]++;
			a.push_back(tmp);
		}
	}

	sort(a.begin(),a.end());

	cout << a.size() << endl;
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout<<endl;

	return 0;
}
