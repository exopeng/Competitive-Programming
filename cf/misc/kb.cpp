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
const int MAXN = 2e2+5;
//store test cases here
/*


*/
int n,k,l;
int d[MAXN];
bool dp[MAXN][MAXN];
bool gs[MAXN][MAXN];
int p[MAXN];
bool rec(int i,int j){
    if(gs[i][j]){
        return dp[i][j];
    }
    gs[i][j]=true;
    if(i==n+1){
        return dp[i][j]=true;
    }
    if(d[i]+p[j]>l&&i!=0){
        return dp[i][j]=false;
    }
    dp[i][j]=max(rec(i+1,(j+1)%(2*k)),rec(i,(j+1)%(2*k)));
    return dp[i][j];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>l;
        for(int j=0;j<MAXN;j++){
            for(int f=0;f<MAXN;f++){
                gs[j][f]=false;
                dp[j][f]=false;
            }
        }
        for(int j=1;j<=n;j++){
            cin>>d[j];
        }
        for(int j=1;j<=k;j++){
            p[j]=p[j-1]+1;
        }
        for(int j=k+1;j<2*k;j++){
            p[j]=p[j-1]-1;
        }
        if(rec(0,0)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<'\n';
    }
    return 0;
}

