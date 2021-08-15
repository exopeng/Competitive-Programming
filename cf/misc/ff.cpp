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
const int MAXN = 5e5;
//store test cases here
/*


*/
ll dp[MAXN];
ll as=0;
ll h[MAXN];
ll w[MAXN];
ll ps[MAXN];
ll f[MAXN];
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
ll p2=binpow(2,MOD-2,MOD);
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
ll add(ll a,ll b){
    return (a+b)%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ps[i]=add(ps[i-1],w[i]);
    }
    vector<pii> st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&st[st.size()-1].f>h[i]){
            st.pop_back();
        }
        if(st.empty()){
            f[i]=0;
        }else{
            f[i]=st[st.size()-1].s;
        }
        st.pb(mp(h[i],i));
    }
    //mod out tho
    for(int i=1;i<=n;i++){
        if(h[i]>=h[i-1]){
            dp[i]=add(dp[i-1],mult(mult(h[i-1]+1,h[i-1]),mult(p2,w[i-1])));
        }else{
            dp[i]=add(dp[f[i]+1],mult(mult(ps[i-1]-ps[f[i]]+MOD,
                (h[i]+1)),mult(h[i],p2)));
        }
        as=add(as,mult(mult(mult(h[i]+1,h[i]),mult(p2,w[i]+1)),mult(w[i],p2)));
        as=add(as,mult(dp[i],w[i]));
    }
    cout<<as<<'\n';
    return 0;
}

