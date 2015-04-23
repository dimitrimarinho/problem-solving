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

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int K, R;
	K = next_int();
	R = next_int();  R = SQR(R);
	
	int M = next_int();
	int x[M], y[M];
	REP( i, M ){
		x[i] = next_int();
		y[i] = next_int();
	}
	
	int N = next_int();
	int xx[N], yy[N], s[N], reach[N];
	REP( i, N ){
		xx[i] = next_int();
		yy[i] = next_int();
		s[i] = next_int();
		reach[i] = 0;
	} 
	
	REP( i, M ) REP( j, N )
		if( SQR(x[i]-xx[j])+SQR(y[i]-yy[j]) <= R )
			reach[j] |= (1<<i);
	
	int ans = 0;
	REP( mask, 1<<M ){
		if( __builtin_popcount(mask) == K ){			
			int cur = 0;
			REP( i, N ) if( reach[i] & mask ) cur += s[i];
			ans = max( ans, cur );
		}
	}
	printf("%d\n", ans );
	
	return 0;
}

























