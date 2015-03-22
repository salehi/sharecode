#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,i,t,a,s,m,set=0;
	vector<int> v;
	while( cin>>n && n!=0)
	{
		s=0; m=0; t=0; a=0; i=0;
		v.clear();
		for( i = 0; i<n; i++ )
		{
			cin>>t;
			v.push_back(t);
			s+=t;
		}
		a = s / i;
		for( i = 0; i<n; i++ )
		{
			if( v[i] - a > 0 )
			{
				m += (v[i] - a);
			}
		}
		cout<<"Set #"<<++set<<endl;
		cout<<"The minimum number of moves is "<<m<<"."<<endl<<endl;
	}
	return 0;
}
