#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t,N,i;
	cin>>t;
	while(t-->0)
	{
		cin>>N;
		i=0;
		while( i++ < N )
		{
			string s;
			getline(cin,s);
		}
		cout<<"1 "<<N-1<<endl;
	}
}
