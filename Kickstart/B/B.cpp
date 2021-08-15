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
const int MAXN = 5e5;
//store test cases here
/*


*/
int dp[MAXN][2];
int a[MAXN];
//d[i][0]=a[i+1]-a[i],d[i][1]=a[i-1]-a[i]
int d[MAXN][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
            if(j){
                d[j-1][0]=a[j]-a[j-1];
            }
            if(j){
                d[j][1]=a[j-1]-a[j];
            }
        }
        int ans=2;
        dp[n-1][0]=dp[0][1]=1;
        dp[n-2][0]=dp[1][1]=2;
        for(int j=n-3;j>-1;j--){
            if(d[j][0]==d[j+1][0]){
                dp[j][0]=dp[j+1][0]+1;
            }else{
                dp[j][0]=2;
            }
            ans=max(ans,dp[j][0]);
        }
        for(int j=2;j<n;j++){
            if(d[j][1]==d[j-1][1]){
                dp[j][1]=dp[j-1][1]+1;
            }else{
                dp[j][1]=2;
            }
            ans=max(ans,dp[j][1]);
        }
        if(ans!=n){
            ans++;
        }
        //edge case n==3
        //edge case j=0&&j==n-2
        for(int j=2;j<n-1;j++){
            if(a[j]-a[j-2]==2*d[j][0]){
                ans=max(ans,dp[j][0]+2);
            }
        }
        for(int j=n-3;j>0;j--){
            if(a[j]-a[j+2]==2*d[j][1]){
                ans=max(ans,dp[j][1]+2);
            }
        }
        //one connectors???
        for(int j=1;j<n-3;j++){
            if(-1*d[j][1]==d[j+2][0]&&a[j+2]-a[j]==2*d[j+2][0]){
                ans=max(ans,dp[j][1]+dp[j+2][0]+1);
            }
        }
        cout<<"Case #"<<(i+1)<<": "<<ans<<"\n";
    }
    return 0;
}

