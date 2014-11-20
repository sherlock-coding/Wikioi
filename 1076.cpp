/* ≈≈–Ú */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,tmp;
	cin >> n;

	vector<int> v;

	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<n;i++)
	{
		cout << v[i]<<" ";
	}
	cout << endl;

	return 0;
}
