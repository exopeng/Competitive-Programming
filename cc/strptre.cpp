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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
        ll tp=0;
        for(int f=1;f<=n;f++){
            tp=(tp+binpow(2,f,MOD)*(1+(f-1)/2))%MOD;
        }
        ll lp=(binpow(2,2*n+2,MOD)-binpow(2,n+2,MOD)-binpow(2,n+1,MOD)+2+5*MOD)%MOD;
        lp=binpow(lp,MOD-2,MOD);
        cout<<((tp*lp)%MOD)<<"\n";
    }
    return 0;
}

