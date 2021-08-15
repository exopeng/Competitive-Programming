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
const int MAXN = 2e3;
//store test cases here
/*


*/
int n;
string s;
int c[MAXN];
vector<int> adj[MAXN];
bool g=true;
void dfs(int v,int ci){
    if(!c[v]){
        c[v]=ci;
        for(int i=0;i<adj[v].size();i++){
            if(c[adj[v][i]]==ci){
                g=false;
                return;
            }
            dfs(adj[v][i],(ci%2)+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(s[j]>s[i]){
                adj[i].pb(j),adj[j].pb(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        dfs(i,1);
    }
    if(!g){
        cout<<"NO"<<'\n';
    }else{
        cout<<"YES"<<'\n';
        for(int i=0;i<n;i++){
            cout<<(c[i]-1);
        }
        cout<<'\n';
    }
    return 0;
}

