#include <bits/stdc++.h>
using namespace std;

bool visited[1000000];
vector <int> ts;
int n;
long long ans = 0;
vector <int> path;
unordered_set<int> notcycle;
void revisit() {
	for (int i = 0; i < path.size(); i++) {
		notcycle.insert(path[i]);
		ans++;
	}
}
void dfs(int curr) {
	if (curr < 0 || curr > n-1) {
		//every trampoline on this path doesn't lead to infinite jumping
		//reverse and go back to all the ones that lead to this
		revisit();
		return;
	}
	//going on a non-infinite tramp
	if (notcycle.find(curr) != notcycle.end()) {
		revisit();
		return;
	}
	if (visited[curr]) {
		return;
	}
	visited[curr] = true;
	path.push_back(curr);
	dfs(curr + ts[curr]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	notcycle.clear();
    	ans = 0;
    	ts.clear();
    	cin >> n;
    	for (int i = 0; i < 1000000; i++) {
    		visited[i] = false;
    	}
    	for (int i = 0; i < n; i++) {
    		int element;
    		cin >> element;
    		ts.push_back(element);
    	}
    	//cycle finding
    	for (int i = 0; i < n; i++) {
    		path.clear();
    		if (!visited[i]) {
    			dfs(i);
    		}
    	}
    	cout << n - ans << "\n";
    }
}

