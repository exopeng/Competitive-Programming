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
ll dp[11][2];
ll a[11];
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
        }
        dp[0][0]=dp[0][1]=a[0];
        for(int j=1;j<n;j++){
            for(int f=0;f<2;f++){
                if(f){
                    dp[j][f]=max(dp[j-1][f]*a[j],dp[j-1][f]-a[j]);
                    dp[j][f]=max(dp[j][f],dp[j-1][f]+a[j]);
                    dp[j][f]=max(dp[j][f],dp[j-1][!f]+a[j]);
                    dp[j][f]=max(dp[j][f],dp[j-1][!f]*a[j]);
                    dp[j][f]=max(dp[j][f],dp[j-1][!f]-a[j]);
                }else{  
                    dp[j][f]=min(dp[j-1][f]*a[j],dp[j-1][f]-a[j]);
                    dp[j][f]=min(dp[j][f],dp[j-1][f]+a[j]);
                    dp[j][f]=min(dp[j][f],dp[j-1][!f]+a[j]);
                    dp[j][f]=min(dp[j][f],dp[j-1][!f]*a[j]);
                    dp[j][f]=min(dp[j][f],dp[j-1][!f]-a[j]);
                }   
            }
        }
        cout<<dp[n-1][0]<<"\n";
    }
    return 0;
}

