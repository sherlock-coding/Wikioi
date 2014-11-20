#include<iostream>
using namespace std;

void execute()
{
	string s;
	if(!(cin>>s))
		return;execute();
	cout<<s<<" ";
}

int main()
{
	execute();
	return 0;
}