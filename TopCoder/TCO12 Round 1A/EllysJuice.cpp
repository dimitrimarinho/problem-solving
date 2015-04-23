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

class EllysJuice {
public:
	vector <string> getWinners( vector <string> players ) {
		
		sort( ALL(players) );
		set< string > canwin;
		vector< string > ans;
		
		int N = SIZE(players);
		do {
			
			double orange = 1000000.0, apple = 1000000.0;
			map< string, double > drank;
			
			REP( i, N ){
				if( i&1 ){ orange /= 2.0; drank[ players[i] ] += orange; }
				else{ apple /= 2.0; drank[ players[i] ] += apple; }
			}
			
			vector< pair< double, string > > res;
			FORIT( x, drank ) res.PB( MP(x->second,x->first) );
			sort( ALL(res) );
			reverse( ALL(res) );
			
			bool ok = false;
			
			if( SIZE(res) > 1 ){
				if( res[0].first > res[1].first ) ok = true;
			} else ok = true;
				 
			if( ok ){
				if( canwin.insert(res[0].second).second ) ans.PB( res[0].second );
			}
					
		} while( next_permutation(ALL(players)) );
		
		sort( ALL(ans) );
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string players[]          = { "elly", "kriss", "stancho", "elly", "stancho" };
			string expected__[]       = {"elly", "stancho" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string players[]          = {"torb", "elly", "stancho", "kriss"};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string players[]          = {"elly", "elly", "elly", "elly", "elly"};
			string expected__[]       = {"elly" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string players[]          = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
			string expected__[]       = {"ariadne", "elly", "stancho" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
