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
vector<int> adj[MAXN];
int sum[MAXN];
int mx[MAXN];
void dfs(int v, int p){
    for(int j=0;j<adj[v].size();j++){
        if(adj[v][j]!=p){
            dfs(adj[v][j],v);
            sum[v]+=sum[adj[v][j]];
        }
    }
    sum[v]++;
}
pii fl(int v, int p){
	if(adj[v].size()==1){
		return mp(v,p);
	}
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			return fl(adj[v][i],v);
		}
	}
	return mp(-1,-1);
}
int ct=INF;
int ct1=-1;
int ct2=-1;
void tr(int v,int p){
    int ps=sum[p];
    int ls=sum[v];
    sum[p]-=ls;
    sum[v]+=sum[p];
    for(int j=0;j<adj[v].size();j++){
        mx[v]=max(mx[v],sum[adj[v][j]]);
    }
    if(mx[v]<ct){
        ct=mx[v];
        ct1=v;
       	ct2=-1;
    }else if(mx[v]==ct){
    	ct2=v;
    }
    for(int j=0;j<adj[v].size();j++){
        if(adj[v][j]!=p){
            tr(adj[v][j],v);
        }
    }
    sum[p]=ps;
    sum[v]=ls;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
    	ct2=-1;
        for(int j=0;j<n;j++){
            adj[j].clear();
            sum[j]=0;
            mx[j]=0;
        }
    	for(int j=0;j<n-1;j++){
    		int a,b;
            cin>>a>>b;
            a--,b--;
            adj[a].pb(b);
            adj[b].pb(a);
    	}
        dfs(0,-1);
        for(int j=0;j<adj[0].size();j++){
	        mx[0]=max(mx[0],sum[adj[0][j]]);
	    }
	    ct=mx[0];
	    ct1=0;
        for(int j=0;j<adj[0].size();j++){
            tr(adj[0][j],0);
        }
        if(ct2==-1){
        	//cout<<"h";
        	cout<<1<<" "<<adj[0][0]+1<<"\n";
        	cout<<1<<" "<<adj[0][0]+1<<"\n";
        }else{
        	if(sum[ct1]>sum[ct2]){
        		pii rs=fl(ct2,ct1);
        		cout<<rs.s+1<<" "<<rs.f+1<<"\n";
        		cout<<ct1+1<<" "<<rs.f+1<<"\n";
        	}else{
        		pii rs=fl(ct1,ct2);
        		cout<<rs.s+1<<" "<<rs.f+1<<"\n";
        		cout<<ct2+1<<" "<<rs.f+1<<"\n";
        	}
        }
    }
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
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

