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

class Over9000Rocks {
public:
	int countPossibilities( vector <int> lowerBound, vector <int> upperBound ) {
		
		int N = SIZE(lowerBound);
		
		vector< pair<int,int> > rng;
		
		REP( mask, 1<<N ){
			
			int mn = 0, mx = 0;
			REP( i, N ) if( mask & (1<<i) ){
				mn += lowerBound[i];
				mx += upperBound[i];
			}
			
			mn = max( 9001, mn );
			if( mx >= mn ) rng.PB( MP(mn,mx) );
			
		}
		
		sort( ALL(rng) );
		
		int ans = 0;
		int last = 9000;
		
		REP( i, SIZE(rng) ) {
			
			if( rng[i].first > last ){
				ans += rng[i].second-rng[i].first+1;
				last = rng[i].second;
			} else if( rng[i].second > last ){
				ans += rng[i].second-last;
				last = rng[i].second;
			}

		}
		
		return ans;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int lowerBound[]          = {9000};
			int upperBound[]          = {9001};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int lowerBound[]          = {9000, 1, 10};
			int upperBound[]          = {9000, 2, 20};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int lowerBound[]          = {1001, 2001, 3001, 3001};
			int upperBound[]          = {1003, 2003, 3003, 3003};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int lowerBound[]          = {9000,90000,1,10};
			int upperBound[]          = {9000,90000,3,15};
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int lowerBound[]          = {1,1,1,1,1,1};
			int upperBound[]          = {3,4,5,6,7,8};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
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
