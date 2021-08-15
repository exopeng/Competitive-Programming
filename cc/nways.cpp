#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
using namespace std::chrono;

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
const int MAXN = 2e6+5;
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
ll fact[MAXN];
ll inv[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=1;
    for(int i=1;i<=MAXN;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=binpow(fact[i],MOD-2,MOD);
    }
    int t;
    cin>>t;
    //auto start = high_resolution_clock::now();

    for(int i=0;i<t;i++){
    	ll n,k;
        cin>>n>>k;
        ll fs=((k+n+1)*fact[k+n]) % MOD;
        fs=(fs*((inv[k]*inv[n])%MOD))%MOD;
        fs=(2*n*((fs-k*k-3*k-2+MOD*1000000)%MOD))%MOD;
        ll dv=((binpow(k+1,MOD-2,MOD)*binpow(k+2,MOD-2,MOD)))%MOD;
        cout<<(n+fs*dv)%MOD<<"\n";
        /*
        ll as=n;
        for(int j=1;j<n;j++){
            as=(as+((2*(n-j)*fact[k+j])%MOD)*((inv[j]*inv[k])%MOD))%MOD;
        }
        
        cout<<as<<"\n";
        */
    }
    /*
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    // To get the value of duration use the count()
    // member function on the duration object
    cout << duration.count() << endl;
    */
    return 0;
}

