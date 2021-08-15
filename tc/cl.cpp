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
const int MAXN = 2e3;
//store test cases here
/*


*/
int mn[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mn[i][j];
            if(i!=0){
                mn[i][j]=min(mn[i][j],mn[i-1][j]);
            }
            if(j!=0){
                mn[i][j]=min(mn[i][j],mn[i][j-1]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        cout<<mn[a][b]<<'\n';
    }

}

