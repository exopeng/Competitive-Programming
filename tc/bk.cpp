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
struct compare {
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
          if (a.f[0] < b.f[0]) return true;
          else if ( (a.f[0] == b.f[0]) && (a.s < b.s) ) return true;
          else return false;
        }   
    };
vector<pair<string,int>> bk;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string a;
        int b;
        cin>>a>>b;
        bk.pb(mp(a,b));
    }
    sort(bk.begin(),bk.end(),compare());
    for(int i=0;i<n;i++){
        cout<<bk[i].f<<"\n";
    }
    return 0;
}

