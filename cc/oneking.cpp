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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	//rights should go after lefts, right->1, left->0
    	//stop after reaching last right of that point
    	vector<pair<int,pii>> ts;
    	cin>>n;
    	for(int j=0;j<n;j++){
    		int a,b;
    		cin>>a>>b;
    		ts.pb(mp(a,mp(0,j)));
    		ts.pb(mp(b,mp(1,j)));
    	}
    	set<int> sn;
    	sort(ts.begin(),ts.end());
    	int ans=0;
    	set<int> act;
    	for(int j=0;j<ts.size();j++){
    		if(sn.find(ts[j].s.s)==sn.end()){
    			if(ts[j].s.f==1){
    				int pt=ts[j].f;
    				while(j+1<ts.size()&&ts[j+1].f==pt){
    					j++;
    				}
    				for(auto it=act.begin();it!=act.end();it++){
    					sn.is(*it);
    				}
    				ans++;
    				act.clear();
    				//cout<<"i"<<"\n";
	    		}else{
	    			act.is(ts[j].s.s);
	    		}
    		}	
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}

