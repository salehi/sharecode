#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i,a,n) for(int (i)=a;i<n;i++)
#define DIF(a,b) abs(abs(a)-abs(b))
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n];
		FOR(i,0,n)
			cin>>a[i];
		bool flag = true;
		int s[n-1];
		FOR(i,0,n-1)
			s[i] = DIF(a[i],a[i+1]);
		FOR(i,0,n-2)
		{
			if( DIF( s[i], s[i+1] ) != 1 )
			{
				flag = false;
				break;
			}
		}
		if( flag )
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
}
