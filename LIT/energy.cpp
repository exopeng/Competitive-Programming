#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int n,m,t;
const int INF = 1000000000;

int cost[10001];
vector<pair<int,int> > adj[10001];
int d[10001][31];

void dijkstrapq(int s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            d[i][j] = INF;
        }
    }

    d[s][t] = 0;

    using pii = pair<int, pair<int,int> >;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({0, {0,t}});

    while (!q.empty()) {
        int v = q.top().second.first;
        int vj = q.top().second.second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v][vj])
            continue;
        //not really necessary

        //or maybe stock up at v?
        //should process the d[v][vj]...d[v][vj+1]...
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (vj - len >= 0) {
                if (d[v][vj] < d[to][vj-len]) {
                    d[to][vj-len] = d[v][vj];
                    q.push({d[to][vj-len], {to,vj-len}});
                }
                //check INF
                //cout impossible to get to that building
                if (cost[to] != 0 && d[to][vj-len] != INF) {
                    for (int i = vj -len + 1; i <= t; i++) {
                        if (d[to][i-1] + cost[to] < d[to][i]) {
                            d[to][i] = d[to][i-1] + cost[to];
                            q.push({d[to][i], {to,i}});
                        }
                    }
                }
            } 
            
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >>t;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    
    dijkstrapq(0);

    for (int i = 1; i < n; i++) {
        int minx = INF;
        for (int j = 0; j <= t; j++) {
            minx = min(minx,d[i][j]);
        }
        if (minx == INF) {
            cout << -1 << " ";
        } else {
            cout << minx << " ";
        }
    }
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
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
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

