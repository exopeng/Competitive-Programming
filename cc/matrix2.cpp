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
const int MAXN = 2e3+5;
//store test cases here
/*


*/
int el[MAXN][MAXN];
int ed[MAXN][MAXN];
int dp[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            el[i][j]=ed[i][j]=dp[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            el[i][j]+=el[i][j-1]*el[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=n-2;j>-1;j--){
            ed[j][i]+=ed[j+1][i]*ed[j][i];
        }
    }
    ll ans=0;
    for(int i=1;i<m;i++){
        for(int j=0;j<n-1;j++){
            dp[j][i]=min(el[j][i],ed[j][i]);
            dp[j][i]=min(dp[j][i],dp[j+1][i-1]+2);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dp[i][j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}

