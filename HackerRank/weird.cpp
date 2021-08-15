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
map<int,int> ts;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,m,l;
    cin>>a>>b>>c>>m>>l;
    bs[0]=l;
    ts[l]=0;
    for(int i=1;i<100000000;i++){
    	bs[i]=(a*bs[i-1]*bs[i-1]+b*bs[i-1]+c)%m;
    	if(ts.find(bs[i])!=ts.end()){
    		cout<<ts[bs[i]]<<" "<<i-ts[bs[i]]<<"\n";
    		return 0;
    	}
    	ts[bs[i]]=i;
    }
    return 0;
}

