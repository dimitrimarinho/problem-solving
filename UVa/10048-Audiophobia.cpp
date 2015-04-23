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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXC 111
int gr[MAXC][MAXC];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int C, S, Q, u, v, d, tc = 1;
	bool first = true;
	
	while( (cin>>C>>S>>Q) && (C+S+Q) ){
		if( !first ) cout << "\n";
		first = false;
		
		FOR( i, 1, C ) FOR( j, 1, C ) gr[i][j] = INF;
		while( S-- ){
			cin >> u >> v >> d;
			gr[u][v] = MIN( gr[u][v], d );
			gr[v][u] = gr[u][v];
		}
		
		FOR( k, 1, C )
			FOR( i, 1, C )
			FOR( j, 1, C )
				if( gr[i][k] != INF && gr[k][j] != INF )
					gr[i][j] = MIN( gr[i][j], MAX( gr[i][k], gr[k][j] ) );
		
		cout << "Case #" << tc++ << "\n";
		while( Q-- ){
			cin >> u >> v;
			if( gr[u][v] == INF ) cout << "no path\n";
			else cout << gr[u][v] << "\n";
		}
		
	}
	
	return 0;
}




















