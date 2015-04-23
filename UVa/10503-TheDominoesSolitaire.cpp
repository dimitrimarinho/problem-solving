#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXM 15
int n, m;
int sa, sb, ta, tb;
int a[MAXM], b[MAXM];
int ok;

bool play( int last, int pos ){
	if( pos == n ) return (last == ta);
	
	REP( i, m ) if( ok & (1<<i) ){
		ok ^= (1<<i);
		if( a[i] == last ){ 
			if( play( b[i], pos+1 ) ) return true;
		} else if( b[i] == last ){ 
			if( play( a[i], pos+1 ) ) return true;
		}
		ok |= (1<<i);
	}
	
	return false;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> n;
	while( n ){
		cin >> m;
		cin >> sa >> sb;
		cin >> ta >> tb;
		REP( i, m ) cin >> a[i] >> b[i];
		ok = (1<<m) - 1;
		if( play( sb, 0 ) ) cout << "YES\n";
		else cout << "NO\n";
		cin >> n;
	}
	
	return 0;
}




















