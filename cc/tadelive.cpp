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
ll ans=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,y;
    cin>>n>>x>>y;
    set<pair<int,pii>,greater<pair<int,pii>> > mt;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        mt.is(mp(m,mp(0,i)));
    }
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        mt.is(mp(m,mp(1,i)));
    }
    set<int> tk;
    for(auto it=mt.begin();it!=mt.end();it++){
        if(it->s.f==0){
            if(x&&tk.find(it->s.s)==tk.end()){
                ans+=it->f;
                x--;
                tk.is(it->s.s);
            }
        }else{
            if(y&&tk.find(it->s.s)==tk.end()){
                ans+=it->f;
                y--;
                tk.is(it->s.s);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

