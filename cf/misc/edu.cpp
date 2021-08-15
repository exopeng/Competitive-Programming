#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
const long long INF = 2e15+10;
const long long MOD = 1e9+7;
const int MAXN = 2e6+5;
//store test cases here
/*


*/
int n,c;
int a[MAXN];
int b[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>c;
        ll mn=INF;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n-1;j++){
            cin>>b[j];
        }
        ll ds=0;
        ll curr=0;
        for(int j=0;j<n;j++){
            if(curr>=c){
                mn=min(ds,mn);
                break;
            }else{
                mn=min(mn,(ll)ceil((c-(double)curr)/a[j])+ds);
            }
            if(j!=n-1&&curr<b[j]){
                ds+=(ll)ceil((b[j]-(double)curr)/a[j]);
                curr+=(ll)ceil((b[j]-(double)curr)/a[j])*a[j];
            }
            curr-=b[j];
            ds++;
        }
        cout<<mn<<"\n";
    }
    return 0;
}

