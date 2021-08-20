#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,pairs=0;
	vector < int > v;
	v.assign(26,0);

	cin>>n;
	string temp;

	for(int i=1;i<=n;i++)
	{
		cin >> temp;
		v[temp[0]-97]++;
	}
	
	for(int i=0;i<=25;i++)
	{
		int d=v[i]/2;
		pairs+=(d*(d-1)/2+(v[i]-d)*(v[i]-d-1)/2);
	}
	
	cout << pairs << endl;
	return 0;
}
