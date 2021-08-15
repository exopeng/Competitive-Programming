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
const int MAXN = 2e6;
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
int ct[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        vector<pll> mt,ms;
        ll n,p;cin>>n>>p;
        for(int j=0;j<n;j++){
            int ks;cin>>ks;
            if(ct[ks]==0){
                mt.pb(mp(ks,0));
                ms.pb(mp(ks,0));
            }
            ct[ks]++;
        }
        for(int j=0;j<mt.size();j++){
            mt[j].s=ct[mt[j].f];
        }   
        sort(mt.begin(),mt.end()),sort(ms.begin(),ms.end());
        reverse(mt.begin(),mt.end()),reverse(ms.begin(),ms.end());
        //p=1 special?
        for(int j=mt.size()-2; j>-1;j--){
            if(mt[j].f-mt[j+1].f<=log(n)/log(p)){
                mt[j].s+=mt[j+1].s/binpow(p,mt[j].f-mt[j+1].f,MOD);
                ms[j].s=mt[j+1].s/binpow(p,mt[j].f-mt[j+1].f,MOD);
                mt[j+1].s-=binpow(p,mt[j].f-mt[j+1].f,MOD)*ms[j].s;
            }
        }
        //convert st all k's power < p
        ll as=0;
        for(int j=0;j<mt.size();j++){
            if(mt[j].s%2){
                if(ms[j].s){
                    mt[j+1].s+=binpow(p,(mt[j].f-mt[j+1].f),MOD);
                    continue;
                }
                as=binpow(p,mt[j].f,MOD);
                for(int f=j+1;f!=mt.size();f++){
                    as=(as-((mt[f].s*binpow(p,mt[f].f,MOD))%MOD)+MOD)%MOD;
                }
                break;
            }
            //if even give back tho?
        }
        cout<<as<<'\n';
        for(int j=0;j<mt.size();j++){
            ct[mt[j].f]=0;
        }
    }   
    return 0;
}

