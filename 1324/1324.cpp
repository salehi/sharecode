#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a,f;
	int n,set=1;
	getline(cin,a);
	while(a!="STOP")
	{
		cin>>n;
		cout<<"Dataset #"<<set++<<":  The initial order is "<<a<<"."<<endl;
		while(n-->0)
		{
			cin>>f;
			size_t s= a.find(f);
			a.erase(s,f.size());
			cout<<"After "<<f<<" leaves, the order is "<<a<<"."<<endl;
		}
		cin>>a;
		if( a == "STOP" )
			break;
		cout<<endl;
	}
	return 0;
}
