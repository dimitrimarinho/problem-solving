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

class RoadOrFlightHard {
public:
   long long minTime( int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K ) {
		int64 rdTm[N];
		int64 flTm[N];
		rdTm[0] = roadFirst % roadMod;
		flTm[0] = flightFirst % flightMod;
		FOR( i, 1, N-1 ){
			rdTm[i] = (rdTm[i-1]*roadProd)%roadMod + roadAdd;
			rdTm[i] %= roadMod;
			
			flTm[i] = (flTm[i-1]*flightProd)%flightMod + flightAdd;
			flTm[i] %= flightMod;
		}
		int64 dp[2][K+1][2];
		REP( i, K+1 ) dp[0][i][0] = 0, dp[0][i][1] = LINF;
		int old = 0, cur = 1;
		
		REP( i, N ){
			REP( j, K+1 ){
					
					dp[cur][j][0] = MIN( dp[old][j][0], dp[old][j][1] )+rdTm[i];
					
					dp[cur][j][1] = dp[old][j][1]+flTm[i];
					if( j ) dp[cur][j][1] = MIN( dp[cur][j][1], dp[old][j-1][0]+flTm[i] );
				
			}
			old = !old;
			cur = !cur;
		}
		
		return MIN( dp[old][K][0], dp[old][K][1] );
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
			int N                     = 3;
			int roadFirst             = 14;
			int roadProd              = 1;
			int roadAdd               = 2;
			int roadMod               = 10;
			int flightFirst           = 18;
			int flightProd            = 1;
			int flightAdd             = 10;
			int flightMod             = 17;
			int K                     = 1;
			long long expected__      = 14;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int roadFirst             = 4;
			int roadProd              = 1;
			int roadAdd               = 2;
			int roadMod               = 10;
			int flightFirst           = 1;
			int flightProd            = 1;
			int flightAdd             = 10;
			int flightMod             = 17;
			int K                     = 2;
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int roadFirst             = 4;
			int roadProd              = 1;
			int roadAdd               = 2;
			int roadMod               = 10;
			int flightFirst           = 1;
			int flightProd            = 1;
			int flightAdd             = 6;
			int flightMod             = 9;
			int K                     = 1;
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int roadFirst             = 85739;
			int roadProd              = 94847;
			int roadAdd               = 93893;
			int roadMod               = 98392;
			int flightFirst           = 92840;
			int flightProd            = 93802;
			int flightAdd             = 93830;
			int flightMod             = 92790;
			int K                     = 3;
			long long expected__      = 122365;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int roadFirst             = ;
			int roadProd              = ;
			int roadAdd               = ;
			int roadMod               = ;
			int flightFirst           = ;
			int flightProd            = ;
			int flightAdd             = ;
			int flightMod             = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int roadFirst             = ;
			int roadProd              = ;
			int roadAdd               = ;
			int roadMod               = ;
			int flightFirst           = ;
			int flightProd            = ;
			int flightAdd             = ;
			int flightMod             = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int roadFirst             = ;
			int roadProd              = ;
			int roadAdd               = ;
			int roadMod               = ;
			int flightFirst           = ;
			int flightProd            = ;
			int flightAdd             = ;
			int flightMod             = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RoadOrFlightHard().minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
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