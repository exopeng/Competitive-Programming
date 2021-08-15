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
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        sort(a,a+n);
        ll sd=0;
        for(int j=0;j<=n-2;j++){
            sd+=a[j];
        }
        double tp=0;
        if(sd%(n-1)){
            tp=((double)(sd%(n-1)))/(n-1);
        }
        tp+=(ll)(sd/(n-1));
        tp+=a[n-1];
        cout<<setprecision(15)<<tp<<'\n';
    }
    return 0;
}

