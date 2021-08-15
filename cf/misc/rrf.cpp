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
int parent[200000];
int size[200000];
void make_set(int v){
    parent[v]=v;
    size[v]=1;
}
int find_set(int v){
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
vector<pair<int,pii>> ts;
vector<pii> lk;
vector<pair<int,pii>> gk;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	ts.clear(),lk.clear(),gk.clear();
    	int n,m,k;
    	cin>>n>>m>>k;
    	for(int j=0;j<n;j++){
    		make_set(j+1);
    	}
    	int mnk=0;
    	int mxk=INF;
    	for(int j=0;j<m;j++){
    		int a,b,c;
    		cin>>a>>b>>c;
    		ts.pb(mp(c,mp(a,b)));
    		if(c<=k){
    			mnk=max(mnk,c);
    			lk.pb(mp(a,b));
    		}else{
    			mxk=min(mxk,c);
    			gk.pb(mp(c,mp(a,b)));
    		}
    	}

    	if(mxk-k<k-mnk){
    		//use whatever
    		//if<=k, weight is 0, else weight is w-k
    		

    	}else{
    		//check don't use any >=k, check if connected
    		//except mnk, weight is 0


    	}


    }
    return 0;
}

