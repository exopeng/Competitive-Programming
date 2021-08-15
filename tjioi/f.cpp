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
ll a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tree<int> ost;
    int n;
    cin>>n;
    ll as=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        as+=(ost.size()-ost.order_of_key(a[i]))*a[i];
        ost.is(a[i]);
    }
    ost.clear();
    for(int i=n-1;i>-1;i--){
        as+=(ost.order_of_key(a[i]))*a[i];
        ost.is(a[i]);
    }
    cout<<as<<"\n";
    return 0;
}

