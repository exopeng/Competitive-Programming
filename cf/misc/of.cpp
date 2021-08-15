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
const long long INF = 1e18;
const long long MOD = 998244353;
const int MAXN = 2e5;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        vector<pll> x;
        vector<ll> a,as,pt,sm;
        for(int j=0;j<n;j++){
            int af;
            cin>>af;
            a.pb(af);
            sm.pb(a[j]);
            if(j){
                sm[j]+=sm[j-1];
            }
        }
        for(int j=0;j<m;j++){
            int af;
            cin>>af;
            x.pb(mp(af,j));
            pt.pb(INF);
            as.pb(0);
        }
        if(sm[n-1]<=0){
            sort(x.begin(),x.end());
            for(ll j=0;j<n;j++){
                int it=(ub(x.begin(),x.end(),mp(sm[j],INF))-x.begin());
                if(it){
                    pt[it-1]=min(pt[it-1],j+1);
                }
            }
        }else{
            for(int j=0;j<n;j++){
                int it=(lb(x.begin(),x.end(),mp(sm[j],(ll)0))-x.begin());
                if(it<m){
                    ll at=(n*(x[it].f-sm[j])/sm[n-1]+j+1);
                    if((x[it].f-sm[j])%sm[n-1]){
                        at+=n;
                    }
                    pt[it]=min(pt[it],at);
                }
            }
        }
        ll mn=INF;
        for(int j=0;j<m;j++){
            mn=min(mn,pt[j]);
            if(mn!=INF){
                as[x[j].s]=mn;
            }else{
                as[x[j].s]=-1;
            }
        }
        for(int j=0;j<m;j++){
            if(as[j]>0){
                as[j]--;
            }
            cout<<as[j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

