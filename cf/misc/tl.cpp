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
const int MAXN = 3e6;
//store test cases here
/*


*/
//store number of nodes with 0,1,and 3 childan
ll dp[MAXN][3];
//lol guessforces
ll as[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1][0]=1;
    for(int i=2;i<MAXN;i++){
        dp[i][0]=(2*dp[i-1][1]+dp[i-1][0])%MOD;
        dp[i][1]=(dp[i-1][0]);
        dp[i][2]=(dp[i-1][1]+dp[i-1][2])%MOD;
        as[i]=(dp[i][2]-dp[i-1][2]+as[max(0,i-3)]+MOD)%MOD;
        if(i<10){
            //cout<<as[i]<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<'\n';
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int n;cin>>n;
        cout<<(4*as[n])%MOD<<'\n';
    }
    return 0;
}

