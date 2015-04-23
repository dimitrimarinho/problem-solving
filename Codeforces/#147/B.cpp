#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define PB push_back
#define MP make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}
inline int CMP(double a, double b) {
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[55][55];

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
    int n;
    cin >> n;
    int c[n+1];
    FOR(i,1,n) cin >> c[i];
    
    map< int, pair<int,int> > where;
    FOR(i,1,n) {
        FOR(j,1,c[i]) {
            cin >> a[i][j];
            where[ a[i][j] ] = MP(i,j);
        }
    }
    
    vector< pair< pair<int,int>, pair<int,int> > > ans;
    
    int cur =  1;
    FOR(i,1,n) {
        FOR(j,1,c[i]) {
            if (a[i][j] != cur) {
               ans.PB(MP(MP(i,j), where[cur]));
               
               where[ a[i][j] ] = where[cur];
               a[ where[cur].first ][ where[cur].second ] = a[i][j];
                
            }
            cur++;
        }
    }
    
    
    cout << SIZE(ans) << "\n";
	REP(i,SIZE(ans)) cout << ans[i].first.first << " " << ans[i].first.second 
                    << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
    
	return 0;
}

















