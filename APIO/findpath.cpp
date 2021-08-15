#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pii pair<int,int>
#define is insert
const long long INF = 1000000000;
const long long MOD = 1000000007;
const int MAXN = 1e3+5;
//store test cases here
/*


*/
int n,t;
map<pii,long long> d;
map<pii, vector<pii> > adj;

//NESW sides
struct side {
	int a,b,c,d;
	int id;
	bool nw;
	side(int a,int b,int c,int d,int id,bool nw){
		this->a=a;
		this->b=b;
		this->c=c;
		this->d=d;
		this->id=id;
		this->nw=nw;
	}

};
void dijkstrapq(pii s) {
    d[s] = 0;
    priority_queue< pair<int,pii> >, vector<p air<int,pii> >, greater< pair<int,pii> >> q;
    q.push({0, s});
    while (!q.empty()) {
        pii v = q.top().s;
        int d_v = q.top().f;
        q.pop();
        if (d_v != d[v])
            continue;
        for (auto edge : adj[v]) {
            pii to = edge;
            int len = abs(v.f-to.f)+abs(v.s-to.s);
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}
bool cmp(side& a,side& b){
	return a.a<b.a;
}
bool cmp1(side& a,side& b){
	return a.b<b.b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
    	pii start,end;
    	cin>>start.f>>start.s>>end.f>>end.s;
    	cin>>n;
    	vector<pii> edges;
		vector<pii> next[MAXN][4];
		vector<side> sidex;
		vector<side> sidey;
		vector<pair<pii,pii> > rect;
    	adj.clear();
    	d.clear();
    	for(int i=0;i<n;i++){
    		int a,b,c,d;
    		cin>>a>>b>>c>>d;
    		rect.pb(mp(mp(a,b),mp(c,d)));
    		//bottom to top
    		sidex.pb(side(a,b,a,d,i+1,true));
    		sidex.pb(side(c,b,c,d,i+1,false));
    		sidey.pb(side(a,d,c,d,i+1,true));
    		sidey.pb(side(a,b,c,b,i+1,false));
    	}
    	//get all edges
    	sidex.pb(side(start.f,start.s,start.f,start.s,0,true));
    	sidey.pb(side(start.f,start.s,start.f,start.s,0,true));
    	sidex.pb(side(end.f,end.s,end.f,end.s,n+1,true));
    	sidey.pb(side(end.f,end.s,end.f,end.s,n+1,true));

    	sidex.pb(side(start.f,start.s,start.f,start.s,0,false));
    	sidey.pb(side(start.f,start.s,start.f,start.s,0,false));
    	sidex.pb(side(end.f,end.s,end.f,end.s,n+1,false));
    	sidey.pb(side(end.f,end.s,end.f,end.s,n+1,false));

    	sort(sidex.begin(),sidex.end(),cmp);
    	sort(sidey.begin(),sidey.end(),cmp1);
    	for(int i=0;i<sidex.size();i++){
    		set<pii> cov;
    		for(int j=0;j<sidex.size();j++){
    			if(i==j){
    				continue;
    			}
    			//handle if closest x to intersection
    			//see if left or right side, top/bot, leq and geq x...
    			//add pts to edge list and all edges
    			//add to relevant rect
    		}
    	}
    	for(int i=0;i<sidey.size();i++){
    		
    	}
    	//add adj edges on same rect
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<4;j++){
    			sort(next[i][j].begin(),next[i][j].end());
    		}
    		for(int j=0;j<4;j++){
    			for(int e=0;e<next[i][j].size();e++){
    				pii curr=next[i][j][e];
    				if(e==0){
    					adj[curr].pb(adj[next[i][j][e+1]]);
    					int sz=next[i][(j+3)%4].size()-1;
    					adj[curr].pb(adj[next[i][(j+3)%4][sz]]);
    				} else if(e==next[i][j].size()-1){
						adj[curr].pb(adj[next[i][j][e-1]]);
    					int sz=next[i][(j+1)%4].size()-1;
    					adj[curr].pb(adj[next[i][(j+1)%4][sz]]);
    				} else{
    					adj[curr].pb(adj[next[i][j][e+1]]);
    					adj[curr].pb(adj[next[i][j][e-1]]);
    				}
    			}
    		}
    	}
    	//set all to INF
    	for(int i=0;i<edges.size();i++){
    		d[edges[i]]=INF;
    	}
    	dijkstrapq(start);
    	if(d[end]==INF){
    		cout<<"No Path"<<"\n";
    	} else{
    		cout<<d[end]<<"\n";
    	}

    }

    return 0;
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

