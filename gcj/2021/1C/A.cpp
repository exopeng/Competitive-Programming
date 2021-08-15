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
    	set<int> as;
    	int n,k;
    	cin>>n>>k;
    	for(int j=0;j<n;j++){
    		int a;
    		cin>>a;
    		as.is(a);
    	}
    	int mx=0;
    	vector<int> poss;
    	poss.pb(k-*prev(as.end()));
    	poss.pb(*as.begin()-1);
    	for(auto it=as.begin();it!=prev(as.end());it++){
    		if(*next(it)-*it>1){
    			poss.pb(1+(*next(it)-*it-2)/2);
    			mx=max(mx,*next(it)-*it-1);
    		}
    	}
    	sort(poss.begin(),poss.end());
    	if(poss.size()>=2){
    		mx=max(mx,poss[poss.size()-1]+poss[poss.size()-2]);
    	}else if(poss.size()==1){
    		mx=max(mx,poss[poss.size()-1]);
    	}
    	cout<<"Case #"<<(i+1)<<": "<<setprecision(10)<<((double)mx/k)<<"\n";
    }
    return 0;
}

