#include <iostream>
#include <sstream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int b,c;
	string l,w;
	cin>>b;
	while( b -- > 0 )
	{
		cin>>c;
		while( c -- > -1 )
		{
			getline( cin, l );
			stringstream input( l );
			size_t size = 0;
			while(getline( input, w, ' ' ))
			{
				reverse( w.begin(), w.end() );
				cout<<w;
				size += w.size() ;
				if( size+1 <= input.str().size() )
				{
					cout<<" ";
					size++;
				}
				
			}
			if( l.size() != 0 )
				cout<<endl;	
		}		
		if( b != 0 )
			cout<<endl;
	}
}
