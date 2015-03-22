/* 
 * File:   main.cpp
 * Author: smss
 *
 * Created on April 19, 2014, 3:00 AM
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;


int main()
{
//#define ONLINE_JUDGE
//#ifndef ONLINE_JUDGE
//    ifstream fs;
//    fs.open("/home/smss/ACM/11340/dist/Debug/GNU-Linux-x86/i.in");
//#define cin fs
//#endif
	int n = 0;
	cin>>n;
	while(n-->0)
	{
		int   numberOfPaidChar=0;
		cin>> numberOfPaidChar;
		typedef map<char,int> mapT;
		mapT paidMap;
		while(numberOfPaidChar-->0)
		{
			char tmp;
			cin>>tmp;
			int paid;
			cin>>paid;
			paidMap.insert(make_pair(tmp, paid));
		}

		int   numberOflines=0;
		cin>> numberOflines;
		int paidAll=0;
		while(numberOflines-->0)
		{
			string line;
			while(getline(cin, line) && line.empty());
			for(string::iterator i = line.begin();
				i != line.end();
				i++){
                            mapT::iterator f = paidMap.find(*i);
                            if( f != paidMap.end())
                                paidAll+=f->second;
			}
		}
                double out = paidAll/100.0;
		printf("%.2f$\n", out);
	}
	return 0;
}