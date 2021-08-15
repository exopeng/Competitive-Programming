#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int d[1000];
int p[1000];
bool visited[1000];
int n;
int edges;
vector<pii> adj[5];

vector<vector<pii>> adj;

void dpq(int s){
    for(int i=0;i<n;i++){
        d[i]=INF;
        p[i]=-1;
    }
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        int v=q.top().s;
        int d_v=q.top().f;
        q.pop();
        if(d_v!=d[v])
            continue;
        for(auto edge:adj[v]){
            int to=edge.f;
            int len=edge.s;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                p[to]=v;
                q.push({d[to],to});
            }
        }
    }
}

void dj(int s){
	for(int i=0;i<n;i++){
		d[i]=INF;
		p[i]=-1;
		vis[i]=false;
	}
	d[s]=0;
	for(int i=0;i<n;i++){
		int v=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&(v==-1||d[j]<d[v])){
				v=j;
			}
		}
		if(d[v]==INF){
			break;
		}
		vis[v]=true;
		for(int j=0;j<adj[v].size();j++){
			int to=adj[v][j].f;
            int len=adj[v][j].s;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                p[to]=v;
            }
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
    	int a,b,w;
    	cin >> a >> b >> w;
    	adj[a].push_back(make_pair(b,w));
     	adj[b].push_back(make_pair(a,w));
    }
    djikstra(0);
    
    for (int i = 0; i < n; i++) {
    	vector<int> path = getPath(0, i);
    	cout << 0 << "->" << i << " dist:" << dist[i] << " path:"; 
    	for (int j = 0; j < path.size(); j++) {
    		cout << path[j] << " ";
    	}
    	cout << "\n";
    }
	


}