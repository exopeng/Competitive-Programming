#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
int n;
int s[MAXN];
ll dp[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            dp[j][j+i]=min(dp[j+1][j+i]+s[j+i]-s[j],dp[j][j+i-1]+s[j+i]-s[j]);
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}

