#include <iostream>
int main(){
	int a,i;
	while(std::cin>>a&&a!=0){
		for(i=1;a!=1;i++)
			if(a%2==0)
				a/=2;
			else
				a=a*3+1;
		std::cout<<i<<"\n";}
}
