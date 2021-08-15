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
const int MAXN = 3e6;
//store test cases here
/*


*/
int a[MAXN];
int n;
set<int> ps[MAXN];
int pt=0;
int mx(){
    for(int i=pt;i<=n;i++){
        if(ps[i].size()==0){
            pt=i;
            return i;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        pt=0;
        vector<int> at;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            ps[a[j]].is(j);
        }
        a[0]=-1;
        for(int j=1;j<=n;j++){
            if(!(a[j]==a[j-1]||a[j]==a[j-1]+1)){
                int mt=mx();
                while(ps[a[j-1]+1].size()){
                    int ix=*ps[a[j-1]+1].begin();
                    ps[a[j-1]+1].erase(ps[a[j-1]+1].begin());
                    a[ix]=mt;   
                    ps[mt].is(ix);
                    at.pb(ix);
                }
                ps[a[j]].erase(j);
                ps[a[j-1]+1].is(j);
                a[j]=a[j-1]+1;
                at.pb(j);
            }
        }
        for(int j=0;j<=n;j++){
            ps[j].clear();
        }
        cout<<at.size()<<'\n';
        for(int j=0;j<at.size();j++){
            cout<<at[j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

