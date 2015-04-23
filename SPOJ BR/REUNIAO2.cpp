/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int fw[101][101];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, M, u, v, w;

	cin >> N >> M;
	REP( i, N ){ REP( j, N ) fw[i][j] = INF; fw[i][i] = 0; }
	
	REP( i, M ){
		cin >> u >> v >> w;
		fw[u][v] = MIN( fw[u][v], w );
		fw[v][u] = MIN( fw[v][u], w );
	}
	
	REP( k, N ) REP( i, N ) REP( j, N ) fw[i][j] = MIN( fw[i][j], fw[i][k]+fw[k][j] );
	
	int ans = INF;
	REP( i, N ){
		int cur = 0;
		REP( j, N ) cur = MAX( cur, fw[i][j] );
		ans = MIN( ans, cur );
	}
	cout << ans << "\n";
	
	return 0;
}
