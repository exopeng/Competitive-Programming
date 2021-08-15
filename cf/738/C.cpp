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
        vector<int> as;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        bool g=false;
        int ix=0;
        for(int j=1;j<n;j++){
            if(a[j]==0&&a[j+1]==1){
                g=true;
                ix=j;
            }
        }
        if(a[n]==0){
            g=true;
        }
        if(a[1]==1){
            g=true;
        }
        //starting at village n+1
        if(g){
            if(a[n]==0){
                for(int j=1;j<=n+1;j++){
                    as.pb(j);
                }
            }else if(a[1]==1){
                as.pb(n+1);
                for(int j=1;j<=n;j++){
                    as.pb(j);
                }
            }else{
                for(int j=1;j<ix;j++){
                    as.pb(j);
                }
                as.pb(ix),as.pb(n+1);
                for(int j=ix+1;j<=n;j++){
                    as.pb(j);
                }
            }
            for(int j=0;j<n+1;j++){
                cout<<as[j]<<' ';
            }
            cout<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}

