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
int arr[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    Tree<int> ost;
    ll inv=0;
    ll as=0;
    for(int i=0;i<n;i++){
        int curr=0;
        cin>>curr;
        if(i){
            as+=ost.size()-ost.order_of_key(curr);
        }
        arr[i]=curr;
        ost.is(curr);
    }
    as%=2;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        as=(as+1)%2;
        cout<<as<<"\n";
    }
    return 0;
}

