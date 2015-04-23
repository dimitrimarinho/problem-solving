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
	int res = 0;
	char c = getchar_unlocked();	
	while( !isdigit(c) ) c = getchar_unlocked();
	
	while( isdigit(c) ){
		res = (res * 10) + (c - '0');
		c = getchar_unlocked();
	}
	
	return res;
}


#define MAXN 111

int v[3], N;
char s[MAXN];

inline bool ok( char c ){ return (c=='a'||c=='b'||c=='c'); }
void readS(){
	N = 0;
	s[N] = getchar_unlocked();
	while( !ok(s[N]) ) s[N] = getchar_unlocked();
	while( ok(s[N]) ){ N++; s[N] = getchar_unlocked(); }
}

int calc[3][11][111], calc_now;
int dp[3][11][111];

int solve( int last, int qnty, int pos ){
	if( pos == N ) return 0;
	
	int &ret = dp[last][qnty][pos];
	
	if( calc[last][qnty][pos] == calc_now ) return ret;
	calc[last][qnty][pos] = calc_now;
	
	ret = 0;
	
	int nqnty = 1;
	if( (s[pos]-'a') == last ) nqnty = min( 10, qnty+1 );
	
	ret = max( solve(last,qnty,pos+1), v[s[pos]-'a']*(1<<(nqnty-1)) + solve( s[pos]-'a', nqnty, pos+1 ) );
	return ret;
}

int main( int argc, char* argv[] ){
	
	
	int T = next_int();
	while( T-- ){
	
		v[0] = next_int();
		v[1] = next_int();
		v[2] = next_int();
		readS();
		calc_now++;
		printf("%d\n", solve( 0, 0, 0 ) );
	}
	
	
	return 0;
}

























