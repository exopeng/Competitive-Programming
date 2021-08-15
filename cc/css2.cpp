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
map<int,vector<pair<int,pii>>> id[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        id[a][b].pb(mp(d,mp(i,c)));
    }
    for(int i=1;i<=1e6;i++){
        for(auto it=id[i].begin();it!=id[i].end();it++){
            sort(id[i][it->f].begin(),id[i][it->f].end(),greater<pair<int,pii>>());
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<id[a][b][0].s.s<<"\n";
    }
    return 0;
}

