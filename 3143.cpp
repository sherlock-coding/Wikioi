/* ¶ş²æÊ÷µÄĞò±éÀú */
#include <iostream>

using namespace std;

int a[16][2] = {0};

void pretravel(int id)
{
	cout << id << " ";
	if(a[id-1][0]!=0)
		pretravel(a[id-1][0]);
	if(a[id-1][1]!=0)
		pretravel(a[id-1][1]);
}

void midtravel(int id)
{
	if(a[id-1][0]!=0)
		midtravel(a[id-1][0]);
	cout << id << " ";
	if(a[id-1][1]!=0)
		midtravel(a[id-1][1]);
}

void nexttravel(int id)
{
	if(a[id-1][0]!=0)
		nexttravel(a[id-1][0]);
	if(a[id-1][1]!=0)
		nexttravel(a[id-1][1]);
	cout << id << " ";
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	
	pretravel(1);
	cout << endl;
	midtravel(1);
	cout << endl;
	nexttravel(1);
	cout << endl;

	return 0;
}
