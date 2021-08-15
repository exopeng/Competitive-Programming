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
ll dp[101][101];
ll summ[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        for(int j=1;j<=n;j++){
            for(int f=1;f<=n;f++){
                dp[j][f]=0;
            }
        }
        for(int j=1;j<=n;j++){
            cin>>a[j];
            summ[j]=(summ[j-1]+a[j])%100;
        }
        for(int k=2;k<=n;k++){
            for(int j=1;j+k-1<=n;j++){
                dp[j][j+k-1]=INF;
                for(int e=j;e<=j+k-2;e++){
                    dp[j][j+k-1]=min(dp[j][j+k-1],((summ[e]-summ[j-1]+10000)%100)
                        *((summ[j+k-1]-summ[e]+10000)%100)
                        +dp[j][e]+dp[e+1][j+k-1]);
                }
            }
        }
        cout<<dp[1][n]<<"\n";
    }
    return 0;
}

