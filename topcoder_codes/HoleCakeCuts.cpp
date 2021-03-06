#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

class HoleCakeCuts {
public: 
	vector<bool> hCut;
	vector<bool> vCut;
	vector< vector <bool> > mark;
	int sz;
	void dfs(int i, int j);
	int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts);
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, -4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(0, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-2, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(2, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 5; int Arr2[] = {40, -40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 0, -20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 12; verify_case(3, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	HoleCakeCuts ___test;
	___test.run_test(-1);
}
// END CUT HERE

#define foreach(i,a,b) for(__typeof(a) i = a; i != b; ++i)
#define forall(i,x) foreach(i,x.begin(),x.end())

int HoleCakeCuts::cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts) {
	hCut = vector<bool> (cakeLength*2 - 1 ,false);
	vCut = vector<bool> (cakeLength*2 - 1 ,false);
	mark = vector< vector <bool> >( cakeLength*2, vector<bool> ( cakeLength*2 ,false) );
	
	for (int i = 0; i < horizontalCuts.size(); ++i)
		hCut[horizontalCuts[i] + cakeLength - 1] = true;
	for (int i = 0; i < verticalCuts.size(); ++i)
		vCut[verticalCuts[i] + cakeLength - 1] = true;
		
	for (int i = cakeLength - holeLength; i < cakeLength + holeLength; ++i)
		for (int j = cakeLength - holeLength; j < cakeLength + holeLength; ++j)
			mark[i][j] = true;
	int res = 0;
	
	sz = cakeLength*2;
	for (int i = 0; i < cakeLength*2; ++i)
		for (int j = 0; j < cakeLength*2; ++j)
			if ( !mark[i][j] )
			{
				res++;
				dfs(i, j);
			}
	return res;
}

void HoleCakeCuts::dfs(int i, int j)
{
	if (mark[i][j])
		return;
	
	mark[i][j] = true;
	
	if (i > 0 && vCut[i - 1] == false)
		dfs(i - 1, j);
	if (i < sz - 1 && vCut[i] == false)
		dfs(i + 1, j);
	if (j > 0 && hCut[j - 1] == false)
		dfs(i, j - 1);
	if (j < sz-1 && hCut[j] == false)
		dfs(i, j + 1);	
}

