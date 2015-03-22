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

int main(){
    ios_base::sync_with_stdio(false);
    int t,n,m,r,x,y;
    string name;

    map<int,int> persiamap;
    map<int,int> persiamap2;


    cin>>t;
    while(t--){
            cin>> n >> m;
            while(n--){
                    cin >> name >> r;
                    while(r--){
                            cin>>x>>y;

                            map<int,int>::iterator f2 = persiamap2.find(y);
                            if( f2 != persiamap2.end() )
                                if( x == f2->second )
                                {
//                                    continue;
                                }
                            
                            persiamap. insert(mp(x,y));
//                            persiamap2.insert(mp(x,y));
                            persiamap2.insert(mp(y,x));

                    }
            }

            cout << persiamap.size()<<endl;
    }
    return 0;
}
