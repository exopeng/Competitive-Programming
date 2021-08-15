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
ll gcd(ll a,ll b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
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
    vector<int> p;
    vector<int> ip(1e6+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i<=1e6;i++){
        if(ip[i]&&(ll)i*i<=1e6){
            for(int j=i*i;j<=1e6;j+=i)
                ip[j]=false;
        }
        if(ip[i]){
            p.pb(i);
        }
    }
    int t;cin>>t;
    for(int i=0;i<t;i++){
        ll a;cin>>a;
        bool g=false;
        for(int j=0;j<p.size();j++){
            if(binpow(a,p[j],10)==binpow(p[j],a,10)){
                cout<<p[j]<<"\n";
                g=true;
                break;
            }
        }
        if(!g){
            cout<<-1<<'\n';
        }
    }
    
    return 0;
}

