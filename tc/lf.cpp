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
double a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,m;cin>>n>>m;
        vector<int> as;
        as.pb(n),as.pb(m),as.pb(min(n,m));
        int tot=1;
        sort(as.begin(),as.end());
        for(int j=1;j>-1;j--){
            if(as[j]==as[j+1]){
                tot++;
                continue;
            }
            break;
        }
        cout<<as[2]<<" "<<tot<<'\n';
    }
    return 0;
}

