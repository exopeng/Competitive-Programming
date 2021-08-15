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
const long long INF = 1e10;
const long long MOD = 1e9+7;
const int MAXN = 2e6;
//store test cases here
/*


*/
ll t[MAXN];
ll r[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>t[i];
        cin>>r[i];
    }
    ll lo=0;
    ll hi=INF;
    while(lo!=hi){
        ll md=(lo+hi)/2;
        ll sm=0;
        for(int j=0;j<n;j++){
            sm+=max((ll)0,(md-t[j])/r[j]);
        }
        if(sm>=x){
            hi=md;
        }else{
            lo=md+1;
        }
    }
    cout<<lo<<'\n';
}
