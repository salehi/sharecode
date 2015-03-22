#include <iostream>
int main()
{
	int n;
	while( std::cin>>n )
		std::cout<<int(n*(n+2)*(2*n+1) /8 )<<"\n";
}
