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

class AddElectricalWires {
public: 
	int maxNewWires(vector <string> wires, vector <int> gridConnections);
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"01000","10100","01010","00100","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maxNewWires(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	AddElectricalWires ___test;
	___test.run_test(-1);
}
// END CUT HERE

#define foreach(i,a,b) for(__typeof(a) i = a; i != b; ++i)
#define forall(i,x) foreach(i,x.begin(),x.end())

void dfs(vector <string> &wires, vector<int> &color, vector<int> &amount, int Color, int pos)
{
	color[pos] = Color;
	amount[Color]++;
	
	for (int i = 0; i < wires[pos].size(); ++i)
		if (wires[pos][i] == '1' && color[i] == -1)
			dfs(wires, color, amount, Color, i);
}

int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridC) {
	int res = 0;
	
	vector<int> color(wires.size(), -1);
	vector<int> amount(wires.size(), 0);
	
	for (int i = 0; i < gridC.size(); ++i)
		dfs(wires, color, amount, gridC[i], gridC[i]);

	//for (int i = 0; i < color.size(); ++i)
	//	cout << i << " " << color[i] << endl;
	
	//completa os coloridos
	for (int i = 0; i < wires.size(); ++i)
	{
		if (color[i] != -1)
		{
			for (int j = 0; j < wires.size(); ++j)
				if (i != j && wires[i][j] == '0' && color[i] == color[j])
				{
					res++;
					wires[i][j] = '1';
					wires[j][i] = '1';
				}
		}
	}
	
	int maxx = 0;
	for (int i = 1; i < amount.size(); ++i)
		if (amount[i] > amount[maxx])
			maxx = i;

	for (int i = 0; i < wires.size(); ++i)
	{
		if (color[i] == -1)
		{
			color[i] = maxx;
			amount[maxx]++;
			
			for (int j = 0; j < wires.size(); ++j)
				if (i != j && wires[i][j] == '0' && color[i] == color[j])
				{
					res++;
					wires[i][j] = '1';
					wires[j][i] = '1';
				}
		}
	}
	
	return res;
}
