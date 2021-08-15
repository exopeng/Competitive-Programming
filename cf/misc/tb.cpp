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
ll sm[MAXN];
vector<ll> ps;
ll hgs[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>sm[i];
        sm[i+n]=sm[i];
        ps.pb(0);
        ps[i]=sm[i];
        hgs[i]=(1+sm[i])*(sm[i])/2;
        if(i){
            ps[i]+=ps[i-1];
            hgs[i]+=hgs[i-1];
        }
    }
    for(int i=n;i<2*n;i++){
        ps.pb(0);
        ps[i]=ps[i-1]+sm[i-n];
        hgs[i]=hgs[i-1]+(1+sm[i-n])*(sm[i-n])/2;
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        ll hg=0;
        int ix=prev(ub(ps.begin(),ps.end(),ps[i]+x-1))-ps.begin();
        ll rem=x-(ps[ix]-ps[i]+1);
        hg+=hgs[ix]-hgs[i]+sm[i]+(1+rem)*rem/2;
        mx=max(mx,hg);
    }
    
    for(int i=n;i<2*n;i++){
        ll hg=0;
        //check if it's the beginning
        int ix=(lb(ps.begin(),ps.end(),ps[i]-x+1))-ps.begin();
        ll rem=x-(ps[i]-ps[ix]);
        hg+=hgs[i]-hgs[ix]+((sm[ix]-rem+1+sm[ix])*rem)/2;
        mx=max(mx,hg);
        //cout<<ix<<" "<<rem<<"\n";
    }
    cout<<mx<<'\n';
    return 0;
}

