#include <iostream>
#include <math.h>
#define forn(i,n) for( int (i) = 0; i < n; i++ )
using namespace std;

struct point
{
	int x,y;
	point(){x=0;y=0;}
};

istream& operator>>(istream& input, point& ob)
{
	input>>ob.x>>ob.y;
	return input;
}

ostream& operator<<(ostream& output, point& ob)
{
	output<<ob.x<<" "<<ob.y;
	return output;
}

/*istream& operator>>(istream& input, Rect& ob)
{
	input>>ob.upl>>ob.lor;
	return input;
}*/
/*
ostream& operator<<( ostream& output , Rect& ob)
{
	//output<<ob.upl; output<<" "; output<<ob.lor; output<<endl;
	//return output;
}/**/

struct Mouse
{
	point O;
	Mouse(){};
	Mouse(point p)
	{
		O = p;
	}
};


struct Rect
{
	point upl,lor;//upper_left & lower_right corners
	int depth;
	Rect(){}
	Rect(point a, point b, int dep)
	{
		upl = a;
		lor = b;
		depth = dep;
	}
	bool iscontain( Mouse mos )
	{
		// first if according to problem description
		if( mos.O.x >= this->upl.x and
			mos.O.x <= this->lor.x and
			mos.O.y <= this->upl.y and
			mos.O.y >= this->lor.y )
		{
			return true;
		}/**/
		// second if according to the input and output example
		/*if( mos.O.x >= this->upl.x and
			mos.O.x <= this->lor.x and
			mos.O.y >= this->upl.y and
			mos.O.y <= this->lor.y )
		{
			return true;
		}/**/
		return false;
	}
	
};

/*istream& operator>>(istream& input, Rect& ob)
{
	input>>ob.upl>>ob.lor;
	return input;
}/**/

ostream& operator<<( ostream& output , Rect& ob)
{
	output<<ob.upl<<" "<<ob.lor<<endl;
	return output;
}

int main()
{
	//Windows and depth input
	int N,level = 0;
	point upl,lor;
	cin>>N;
	Rect array[N];
	forn(i,N)
	{
		cin>>upl>>lor;
		array[i] = Rect( upl, lor, level++ );
	}
	//Mouse Clicks input
	int M;
	cin>>M;
	Mouse array2[M];
	point clk;
	forn(i,M)
	{
		cin>>clk;
		array2[i] = Mouse(clk);
	}
	//Mouse Clicks search
	forn(I, M)
	{
		bool depthwrote = false;
		forn(J, N)
		{
			if( array[J].iscontain( array2[I] ) )
			{
				cout<<array[J].depth<<endl;
				depthwrote = true;
			}
		}
		if( depthwrote == false )
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
