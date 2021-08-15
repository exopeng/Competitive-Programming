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
int ct[3][MAXN];
int ps[3][MAXN];
int dp[3][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for(int i=0;i<n;i++){
        ct[s[i]-65][i]++;
        if(i){
            ct[0][i]+=ct[0][i-1];
            ct[1][i]+=ct[1][i-1];
            ct[2][i]+=ct[2][i-1];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            if(j){
                ps[i][j]=ps[i][j-1];
            }
            if(ct[i][j]>=ct[(i+1)%3][j]&&ct[i][j]>=ct[(i+2)%3][j]){
                ps[i][j]++;
            }
        }
    }
    //when less than k from n, can transition directly to n
    dp[0][k-1]=ps[0][k-1];
    dp[1][k-1]=ps[1][k-1];
    dp[2][k-1]=ps[2][k-1];
    for(int i=k-1;i<n;i++){
        for(int j=0;j<3;j++){
            dp[j][i+1]=max(dp[j][i+1],dp[j][i]+ps[j][i+1]-ps[j][i]);
            for(int f=0;f<3;f++){
                if(i+k>=n){
                    dp[f][n-1]=max(dp[f][n-1],dp[j][i]+ps[f][n-1]-ps[f][i]);
                }else{
                    dp[f][i+k]=max(dp[f][i+k],dp[j][i]+ps[f][i+k]-ps[f][i]);
                }
            }
        }
    }
    cout<<max(max(dp[0][n-1],dp[1][n-1]),dp[2][n-1])<<'\n';
}

