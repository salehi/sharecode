#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define COUT cout<<right<<setw(5)
int main()
{
	int n,i,s;
	cout<<"PERFECTION OUTPUT\n";
	while( cin>>n && n != 0 )
	{
		n = abs(n);
		s = 0;	
		for(i=1; i < n; i++ )
			if( n % i == 0 )
				s += i;
		if( s == n )
			COUT<<n<<"  PERFECT\n";
		if(s>n)
			COUT<<n<<"  ABUNDANT\n";
		if(s<n)
			COUT<<n<<"  DEFICIENT\n";
	}
	cout<<"END OF OUTPUT\n";
}
