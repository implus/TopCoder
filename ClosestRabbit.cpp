/* BEGIN CUT HERE
SRM 636 div 1 level 2:
only u -> v -> u circle exist, 3 more can't be there
so it's like tree structure, some edge duplicated, duplicated edge we lose it;

if edges number == n - 1, just a tree, 1 component
				   n - 2, just 2 trees, 2 component
n - x means x edges duplicated, there is x  u->v->u
so if there is a u->v->u, there is more one component

check every pair(u, v)'s possibility to be (u->v->u) 
*/
#line 5 "ClosestRabbit.cpp"
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;

//#define TEST
class ClosestRabbit {
	public:
	int dis(pii a, pii b){
		int x = a.first - b.first, 
		y = a.second - b.second;
		return x * x + y * y;
	}
	double C[440][440];
	double getExpected(vector <string> board, int r) {
		int n = board.size(), m = board[0].size();
		vector<pii> lx;
		for(int i = 0; i < n; i++){
			for(int j =0 ; j < m; j++){
				if(board[i][j] == '.') 
					lx.push_back(pii(i, j));
			}
		}

		for(int i = 0; i < 440; i++){
			C[i][0] = 1;
			for(int j = 1; j <= i; j++){
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}

		int c = lx.size();
		double ans = 0;
		for(int i = 0; i < c; i++){
			for(int j = i + 1; j < c; j++){
				// pair i, j
				int d = dis(lx[i], lx[j]), no = 0;
				for(int k = 0; k < c; k++){
					if(k == i || k == j) continue;
					bool ok = 1;
					if(dis(lx[k], lx[i]) < d || (dis(lx[k], lx[i]) == d && k < j)) ok = 0;
					if(dis(lx[k], lx[j]) < d || (dis(lx[k], lx[j]) == d && k < i)) ok = 0;
					if(ok) no++;
				}
				ans += C[no][r - 2] / C[c][r];
			}
		}
		return ans;
	}
#ifdef TEST
#define CUT1
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.6; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 2.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....",
 "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.253968253968254; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#####.#####..#....#",
 "#......#....#.##..##",
 ".####..#####..#.##.#",
 ".....#.#...#..#....#",
 "#####..#....#.#....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; double Arg2 = 5.77311527122319; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE

#endif
};

#ifdef TEST
#define CUT2
int main(){ ClosestRabbit __test; __test.run_test(-1); return 0; }
#endif
