#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define var double
var F(var a)
{
	if( a == 1 )
		return 1;
	return a * F(a-1);
}

var C(var n, var r)
{
	return F(n) / (F(r) * F(n-r) );
}
var Ca(var n)
{
	return C(2*n,n)/(n+1);
}
int main()
{
	int n=31;
	vector<var> a(31,0);
	while(--n>0)
		a[n] = Ca(n);
	//a[30] = 3814986502092304;
	while(cin>>n,n)
	{
//		printf("%e\n"  , a[n]);
		printf("%.0f\n", a[n]);
//		printf("%e | %.0f <br>\n", a[n], a[n] );
//		cout<<a[n]<<"<br>"<<endl;
	}
	return 0;
}
