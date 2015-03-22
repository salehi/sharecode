#include <iostream>
#include <map>
#include <string.h>
#include <sstream>
using namespace std;
int main()
{
	string p,s,l;
	map<char,char> h;
	stringstream ou;
    cin>>p>>s;
    for(int i=0;i<p.size();i++)
		h.insert(make_pair(p[i],s[i]));
    ou<<s<<endl<<p;
    while(getline(cin,l))
    {
    	for(int i=0; i < l.size(); i++ )
	        if( h.find(l[i]) == h.end() )
    	        ou<<l[i];
        	else
            	ou<<h.find(l[i])->second;
    	ou<<endl;
    }
    cout<<ou.str();
    return 0;
}
