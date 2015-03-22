#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
vector<string> all;
int count = 0;
int match = 0;
bool shiftLd()
{
	count++;
	for(int i=0;i<all.size();i++)
	{
		if( all[i].size() == 1 )
			return false;
		string cp = "";
		for(int J = 1; J < all[i].size(); J++ )
			cp += all[i][J];
		all[i] = cp;
	}
	return true;
}
bool haveMatch()
{
	match++;
	for(int i=0;i<all.size();i++)
	{
		for(int j=i+1;j<all.size();j++)
		{
			if(all[i].compare(all[j]) == 0)
				return true;
		}
	}
	return false;
}

int main()
{
	int N=0; 
	while( cin>>N, N )
	{
		all.clear();
		match = 0;
		count = 0;
		for(int i = 0; i < N; i++ )
		{
			string tmp;
			cin>>tmp;
			all.push_back(tmp);
		}
		internal:
		if(!shiftLd())
		{
			printf("%d\n", --count );
			continue;
		}
		if(haveMatch())
		{
			printf("%d\n", --match);
			continue;
		}
		goto internal;
	}
	return 0;
}
