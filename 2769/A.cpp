#define DEBUG
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

int main()
{
    int l=1050;
    vector<int> s(l,1);
    for( int i=2 ; i<l ; i++ )
        s[i] = s[i-1] + s[i-2];
    int t,k,f=1;
    cin>>t;
    while(t--){
        cin>>k;
        string line;
        stringstream ans;
        cin.ignore(); 
        std::getline(std::cin ,line);
#ifdef DEBUG
//        cout<<"Line: "<<line<<endl;
#endif
        f=1;
        int base=0;
        while(ans.str().size() < k )
        {
            int i = base+s[f++];
            Sub:
            if( i < line.size() )
            {
                if( line[i-1] == '-' )
                {
                    f=1;
                    base=i;
                    continue;
                }
                ans << line[i-1];
            }
            else
            {
                while( i > (2*line.size()) )
                    i %= (2*line.size());
                if( i > line.size() )
                {
                    int num = base+line.size() - (i%line.size())-1;
                    if ( line [num] == '-' )
                    {
                        f=1;
                        base=num;
                        continue;
                    }
                    ans << line [num];
                }
            }
        }
        printf("%s\n",ans.str().c_str());
            
    }
    return 0;
}
