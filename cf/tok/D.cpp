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
const int MAXN = 3e3;
//store test cases here
/*


*/
int n;
vector<int> adj[MAXN];
int d[MAXN];
vector<pii> et;
void qu(int v){
    cout<<"? "<<v<<"\n";
    cout.flush();
    for(int i=1;i<=n;i++){
        cin>>d[i];
        if(d[i]==1){
            et.pb(mp(v,i));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cout<<"? 1"<<"\n";
    cout.flush();
    vector<int> od,ev;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        if(d[i]%2){
            od.pb(i);
        }else{
            ev.pb(i);
        }
    }
    if(ev.size()==od.size()){
        for(int i=1;i<=n;i++){
            if(d[i]==1){
                et.pb(mp(1,i));
            }
        }
        for(int i=1;i<ev.size();i++){
            qu(ev[i]);
        }
    }else{
        if(ev.size()<od.size()){
            swap(ev,od);
        }
        for(int i=0;i<od.size();i++){
            qu(od[i]);
        }
    }
    cout<<'!'<<'\n';
    for(int i=0;i<n-1;i++){
        cout<<et[i].f<<" "<<et[i].s<<"\n";
    }
    cout.flush();
    return 0;
}

