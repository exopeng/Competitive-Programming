#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int d[1000][1000];
int p[1000][1000];
vector< pair<int,int> > adj[1000];
int n;
int edges;

bool floydwarshall() {
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (j != i) {
    			d[i][j] = inf;
    			p[i][j] = n;
    		} else {
    			d[i][j] = 0;
    			p[i][j] = -1;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < adj[i].size(); j++) {
    		p[i][adj[i][j].first] = i;
    		d[i][adj[i][j].first] = adj[i][j].second;
    	}
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
    bool negcycle = false;
    for (int i = 0; i < n; i++) {
    	if (d[i][i] < 0) {
    		negcycle = true;
    		break;
    	}
    }
    return negcycle;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> edges;

    for (int i = 0; i < edges; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
    }

/*
4 4
0 2 -2
2 3 2
3 1 -1
1 2 3
1 0 4
*/
    if (floydwarshall()) {
    	cout << "negative cycle weight" << "\n";
    } else {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if (i != j) {
    				cout << i << "-> " << j << " dist: " << dist[i][j] << " Path: ";
    				vector<int> temp = getPath(i,j);
    				for (int k = 0; k < temp.size(); k++) {
    					cout << temp[k] << " ";
    				}
    				cout << "\n";
    			}
    		}
    	}
    }
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

