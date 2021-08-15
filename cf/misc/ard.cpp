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
const int MAXN = 2e6;
//store test cases here
/*


*/
int a[MAXN];
set<int> ax[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
    	n*=2;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
    	}
    	sort(a,a+n);
    	for(int j=0;j<n;j++){
    		ax[a[j]].is(j);
    	}
    	vector<int> as;
    	for(int j=0;j<n-1;j++){
    		vector<int> ts;
    		vector<bool> tk(n,false);
    		bool g=true;
    		tk[n-1]=true,tk[j]=true;
    		//use set to track nodes
    		ax[a[n-1]].erase(j),ax[a[j]].erase(n-1);
    		ts.pb(n-1),ts.pb(j);
    		int lt=a[n-1];
    		for(int f=n-2;f>-1;f--){
    			if(tk[f]){
    				continue;
    			}
    			tk[f]=true;
    			ts.pb(f);
    			ax[a[f]].erase(f);
    			if(ax[lt-a[f]].size()==0){
    				g=false;
    				break;
    			}
    			tk[*prev(ax[lt-a[f]].end())]=true;
    			ts.pb(*prev(ax[lt-a[f]].end()));
    			ax[lt-a[f]].erase(*prev(ax[lt-a[f]].end()));
    			lt=a[f];
    		}
    		if(g){
    			as=ts;
    			break;
    		}
    		for(int f=0;f<ts.size();f++){
    			ax[a[ts[f]]].is(ts[f]);
    		}
    	}
    	for(int j=0;j<n;j++){
    		ax[a[j]].clear();
    	}
    	if(as.size()){
    		cout<<"YES"<<"\n";
    		cout<<(a[as[0]]+a[as[1]])<<"\n";
    		for(int j=0;j<as.size();j+=2){
    			cout<<a[as[j]]<<" "<<a[as[j+1]]<<"\n";
    		}
    	}else{
    		cout<<"NO"<<"\n";
    	}
    }
    return 0;
}

