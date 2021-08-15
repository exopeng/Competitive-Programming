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
ll binpow(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        m++;
        ll x=0;
        string ts,ps,ls;
        while(n!=0){
            ts+=to_string(n%2);
            n/=2;
        }
        while(m!=0){
            ps+=to_string(m%2);
            m/=2;
        }
        while(ts.size()<ps.size()){
            ts+="0";
        }
        while(ts.size()>ps.size()){
            ps+="0";
        }
        //cout<<ts<<"\n"<<ps<<'\n';
        for(int j=ts.size()-1;j>-1;j--){
            if(ts[j]==ps[j]){
                continue;
            }
            if(ts[j]<ps[j]){
                x+=pow(2,j);
            }else{
                break;
            }
        }
        cout<<x<<'\n';
    }
    return 0;
}

