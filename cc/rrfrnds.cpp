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
bool adj[MAXN][MAXN];
int cp[MAXN];
int cv=1;
map<int,pii> ct;
int aj[MAXN];
void dfs(int v){
    if(!cp[v]){
        cp[v]=cv;
        for(int i=0;i<n;i++){
            if(adj[v][i]){
                dfs(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            adj[i][j]=s[j]-'0';
            aj[j]+=s[j]-'0';
        }
    }   
    for(int i=0;i<n;i++){
        if(!cp[i]){
            dfs(i);
            cv++;
        }
    }
    for(int i=0;i<n;i++){
        ct[cp[i]].f++;
        ct[cp[i]].s+=aj[i];
    }
    ll ans=0;
    for(auto it=ct.begin();it!=ct.end();it++){
        ans+=it->s.f*(it->s.f-1)-it->s.s;
    }
    cout<<ans<<"\n";
    return 0;
}

