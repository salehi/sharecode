#include <iostream>
using namespace std;
int main()
{
	int n,m,c,k,a,b;
	cin>>k;
	while(k-->0)
	{
		int s=1;
		while(cin>>n>>m)
		{
			if(n==0&&m==0) 
				break; 
			c=0;
			for( a = 1; a<n-1; a++ )
				for( b = a+1; b<n; b++ )
					if(int(a*a+b*b+m)%(a*b)==0)
						c++;
			cout<<"Case "<<s++<<": "<<c<<endl;
		}
		if( k != 0 )
			cout<<endl;
	}
}
