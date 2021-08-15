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
const int MAXN = 2e2+1;
//store test cases here
/*


*/
int r,g,b;
ll dp[MAXN][MAXN][MAXN];
int rs[MAXN],gs[MAXN],bs[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>g>>b;
    for(int i=0;i<r;i++){
        cin>>rs[i];
    }
    for(int i=0;i<g;i++){
        cin>>gs[i];
    }
    for(int i=0;i<b;i++){
        cin>>bs[i];
    }
    sort(rs,rs+r,greater<int>());
    sort(gs,gs+g,greater<int>());
    sort(bs,bs+b,greater<int>());
    for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
            for(int f=0;f<=b;f++){
                if(i){
                    dp[i][j][f]=max(dp[i][j][f],dp[i-1][j][f]);
                }
                if(j){
                    dp[i][j][f]=max(dp[i][j][f],dp[i][j-1][f]);
                }
                if(f){
                    dp[i][j][f]=max(dp[i][j][f],dp[i][j][f-1]);
                }
                if(i<r&&f<b){
                    dp[i+1][j][f+1]=max(dp[i+1][j][f+1],dp[i][j][f]+rs[i]*bs[f]);
                }
                if(i<r&&j<g){
                    dp[i+1][j+1][f]=max(dp[i+1][j+1][f],dp[i][j][f]+rs[i]*gs[j]);
                }
                if(f<b&&j<g){
                    dp[i][j+1][f+1]=max(dp[i][j+1][f+1],dp[i][j][f]+bs[f]*gs[j]);
                }
            }
        }
    }
    cout<<dp[r][g][b]<<'\n';
    return 0;
}

