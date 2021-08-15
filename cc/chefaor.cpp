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
const int MAXN = 5e3+5;
//store test cases here
/*


*/
int a[MAXN];
ll dp[MAXN][MAXN][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,k;
    	cin>>n>>k;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=0;j<=k;j++){
            for(int f=0;f<=n;f++){
                dp[j][f][0]=dp[j][f][1]=0;
            }
        }
        //only xor individual, not the whole thing
        for(int j=1;j<=k;j++){
            for(int f=j;f<=n;f++){
                if(dp[j-1][f-1][0]+dp[j-1][f-1][1]+a[f]
                    >dp[j][f-1][0]+dp[j][f-1][1]|a[f]){
                    dp[j][f][1]=a[f];
                    dp[j][f][0]=dp[j-1][f-1][0]+dp[j-1][f-1][1];
                }else{
                    dp[j][f][1]=dp[j][f-1][1]|a[f];
                    dp[j][f][0]=dp[j][f-1][0];   
                }
                
            }
        }
        cout<<dp[k][n][0]<<" "<<dp[k][n][1]<<"\n";
    }
    return 0;
}

