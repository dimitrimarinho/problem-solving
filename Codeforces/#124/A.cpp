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

int segt[1<<18];
string s;

void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = lo;
	} else {
		int ls = (node<<1) + 1;
		int rs = ls + 1;
		int mid = (lo+hi)>>1;
		
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		
		if( s[ segt[rs] ] > s[ segt[ls] ] )
			segt[node] = segt[rs];
		else segt[node] = segt[ls];
	}
}

int from, to;
int qry( int node, int lo, int hi ){
	if( from <= lo && hi <= to ) return segt[node];
	
	int ls = (node<<1) + 1;
	int rs = ls + 1;
	int mid = (lo+hi)>>1;
	
	if( mid+1 > to ) return qry( ls, lo, mid );
	if( mid < from ) return qry( rs, mid+1, hi );
	
	int a = qry( ls, lo, mid );
	int b = qry( rs, mid+1, hi );
	
	if( s[ b ] > s[ a ] ) return b;
	return a;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> s;
	
	from = 0, to = SIZE(s)-1;
	build(0,0,to);
	
	while( from <= to ){
		int now = qry( 0, 0, to );
		cout << s[ now ];
		from = now+1;
	}
	cout << "\n";
	
	return 0;
}








