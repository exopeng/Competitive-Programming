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
map<int,int> ms;
vector<ll> ps;
map<int,int> mt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;i++){
    	int a;
    	cin>>a;
    	ms[a]++;
    }
    int ix=0;
    ll lt=0;
    for(auto it=ms.begin();it!=ms.end();it++){
    	ps.pb(0);
    	mt[ix]=it->f;
    	ps[ix]+=lt;
    	ps[ix]+=it->s;
    	lt=ps[ix];
    	ix++;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
    	int x;
    	cin>>x;
    	auto it=lb(ps.begin(),ps.end(),x+1);
    	if(it==ps.end()){
    		cout<<s<<"\n";
    	}else{
    		cout<<mt[(it-ps.begin())]-1<<"\n";
    	}
    }

    return 0;
}

