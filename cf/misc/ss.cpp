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
int a[MAXN];
//hours, element
int dp[2001][2001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<2001;j++){
            dp[j][i]=-1;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<h;j++){
            if(dp[j][i]>=0){
                if((j+a[i])%h>=l&&(j+a[i])%h<=r){
                 dp[(j+a[i])%h][i+1]=max(dp[(j+a[i])%h][i+1],dp[j][i]+1);
                }else{
                 dp[(j+a[i])%h][i+1]=max(dp[(j+a[i])%h][i+1],dp[j][i]);
                }
                if((j+a[i]-1)%h>=l&&(j+a[i]-1)%h<=r){
                 dp[(j+a[i]-1)%h][i+1]=max(dp[(j+a[i]-1)%h][i+1],dp[j][i]+1);
                }else{
                 dp[(j+a[i]-1)%h][i+1]=max(dp[(j+a[i]-1)%h][i+1],dp[j][i]);
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<2001;i++){
        mx=max(mx,dp[i][n]);
    }
    cout<<mx<<'\n';
    return 0;
}

