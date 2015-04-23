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

#define MAXN 100100

string S;
int N, SA[MAXN], LCP[MAXN], rank[MAXN], bucket[CHAR_MAX-CHAR_MIN+1];
char bh[MAXN+1];

void buildSA(){
	int a, c, d, e, f, h, i, j, x;
	int *cnt = LCP;
	memset( bucket, -1, sizeof(bucket) ); 
	for( i = 0; i < N; i++ ){
		j = S[i] - CHAR_MIN;
		rank[i] = bucket[j];
		bucket[j] = i;
	}
	for( a = c = 0; a <= CHAR_MAX-CHAR_MIN; a++ ){
		for( i = bucket[a]; i != -1; i=j ){
			j = rank[i]; rank[i] = c;
			bh[c++] = (i==bucket[a]);
		}
	}
	bh[N] = 1;
	for( i = 0; i < N; i++ )
		SA[ rank[i] ] = i;
	x = 0;
	for( h = 1; h < N; h *= 2 ){
		for( i = 0; i < N; i++ ){
			if( bh[i] & 1 ){
				x = i;
				cnt[x] = 0;
			}
			rank[ SA[i] ] = x;
		}
		d = N-h; e = rank[d];
		rank[d] = e + cnt[e]++;
		bh[rank[d]] |= 2;
		
		i = 0;
		while( i < N ){
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 ){
					e = rank[d]; rank[d] = e + cnt[e]++; bh[rank[d]] |= 2;
				}
			}
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 && (bh[rank[d]] & 2)){
					for( e = rank[d]+1; bh[e] == 2; e++);
					for( f = rank[d]+1; f < e; f++ ) bh[f] &= 1;
				}
			}
			i = j;
		}
		for( i = 0; i < N; i++ ){
			SA[rank[i]] = i;
			if( bh[i] == 2 ) bh[i] = 3;	
		}
	}
	
}

int bit[MAXN];

int MAXVAL;

const int MOD = 1000000007;

void up( int idx, int inc ){
	if( inc >= MOD ) inc -= MOD;
	while( idx <= MAXVAL ){
		bit[idx] += inc;
		if( bit[idx] >= MOD ) bit[idx] -= MOD;
		idx += (idx & -idx);
	}
}

int get( int idx ){
	int ans = 0;
	while( idx > 0 ){
		ans += bit[idx];
		if( ans >= MOD ) ans -= MOD;
		idx -= (idx & -idx);
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> S ){
		MAXVAL = N = SIZE(S);
		REP( i, MAXVAL+1 ) bit[i] = 0;
		buildSA();
		REP( i, N ) up( N-SA[i], get(N-SA[i]-1)+1 );
		cout << get( N ) << "\n";
	}
		
	return 0;
}

























