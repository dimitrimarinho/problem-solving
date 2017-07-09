#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class DistanceZeroAndOne {
public:
    vector <string> construct( vector <int> dist0, vector <int> dist1 ) {
     	if (dist0[0] || dist1[1] || (dist0[1] != dist1[0])) return {};
     	int n = dist0.size();

     	vector<vector<int>> at_dist[2];
     	for (int i = 0; i < n; ++i) {
     		at_dist[0].push_back(vector<int>());
     		at_dist[1].push_back(vector<int>());
     	}

     	for (int i = 0; i < n; ++i) {
     		at_dist[0][dist0[i]].push_back(i);
     		at_dist[1][dist1[i]].push_back(i);
     	}

     	auto consecutive = [&at_dist](int from, int d, int i, int j) -> bool {
     		return binary_search(at_dist[from][d].begin(), at_dist[from][d].end(), i) &&
     					 binary_search(at_dist[from][d+1].begin(), at_dist[from][d+1].end(), j);
     	};

     	auto samelevel = [&at_dist](int from, int d, int i, int j) -> bool {
     		return binary_search(at_dist[from][d].begin(), at_dist[from][d].end(), i) &&
     					 binary_search(at_dist[from][d].begin(), at_dist[from][d].end(), j);
     	};

     	vector<string> res(n, string(n, 'N'));
     	for (int i = 0; i < n; ++i) {
     		for (int j = i+1; j < n; ++j) {
     			bool consecutive0 = false, consecutive1 = false;
     			bool samelevel0 = false, samelevel1 = false;
     			for (int d = 0; d < n; ++d) {
     				if (d+1 < n && (consecutive(0, d, i, j) || consecutive(0, d, j, i))) consecutive0 = true;
     				if (d+1 < n && (consecutive(1, d, i, j) || consecutive(1, d, j, i))) consecutive1 = true;
     				if (samelevel(0, d, i, j)) samelevel0 = true;
     				if (samelevel(1, d, i, j)) samelevel1 = true;
     			}
     			if ((consecutive0 && consecutive1) || (consecutive0 && samelevel1) || (consecutive1 && samelevel0))
     				res[i][j] = res[j][i] = 'Y';
     		}
     	}

     	auto get_dists = [&](int from) -> vector<int> {
     		vector<int> ds(n, 256);
     		ds[from] = 0;
     		queue<int> q;
     		q.push(from);
     		while (!q.empty()) {
     			int u = q.front(); q.pop();
     			for (int v = 0; v < n; ++v) if (res[u][v] == 'Y' && ds[v] == 256) {
     				q.push(v);
     				ds[v] = ds[u] + 1;
     			}
     		}
     		return ds;
     	};

     	auto nd = get_dists(0);
     	if (nd != dist0) return {};
     	nd = get_dists(1);
     	if (nd != dist1) return {};

     	return res;
    }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing DistanceZeroAndOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495297113;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DistanceZeroAndOne _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {2,0,1};
				string __expected[] = {"NNY", "NNY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 1:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {1,0,2};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 2:
			{
				int dist0[] = {3,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 3:
			{
				int dist0[] = {0,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = {"NYYY", "YNYY", "YYNN", "YYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 4:
			{
				int dist0[] = {0,3,1,2,2,3,4,4};
				int dist1[] = {3,0,2,1,2,3,4,4};
				string __expected[] = {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 5:
			{
				int dist0[] = {0,1};
				int dist1[] = {1,0};
				string __expected[] = {"NY", "YN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			/*case 6:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
