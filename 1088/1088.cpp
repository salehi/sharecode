#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,s,i=0; cin>>n;
	while( n-->0 )
	{
		string str;
		cin>>str;
		cout<<"String #"<<++i<<endl;
		for(s=0; s<str.size(); s++ )
		{
			if( char(str[s]) == 'Z' )
				cout<<char(str[s]-25);				
			else
				cout<<char(str[s]+1);				
		}
		cout<<"\n\n";
	}
}
