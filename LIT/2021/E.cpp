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
const int MAXN = 2e5+100;
//store test cases here
/*


*/
ll binpow(ll a,ll b,ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll dp[MAXN];
int a[MAXN];
bool bk[MAXN];
ll mk[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        a[b]++;
        bk[b]=1;
    }
    for(int i=1;i<=2*n+99;i++){
        a[i]+=a[i-1];
    }
    ll cu=0;
    //check edge cases
    //check landing on yourself
    for(int i=1;i<=n;i++){
        cu=(cu+mk[i]+(ll)1e9*MOD)%MOD;
        if(bk[i]){
            continue;
        }
        dp[i]=cu;
        if(i==1){
            dp[i]=1;
        }
        ll pb=(dp[i]*binpow(r-l+1-(a[i+r]-a[i+l-1]),MOD-2,MOD))%MOD;
        if(l==0){
            pb=(dp[i]*binpow(r-(a[i+r]-a[i+l]),MOD-2,MOD))%MOD;
        }
        mk[i+l]=(mk[i+l]+pb)%MOD;
        if(l==0&&r){
            mk[i+1]=(mk[i+1]+pb)%MOD;
        }
        mk[i+r+1]=((mk[i+r+1]-pb)+(ll)1e9*MOD)%MOD;
    }
    for(int i=1;i<=n;i++){
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n]<<'\n';
    return 0;
}

