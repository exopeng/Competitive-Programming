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
map<ll,ll> dp;
void dfs(ll v){
    if(dp.find(v)!=dp.end()){
        return;
    }
    if(v==0){
        dp[v]=0;
    }else{
        dfs(v/2),dfs(v/3),dfs(v/4);
        dp[v]=max(dp[v/2]+dp[v/3]+dp[v/4],v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    while(cin>>n)
    {
       dfs(n);
       cout<<dp[n]<<"\n";
    }
    return 0;
}

