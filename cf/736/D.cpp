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
ll a[MAXN];
ll md[MAXN][82];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
            for(ll f=2;f<=83;f++){
                md[j][f-2]=a[j]%f;
            }
        }
        int as=0;
        for(int j=0;j<82;j++){
            int ct=0;
            ll lt=0;
            for(int f=0;f<n;f++){
                if(md[f][j]==lt){
                    ct++;
                }else{
                    as=max(as,ct);
                    lt=md[f][j];
                    ct=1;
                }
            }
            as=max(as,ct);
        }
        cout<<as<<'\n';
    }
    return 0;
}

