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
const int MAXN = 4e5;
//store test cases here
/*


*/
set<int,greater<int>> adj[MAXN];
set<int> mt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].is(b),adj[b].is(a);
    }
    int q;cin>>q;
    int mx=0;
    for(int i=1;i<=n;i++){
        if(*adj[i].begin()<i){
            mt.is(i);
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            adj[b].is(c),adj[c].is(b);
            if(b>*adj[b].begin()){
                mt.is(b);
            }else{
                mt.erase(b);
            }
            if(c>*adj[c].begin()){
                mt.is(c);
            }else{
                mt.erase(c);
            }
        }else if(a==2){
            cin>>b>>c;
            adj[b].erase(c),adj[c].erase(b);
            if(b>*adj[b].begin()){
                mt.is(b);
            }else{
                mt.erase(b);
            }
            if(c>*adj[c].begin()){
                mt.is(c);
            }else{
                mt.erase(c);
            }
        }else{
            cout<<(int)(mt.size())<<'\n';
        }
    }
    return 0;
}

