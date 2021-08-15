#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100000];
bool visited[100000];
vector<int> ans;
void dfs(int v) {
	if (visited[v]) {
		return;
	}
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		dfs(adj[v][i]);
	}
	ans.push_back(v);
}

void toposort() {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   	n = 11;
   	adj[0].push_back(2);
   	adj[1].push_back(2);
   	adj[2].push_back(3);
   	adj[2].push_back(4);
   	adj[2].push_back(5);
   	adj[3].push_back(6);
   	adj[3].push_back(7);
   	adj[4].push_back(8);
   	adj[5].push_back(8);
   	adj[8].push_back(9);
   	adj[9].push_back(10);
   	adj[7].push_back(9);
   	toposort();
   	for (int i = 0; i < n; i++) {
   		cout << ans[i] << " ";
   	}
   	cout << "\n";
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

