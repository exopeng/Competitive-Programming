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
#define ll long long
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,m,k,a,b;
vector<pair<int,string> > adj[MAXN];
vector<string> ks;
string sp[MAXN];
//maps original string to new string
map<string,string> vs;
//maps new string to original string
map<string,string> sv;
//maps original string to index
map<string,int> ix;
vector<string> st;
int ct[6];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("wiring.in","r",stdin);
    freopen("wiring.out","w",stdout);
    cin>>n>>m>>k>>a>>b;
    a--,b--;
    for(int i=0;i<k;i++){
    	string s;
    	cin>>s;
    	ks.pb(s);
    	ix[s]=i;
    }
    sort(ks.begin(),ks.end());
    st.pb("a");
    st.pb("b");
    st.pb("c");
    st.pb("d");
    st.pb("e");
    for(int i=0;i<k;i++){
    	vs[ks[i]]=st[i];
    	sv.is(mp(st[i],ks[i]));
    }
    for(int i=0;i<m;i++){
    	int c,d;
    	string s;
    	cin>>c>>d>>s;
    	c--,d--;
    	adj[c].pb(mp(d,vs[s]));
    	adj[d].pb(mp(c,vs[s]));
    }
    queue<pair<int,string>> q;
    sp[a]="A";
    for(int i=0;i<adj[a].size();i++){
    	sp[adj[a][i].f]=adj[a][i].s;
    	q.push(mp(adj[a][i].f,adj[a][i].s));
    }
    while(q.empty()==false){
    	pair<int,string> t=q.front();
    	q.pop();
    	if(t.s!=sp[t.f]){
    		continue;
    	}
    	for(int i=0;i<adj[t.f].size();i++){
    		string ns=t.s+adj[t.f][i].s;
    		if(sp[adj[t.f][i].f]==""||ns.size()<sp[adj[t.f][i].f].size()||
    			ns.size()==sp[adj[t.f][i].f].size()&&ns<sp[adj[t.f][i].f]){
    			//cout<<"r:"<<sp[adj[t.f][i].f]<<" "<<ns<<"\n";
    			sp[adj[t.f][i].f]=ns;
    			q.push(mp(adj[t.f][i].f,ns));
    		}else{
    			//cout<<"r:"<<sp[adj[t.f][i].f]<<" "<<ns<<"\n";
    		}
    	}
    }
    bool np=false;
    if(sp[b].size()==0){
    	np=true;
    }
    for(int i=0;i<sp[b].size();i++){
    	string c;
    	c+=sp[b][i];
    	ct[ix[sv[c]]]++;
    }
    for(int i=0;i<k;i++){
    	if(np){
    		cout<<-1<<"\n";
    	}else{
    		cout<<ct[i]<<"\n";
    	}
    }
    
    return 0;
}
/* REMINDERS
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
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

