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
ll fac[MAXN];
int ct[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }
    for(int i=0;i<n;i++){
        string s;
        int d;cin>>s>>d;
        ct[d]++;
    }
    ll tot=1;
    for(int i=1;i<=1e6;i++){
        tot=(tot*fac[ct[i]])%MOD;
    }
    cout<<tot<<'\n';
}

