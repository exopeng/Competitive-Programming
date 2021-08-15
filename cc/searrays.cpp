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
ll ft[MAXN];
ll ift[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    ft[0]=1;
    ift[0]=1;
    for(int i=1;i<MAXN;i++){
        ft[i]=(ft[i-1]*i)%MOD;
        ift[i]=binpow(ft[i],MOD-2,MOD);
    }
    for(int i=0;i<t;i++){
    	int n,k;
        ll as=0;
        cin>>n>>k;
        for(int j=0;j<=n/k;j++){
            ll ts=(ft[n-j*k+j]*ift[j])%MOD;
            ts=(ts*ift[n-j*k])%MOD;
            as=(as+ts)%MOD;
        }
        cout<<as<<"\n";
    }
    return 0;
}

