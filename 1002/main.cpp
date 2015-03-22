#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
//#include <cmath>
#define double long double
#define PI 3.141592654
#define pie pair<int, int>
#define pid pair<double, double>
#define pb push_back
#define mp make_pair
using namespace std;

double x,y,N,t1,t2,r;

double abs( double& a )
{
	if( a >= 0.0 )
	{
//		cout<<"\n\tA = "<<a<<" >= 0 ";
		return a;
	}
//	cout<<"\n\tA = "<<a<<" < 0 ";
	return -a;
}

double Rad2Deg( double R )
{
	return 180 * R * PI;//pi * daraje = 180 * radian -> daraje = 180 * radian / pi
}

double Deg2Rad( double D )
{
	return PI * D / 180;// pi * daraje = 180 * radian -> radian = pi * daraje / 180
}

double hypot( double a1, double a2 )
{
	return sqrt( a1*a1 + a2*a2 );
}

double dis2cen( double a1, double a2 )
{
	double delx = a1-x;
	double dely = a2-y;
	return hypot( delx, dely );
}

std::pair<double, double> cartesian_to_polar(double a1, double a2)
{
	double delx = a1-x; delx = abs(delx); 
	double dely = a2-y; dely = abs(dely);
	double r = hypot(delx, dely);
	if( delx == 0.0 ) delx = r/10;
	double t = asin( dely / r );
	if( a1 >= x )
	{
		if( a2 >= y )
		{
		}
		else if( a2 <= y )
		{
			t += 2*PI/3;
		}
	}
	else if( a1 <= x )
	{
		if( a2 >= y )
		{
			t += PI/2;
		}
		else if( a2 <= y )
		{
			t += PI;
		}
	}
	while( t < 0.0 ) t+= 2*PI;
	while( t >= 2*PI ) t -= 2*PI;
//	t = Rad2Deg(t);
	cout<<"ANGLE:\t"<<t<<endl;
	return make_pair(r,t);
}

class ComparePolar
{
public:
	bool operator()(pid a1, pid a2)
	{
		return a1.second < a2.second;
	}
};

int main()
{
	cout<<"PI/2 = "<<PI/2<<"\tPI = "<<PI<<"\t2PI/3 = "<<2*PI/3<<"\t2PI = "<<2*PI<<"\tPI^ln(PI) = "<<pow(PI,log(PI))<<endl;
	ios_base::sync_with_stdio(false);
	cout.sync_with_stdio(false);
	while( cin>>x>>y>>r && r>=0 )
	{
		cin>>N;
		vector< pie > points_cartesian;
		vector< pid > points_polar;
		vector< double > degrees;
		while(N-->0)
		{
			cin>>t1>>t2;
			if( dis2cen( t1, t2 ) <= r )
			{
				points_cartesian.pb(mp(t1,t2));
				points_polar.pb( cartesian_to_polar(t1,t2) );
			}
		}
		sort(points_polar.begin(), points_polar.end(), ComparePolar());
		/*for(int i = 0; i < points_polar.size(); i++ )
		{
			cout<<"\t"<<points_polar[i].second<<endl;
		}*/
		int Max=0, C=0;
		double angle,tmp=0;
		for( int i = 0 ; i<= points_polar.size(); i++ )
		{
			C=0;
			tmp = points_polar[i].second;
			for( int idx = 0; idx < points_polar.size(); idx ++ )
			{
				angle = points_polar[idx].second;
				if( angle >=tmp && angle <= tmp + PI )
					C++;
			}
			if( C>Max )
				Max = C;
		}
		cout<<Max<<endl;
	}
	return 0;
}
