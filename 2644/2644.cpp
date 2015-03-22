#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
#define ins insert
#define mp make_pair
#define hm map<char,char>
#define FOR(i,n) for(int (i) = 0; i<n; i++)
hm m;hm::iterator it;
void r(string& s)
{
	reverse(s.begin(), s.end());
}
void sh(string str)
{
	int n = str.size()/2;
	FOR(i,n)
	{
		int f = i+n, s = i;
		m.ins( mp(str[f], str[s]) );
		m.ins( mp(char(str[f]-32), char(str[s]-32)) );
	}
}
int main()
{
	string l,v="aiyeou",c="bkxznhdcwgpvjqtsrlmf";
	sh(v); r(v); sh(v);
	sh(c); r(c); sh(c);
	while(getline(cin,l))
	{
		FOR(i,l.size())
		{
			it = m.find( l[i] );
			if( it != m.end() )
			{
				cout<<it->second;
			}
			else
				cout<< l[i];
		}
		cout<<endl;
	}
}
