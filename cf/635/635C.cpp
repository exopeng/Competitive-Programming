#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200000;
vector<int> adj[MAXN];
int ctUnder[MAXN];
vector< pair<int, int> > distances;
int n, k;
long long ans = 0;

int dfs(int x, int last, int dist) {
	distances.push_back(make_pair(dist, x));

	if (adj[x].size() == 1 && last == adj[x][0]) {
		ctUnder[x] = 0;
		return 0;
	}
	for (int i = 0; i < adj[x].size(); i++) {
		if (adj[x][i] != last) {
			ctUnder[x] += 1 + dfs(adj[x][i], x, dist + 1);
		}
	}
	return ctUnder[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
   		adj[y].push_back(x);
	}
	//for (int i = 0; i < n; i++) {
	//	cout << ctUnder[i] << " ";
	//}
	//find number of nodes under each node
	dfs(0, -1, 0);

	//for (int i = 0; i < n; i++) {
//		cout << ctUnder[i] << " ";
//	}
//	cout << "\n";

	//for (int i = 0; i < n; i++) {
	//	cout << distances[i].first << " " << distances[i].second << "\n";
	//}
	//for every node, start with greatest and propagate downwards
	//sort(dist.begin(), dist.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		distances[i].first -= ctUnder[distances[i].second];
	}
	sort(distances.begin(), distances.end());
	reverse(distances.begin(), distances.end());

	for (int i = 0; i < k; i++) {
		ans += distances[i].first;
	}
	cout << ans << "\n";
}

