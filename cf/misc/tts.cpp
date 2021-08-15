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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        vector<pair<pii,int>> id;
        cin>>n;
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            id.pb(mp(mp(a,0),j));
            id.pb(mp(mp(b,1),j));
        }
        int cs=0;
        int mx=0;
        map<int,int> act;
        sort(id.begin(),id.end());
        for(int j=0;j<id.size();j++){
            if(id[j].f.s==0){
                act[id[j].s]=cs;
            }else{
                mx=max(mx,(int)act.size()-1+cs-act[id[j].s]);
                act.erase(id[j].s);
                cs++;
            }
        }
        cout<<n-mx-1<<"\n";
    }
    return 0;
}

