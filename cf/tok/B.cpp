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
const int MAXN = 5e5;
//store test cases here
/*


*/
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        a[n+1]=0;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        ll as=0;
        for(int j=1;j<=n;j++){
            if(a[j]>max(a[j-1],a[j+1])){
                as+=a[j]-max(a[j-1],a[j+1]);
                a[j]=max(a[j-1],a[j+1]);
            }
        }
        ll to=0;
        for(int j=1;j<=n;j++){
            to+=abs(a[j]-a[j-1]);
        }
        to+=a[n];
        cout<<to+as<<"\n";
    }
    return 0;
}

