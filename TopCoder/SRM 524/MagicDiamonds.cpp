// Paste me into the FileEdit configuration dialog

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
#include <bitset>

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

#define MXXX 1000000

bitset< MXXX+10 > bs;
vector< int64 > primes;

void sieve(){
	primes.clear();
	REP( i, MXXX+1 ) bs[i] = (i&1);
	bs[1] = false;
	bs[2] = true;
	
	for( int i = 3; i <= 1000; i+=2 ) if( bs[i] ){
		for( int j = i*i; j <= MXXX; j+=i ) bs[j] = false;
	}
	REP( i, MXXX+1 ) if( bs[i] ) primes.PB( i );
}

bool isPrime( int64 N ){
	if( N <= MXXX ) return bs.test( N );
	REP( i, SIZE(primes) ) if( N % primes[i] == 0 ) return false;
	return true;
}

class MagicDiamonds {
public:
   long long minimalTransfer( long long n ) {
	sieve();
	if( isPrime(n) ) return 2+(n==3);
	return 1;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			long long n               = 2;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 4294967297LL;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 2147483647;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			long long n               = 1000000000000;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
     case 5: {
			long long n               = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 6: {
			long long n               = 999999999989;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
