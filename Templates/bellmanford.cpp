#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int dist[1000];
int path[1000];
int n;
int edge;
vector< pair< pair<int,int>, int> > edges;


bool bellmanford(int source) {
	for (int i = 0; i < n; i++) {
		dist[i] = inf;
		path[i] = -1;
	}
	bool negcycle;
	dist[source] = 0;
	for (int i = 0; i < n; i++) {
		negcycle = false;
		for (int j = 0; j < edge; j++) {
			int a = edges[j].first.first;
			int b = edges[j].first.second;
			int w = edges[j].second;
			if (dist[a] < inf) {
				if (dist[a] + w < dist[b]) {
					dist[b] = dist[a] + w;
					path[b] = a;
					negcycle = true;
				}
			}
		}
	}
	if (negcycle) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> edge;
    for (int i = 0; i < edge; i++) {
    	int a,b,w;
    	cin >> a >> b >> w;
    	edges.push_back(make_pair(make_pair(a,b), w));
    }
    if (bellmanford(1)) {
    	cout << "negative cycle" << "\n";
    } else {
    	for (int i = 0; i < n; i++) {
	    	vector<int> path = getPath(0, i);
	    	cout << 0 << "->" << i << " dist:" << dist[i] << " path:"; 
	    	for (int j = 0; j < path.size(); j++) {
	    		cout << path[j] << " ";
	    	}
	    	cout << "\n";
    	}
    }
    
    
	


}