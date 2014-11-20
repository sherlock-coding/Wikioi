/* ÉßÐÎ¾ØÕó */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[100][100],s=0;
	int col = n/2;
	int row = col;
	int index = 1;
	int count = 0;
	int direction = 0;

	a[row][col] = 1;
	int no = 2;
	int tmp;
	while(no<=n*n)
	{
		tmp = index;
		while(tmp>0)
		{
			switch(direction)
			{
			case 0:
				col++;
				break;
			case 1:
				row--;
				break;
			case 2:
				col--;
				break;
			case 3:
				row++;
				break;
			}
			a[row][col] = no;
			no++;
			tmp--;
		}
		direction = (direction+1)%4;
		count++;
		if(count==2)
		{
			count = 0;
			index++;
		}

	}

	int sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j||i+j==n-1)
				sum += a[i][j];
			cout  << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << sum <<endl;
	return 0;
}
