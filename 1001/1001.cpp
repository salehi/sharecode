#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

double PI() { return 3.14159; }

double Rad2Deg( double radian )
{
	return 180*radian / PI();
}

bool GetAlpha( pair<int, int> v1, pair<int, int> v2, pair<int, int> O )
{
	//Asume that v1(a,b) and v2(c,d) -> v1.v2 = a*c + b*d
	double a = v1.first - O.first;
	double b = v1.second - O.second;
	double c = v2.first - O.first;
	double d = v2.second - O.second;
	double aDOTb = ( a*c + b*d);
	double absV1 = sqrt( pow(a,2) + pow(b,2) );
	double absV2 = sqrt( pow(c,2) + pow(d,2) );
	double cos_theta =  aDOTb/ (absV1 + absV2);
	return acos(cos_theta) - PI() <= 0;
}

double GetDistance( pair<int, int> a, pair<int, int> b)
{
	double delta_x = a.first - b.first;
	double delta_y = a.second - b.second;
	return sqrt( pow(delta_x,2) + pow(delta_y,2) );
}



int main()
{
	int x_b, y_b, x,y, n = 0, compare_max = 0, max = 0;
	double r = 0;
	while(1)
	{
		cin>>x_b>>y_b>>r;
		if( r < 0 )
			break;
		cin>>n;
		pair<int, int> O = make_pair( x_b, y_b );
		max = 0, compare_max = 0;
		vector< pair<int, int> > points;
		for( int i = 0; i<n; i++ )
		{
			cin>>x>>y;
			if( GetDistance(O, make_pair(x,y) ) -r <= 0.0 )
				points.push_back(make_pair( x, y ));
		}
		vector< pair<int, int> >::const_iterator endp = points.end();
		for( vector< pair<int, int> >::iterator it = points.begin();
			it != endp;
			it++ )
		{	
			for( vector< pair<int, int> >::iterator it2 = points.begin();
				it2 != endp;
				it2++ )
			{
				if( GetAlpha( *it, *it2, O ) )
					compare_max ++;
			}
			if( compare_max - max > 0 )
				max = compare_max;
			compare_max = 0;			
		}
		cout<<max<<endl;
	}
	return 0;
}
