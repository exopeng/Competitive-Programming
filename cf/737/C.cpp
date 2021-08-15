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
const int MAXN = 3e5;
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
ll mult(ll a,ll  b){
    return (a*b)%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fc[0]=1;
    for(int j=1;j<MAXN;j++){
        fc[j]=(fc[j-1]*j)%MOD;
    }
    int t;cin>>t;
    for(int i=0;i<t;i++){
        ll n,k;cin>>n>>k;
        if(n%2){
            ll as=1;
            for(int j=0;j<=n-1;j+=2){
                as=(as+mult(fc[n],(mult(binpow(fc[j],MOD-2,MOD),binpow(fc[n-j],MOD-2,MOD)))))%MOD;
            }
            cout<<binpow(as,k,MOD)<<'\n';
        }else{
            ll as=0;
            for(int j=0;j<=n-2;j+=2){
                as=(as+mult(fc[n],(mult(binpow(fc[j],MOD-2,MOD),binpow(fc[n-j],MOD-2,MOD)))))%MOD;
            }
            ll at=0;
            for(int j=0;j<k;j++){
                at=(at+(mult(binpow(as,j,MOD),binpow(2,n*(k-j-1),MOD))))%MOD;
            }
            at=(at+binpow(as,k,MOD))%MOD;
            cout<<at<<'\n';
        }
    }
    return 0;
}

