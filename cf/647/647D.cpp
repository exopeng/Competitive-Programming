#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[500000];
int des[500000];
unordered_set< pair<int,int> > nodes1;
string ans = "";
vector< pair<int,int> > nodes;
set<int> take;
int taken[500000];
bool found = false;

bool cmp(const int &a, const int &b) {
	if (taken[a] == 0 && taken[b] == 0) {
		return (des[a] < des[b]);
	} else {
		if (taken[a] == 0) {
			return true;
		}
		return false;
	}
}

void dfs(int curr) {
	if (found) {
		return;
	}
	if (taken[curr]) {
		return;
	}
	nodes1.remove(make_pair(des[curr], curr));
	//determine lowest num to take
	take.clear();

	ans += to_string(curr);
	for (int i = 0; i < adj[curr].size(); i++) {
		if (taken[adj[curr][i]] != 0) {
			take.insert(taken[adj[curr][i]]);
		}
	}

	if (*take.begin() > des[curr]) {
		taken[curr] = des[curr];
	} else {
		if (take.find(des[curr]) != take.end()) {
			cout << "-1" << "\n";
			found = true;
			return;
		}
		for (set<int>::iterator it = take.begin(); it != take.end(); it++) {
			//find the first topic that you can use
			if (take.find(*(it)) == take.end()) {
				if (*take.find(*(it) + 1) != des[curr]) {
					cout << "-1" << "\n";
					found = true;
					return;
				} else {
					taken[curr] = des[curr];
					break;
				}
			}
		}		
	}
	//visit neigbors in order of smallest to largest blog
	sort(adj[curr].begin(), adj[curr].end(), cmp);
	for (int i = 0; i < adj[curr].size(); i++) {
		dfs(adj[curr][i]);
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a,b;
    	cin >> a >> b;
    	a--,b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
    	cin >> des[i];
    	nodes.push_back(make_pair(des[i],i));
    }
    sort(nodes.begin(), nodes.end());
    for (int i = 0; i < n; i++) {
    	if (nodes1.find(nodes[i]) == nodes1.end()) {
    		continue;
    	}
    	dfs(i);
    }
    cout << ans << "\n";
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
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
 */

