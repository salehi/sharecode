#include <iostream>
#include <string.h>

using namespace std;

string mergestr( string s1, string s2 )
{
	string ret;
	for( int i = 0; i < s1.size(); i++ )
	{
		ret += s2[i];
		ret += s1[i];
	}
	return ret;
}

void extractstr(string orig, string &s1, string &s2)
{
	int n = orig.size()/2;
	for( int i = 0; i<n; i++ )
	{
		s1[i] = orig[i];
		s2[i] = orig[i+n];
	}
}

string STR1, STR2, STR, STRC;
int t=0;
void getAll()
{
	cin>>t>>STR1>>STR2>>STR;
}

int main()
{
	int I=1;
	for( getAll(); t!=0 and I<=50; I++ )
	{
		string STRC = mergestr(STR1, STR2);
		if( STR.compare(STRC) == 0 )
		{
			cout<<I<<endl;
			I=0;
			getAll();
		}
		else if( I == 50 )
		{
			cout<<"-1"<<endl;
			I=0;
			getAll();
		}
		else
		{
			extractstr( STRC, STR1, STR2 );
		}
	}
	return 0;
}
