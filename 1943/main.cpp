#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,N,c,I,J;
	cin>>N;
	while(N-->0)
	{
		cin>>t;
		string cor,ton;
		getline( cin, cor );
		getline( cin, ton );
		I = J = c = 0;
		while( I++ < cor.size() && J++ < ton.size() )
			if(strcmp( &cor[I], &ton[J] ) )
				c++;
		cout<<c<<endl;
		cout<<ton.size()<<endl;
		cout<< (ton.size()- ++c) * 2 * t <<endl;
	}	
	return 0;
}
