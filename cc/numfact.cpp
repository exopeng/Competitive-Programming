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
        map<int,int> ps;
        cin>>n;
        for(int j=0;j<n;j++){
            int f;
            cin>>f;
            int l=f;
            for(int m=2;m*m<=l;m++){
                while(f%m==0){
                    f/=m;
                    ps[m]++;
                }
            }
            if(f!=1){
                ps[f]++;
            }
        }
        ll ms=1;
        for(auto it=ps.begin();it!=ps.end();it++){
            ms*=(it->s+1);
        }
        cout<<ms<<"\n";
    }
    return 0;
}

