/* 汉诺塔游戏 */
#include <iostream>
#include <string>

using namespace std;

struct step
{
	int no;
	char from;
	char to;
};

int count = 0;
step s[1024];

void move(int n,char a,char b ,char c ) // 将a上的1-n圆盘借助b移动到c
{
	if(n>1)
		move(n-1,a,c,b);
	s[count].no = n;
	s[count].from = a;
	s[count].to = c;
	count++;
	if(n>1)
		move(n-1,b,a,c);
}

int main()
{
	int n;
	cin >> n;

	move(n,'A','B','C');

	cout << count << endl;
	for(int i=0;i<count;i++)
	{
		cout << s[i].no << " from " << s[i].from << " to " << s[i].to << endl;
	}

	return 0;
}
