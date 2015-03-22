#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <ctype.h>
#include <cstring>
using namespace std;
string line,host,port,path;
void def()
{
	host = "defult";
	port = "defult";
	path = "defult";
}
int main()
{
	char pro;
	int n,set=1;
	getline(cin,line);
	sscanf(line.c_str(),"%d",&n);
	while(n-->0)
	{
		def();
		getline(cin,line);
		cout<<"URL #"<<set++<<endl;
		if( line.size() > 1 )
		{
			size_t prot = line.find("://");
			def();
			if( prot != string::npos )
			{
				port = line.substr(0,prot);				
				line = line.substr(prot+3);
			}
			cout<<"Protocol = "<<port<<endl;
		}
		if( line.size() > 1 )
		{
			def();
			size_t slash = line.find("/");
			size_t colon = line.find(":");
			if( slash == string::npos && colon == string::npos)
			{
				cout<<"Host     = "<<line<<endl
					<<"Port     = "<<port<<endl
					<<"Path     = "<<path<<endl;
			}
			if( slash != string::npos && colon == string::npos  )
			{
				host = line.substr(0,slash);
				path = line.substr(slash+1);
				cout<<"Host     = "<<host<<endl
					<<"Port     = "<<port<<endl
					<<"Path     = "<<path<<endl;
			}
			if( slash != string::npos && colon != string::npos)
			{
				def();
				path = line.substr(slash+1);
				line.erase(slash);
				port = line.substr(colon+1);
				line.erase(colon);
				cout<<"Host     = "<<line<<endl
					<<"Port     = "<<port<<endl
					<<"Path     = "<<path<<endl;
			}
			if( slash == string::npos && colon != string::npos )
			{
				def();
				port = line.substr(colon+1);
				line.erase(colon);
				cout<<"Host     = "<<line<<endl
					<<"Port     = "<<port<<endl
					<<"Path     = "<<path<<endl;
			}
		}
		if(n!=0) cout<<endl;
	}
	return 0;
}
