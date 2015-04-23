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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while(!isdigit(c)) c = getchar_unlocked();
	while(isdigit(c)){ res = 10*res + (c-'0'); c = getchar_unlocked(); }
	return res;
}

int a[30];

int n, ans, mx;

map< int, int > seen;

void solve(int mask, int lvl){
	
	if( lvl >= ans ) return;
	if( mask == ((1<<n)-1) ){ ans = lvl; return; }
	if( seen.count(mask) && seen[mask] <= lvl ) return;
	seen[mask] = lvl;
	
	REP( i, n ){
		int now = ((mask>>i) & 1);
		int turnon = (1<<i);
		int len = 1;
		FOR( j, i+1, n-1 ){
			len++;
			now += ((mask>>j) & 1);
			turnon |= (1<<j);
			
			if( (2*now >= len) && (now != len) )
				solve(mask | turnon,lvl+1);
			
		}	
	}
	
}

int main( int argc, char* argv[] ){
	
	
	int t = next_int();
	while( t-- ){
		n = next_int();
		
		mx = 0;
		REP( i, n ){
			a[i] = next_int();
			mx = max( mx, a[i] );
		}
		
		int mask = 0;
		REP( i, n ) if( a[i] == mx )
			mask |= (1<<i);
		
		ans = ceil( log2(n) );
		seen.clear();
		solve(mask,0);
		
		printf("%d\n", ans );	
	}
		
	return 0;
}

























