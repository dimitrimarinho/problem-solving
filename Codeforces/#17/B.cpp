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

#define INF 2e9
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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1001

int n, q[MAXN], dist[MAXN];
vector< int > gr[MAXN];
int cost[MAXN][MAXN];
int parent[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> n;
	
	int root = -1;
	FOR( i, 1, n ){
		cin >> q[i]; gr[i].clear();
		FOR( j, 1, n ) cost[i][j] = INF;
		dist[i] = INF;
		parent[i] = -1;
		if( root == -1 || q[i] > q[root] ) root = i;
	}
	
	int m, u, v, c;
	cin >> m;
	REP( i, m ){
		cin >> u >> v >> c;
		if( cost[u][v] == INF ) gr[u].PB( v );
		cost[u][v] = min( cost[u][v], c );
	}
	
	int ans = 0;
	if( n != 1 ){
		priority_queue< pair<int,int> > q;
		dist[root] = 0;
		q.push( MP(0,root) );
		
		
		while( !q.empty() ){
			
			c = -q.top().first;
			u = q.top().second; q.pop();
		
			if( c > dist[u] ) continue;
			for( size_t i = 0; i < gr[u].size(); i++ ){
				v = gr[u][i];
				if( cost[u][v] < dist[v] ){
					if( parent[v] != -1 )
						ans -= cost[ parent[v] ][ v ];
					ans += cost[u][v];
					parent[v] = u;
					
					dist[v] = cost[u][v];
					q.push( MP(-dist[v], v) );
				}
			}
			
		}
		
		FOR( i, 1, n ) if( i != root && parent[i] == -1 ) ans = -1;
			
	}
	
	cout << ans << "\n";
	
	return 0;
}




















