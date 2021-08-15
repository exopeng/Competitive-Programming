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
const int MAXN = 2e5+100;
//store test cases here
/*


*/
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;cin>>n>>k;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        vector<pii> ts;
        vector<pii> tp;
        map<int,int> ct;
        for(int j=0;j<n/2;j++){
            if(a[j]>a[n-j-1]){
                swap(a[j],a[n-j-1]);
            }
            ts.pb(mp(a[j],a[n-j-1]));
            tp.pb(mp(a[n-j-1],a[j]));
            ct[a[j]+a[n-j-1]]++;
        }
        sort(tp.begin(),tp.end());
        sort(ts.begin(),ts.end());
        int mn=INF;
        for(int j=2;j<=2*k;j++){
            int cur=n-2*ct[j];
            cur/=2;
            //
            int it=(ts.end()-lb(ts.begin(),ts.end(),mp(j,0)));
            int ix=(lb(tp.begin(),tp.end(),mp(j-k,0))-tp.begin());
            cur+=it+ix;
            mn=min(mn,cur);
        }
        cout<<mn<<'\n';
    }
    return 0;
}

