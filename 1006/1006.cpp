#include<iostream>
int main(){
	double sum,c,i;sum = 0,i = 1.00;std::cin>>c;
	while(c != 0.00 ){
		sum += 1/++i;
		if( sum >= c)
		{
			sum = 0.00;
			std::cout<<--i<<" card(s)\n";
			i = 1.00;
			std::cin>>c;
		}
	}
}
