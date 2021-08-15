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
const int MAXN = 1e3;
//store test cases here
/*


*/
int g[MAXN][MAXN];
multiset<int,greater<int>> rs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int ct=0;
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]){
                ct++;
            }else{
                rs.is(ct);
                ct=0;
            }
        }
        rs.is(ct);
    }
    int as=0;
    for(auto it=rs.begin();it!=rs.end();it++){
        if(k){
            as+=*it;
            k--;
        }
    }
    cout<<as<<'\n';
    return 0;
}

