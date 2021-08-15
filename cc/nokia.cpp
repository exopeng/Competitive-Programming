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
int dp[33];
void dfs(int v){
    if(dp[v]){
        return;
    }
    if(v==2){
        dp[v]=2;
        return;
    }else if(v==1){
        dp[v]=0;
        return;
    }
    dfs(ceil(double(v)/2));
    dfs(v/2);
    dp[v]=v+dp[(int)ceil(double(v)/2)]+dp[v/2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,m;
        cin>>n>>m;
        int ub=((n+3)*n)/2;
        dfs(n+1);
        int lb=dp[n+1];
        if(m>=lb&&m<=ub){
            cout<<0<<"\n";
        }else if(m>=ub){
            cout<<m-ub<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}

