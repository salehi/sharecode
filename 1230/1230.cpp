#include <iostream>
#include <cmath>
#define T unsigned long long int
using namespace std;
T sum(T a)
{
	int n = log10(a) ;
	T s=0;
	for(int i=n;i>=0;i--)
	{
		T power = int(std::pow(10.0, i ));
		T digit = int( a - (a % power)) / power;
        s += digit;
		a %= power;
	}
	return s;
}

int main()
{
	T a=0,r=0;
	while(cin>>a && a != 0)
	{
		r += sum(a);
		while(int(log10(r)+1) != 1)
			r = sum(r);
		cout<<r<<endl;r=0;
	}
	return 0;
}
