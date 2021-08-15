#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

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
set<ll> ct;
vector<ll> cl;
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
    auto start = high_resolution_clock::now();
    for(int i=0;i<=18;i++){
        for(int f=i+1;f<=18;f++){
            for(int j=f+1;j<=18;j++){
                for(ll m=0;m<10;m++){
                    ll ns=m*binpow(10,18-i);
                    for(ll l=0;l<10;l++){
                        ns+=l*binpow(10,18-f);
                        for(ll c=0;c<10;c++){
                            ns+=c*binpow(10,18-j);
                            ct.is(ns);
                            ns-=c*binpow(10,18-j);
                        }
                        ns-=l*binpow(10,18-f);
                    }
                }
            }
        }
    }
    for(auto it=ct.begin();it!=ct.end();it++){
        cl.pb(*it);
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll l,r;
        cin>>l>>r;
        auto it=lb(cl.begin(),cl.end(),r+1);
        auto it1=lb(cl.begin(),cl.end(),l);
        cout<<(it-it1)<<'\n';
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //cout << duration.count() << endl;
    return 0;
}

