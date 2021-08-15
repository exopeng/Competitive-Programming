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
const long long MOD = 998244353;
const int MAXN = 2e5;
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
ll fc[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    fc[0]=1;
    for(int i=1;i<MAXN;i++){
        fc[i]=(fc[i-1]*i)%MOD;
    }
    for(int i=0;i<t;i++){
        ll n;
        cin>>n;
        string s;cin>>s;
        ll x=0;
        ll y=0;
        int cu=0;
        for(int j=0;j<n;j++){
            if(s[j]=='0'){
                x+=cu%2;
                y+=cu/2;
                cu=0;
            }else{
                cu++;
            }
        }
        if(cu){
            x+=cu%2;
            y+=cu/2;
        }
        //cout<<y<<" "<<x<<'\n';
        cout<<(((fc[n-x-y]*binpow(fc[y],MOD-2,MOD))%MOD)*binpow(fc[n-x-2*y],MOD-2,MOD))%MOD<<'\n';
    }
    return 0;
}

