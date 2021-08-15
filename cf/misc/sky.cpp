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
const int MAXN = 5e5+10;
//store test cases here
/*


*/
ll m[MAXN];
int ix[MAXN];
int rx[MAXN];
ll dp[MAXN][2];
int as[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    vector<pii> ts;
    for(int i=0;i<n;i++){
        while(!ts.empty()&&ts[ts.size()-1].f>=m[i]){
            ts.pop_back();
        }
        if(ts.empty()){
            ix[i]=-1;
        }else{
            ix[i]=ts[ts.size()-1].s;
        }
        ts.pb(mp(m[i],i));
    }
    dp[0][0]=m[0];
    for(int i=1;i<n;i++){
        if(m[i]>=m[i-1]){
            dp[i][0]=dp[i-1][0]+m[i];
        }else{
            if(ix[i]==-1){
            dp[i][0]=(i-ix[i])*m[i];
            }else{
            dp[i][0]=dp[ix[i]][0]+(i-ix[i])*m[i];
            }
        }
    }
    ts.clear();
    for(int i=n-1;i>-1;i--){
        while(!ts.empty()&&ts[ts.size()-1].f>=m[i]){
            ts.pop_back();
        }
        if(ts.empty()){
            rx[i]=n;
        }else{
            rx[i]=ts[ts.size()-1].s;
        }
        ts.pb(mp(m[i],i));
    }
    dp[n-1][1]=m[n-1];
    for(int i=n-2;i>-1;i--){
        if(m[i]>=m[i+1]){
            dp[i][1]=dp[i+1][1]+m[i];
        }else{
            dp[i][1]=dp[rx[i]][1]+(rx[i]-i)*m[i];
        }
    }
    ll mx=dp[0][1];
    int it=0;
    for(int i=0;i<n;i++){
        if(dp[i][0]+dp[i+1][1]>mx){
            mx=dp[i][0]+dp[i+1][1];
            it=i+1;
        }
    }
    ll mn=2*INF;
    for(int i=it-1;i>-1;i--){
        as[i]=min(mn,m[i]);
        mn=min(mn,m[i]);
    }       
    mn=2*INF;
    for(int i=it;i<n;i++){
        as[i]=min(mn,m[i]);
        mn=min(mn,m[i]);
    }
    for(int i=0;i<n;i++){
        cout<<as[i]<<" ";
    }
    cout<<'\n';
    return 0;
}

