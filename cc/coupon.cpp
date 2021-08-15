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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
vector<vector<ll>> dp;
vector<vector<ll>> ds;
vector<vector<ll>> cs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll ans=INF;
        int n,m;
        cin>>n>>m;
        dp.resize(n);
        cs.resize(n);
        ds.resize(n);
        for(int j=0;j<n;j++){
            dp[j].clear();
            cs[j].clear();
            ds[j].clear();
            for(int e=0;e<m;e++){
                int a;
                cin>>a;
                dp[j].pb(INF);
                cs[j].pb(a);
                if(j==n-1){
                    dp[j][e]=a;
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int e=0;e<m;e++){
                int a;
                cin>>a;
                ds[j].pb(a);
            }
        }
        for(int j=n-2;j>-1;j--){
            ll mn=INF;
            for(int e=0;e<m;e++){
                mn=min(mn,dp[j+1][e]);
            }
            for(int e=0;e<m;e++){
                if(cs[j+1][e]<ds[j][e]){
                    dp[j][e]=cs[j][e]+min(dp[j+1][e]-cs[j+1][e],mn);
                }else{
                    dp[j][e]=cs[j][e]+min(dp[j+1][e]-ds[j][e],mn);
                }
                if(j==0){
                    ans=min(ans,dp[j][e]);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

