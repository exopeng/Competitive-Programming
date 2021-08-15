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
int a[MAXN];
//# of element j after or at index i
int geq[MAXN+1][MAXN+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        ll as=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            geq[n-1][j]=0;
        }
        geq[n-1][a[n-1]]=1;
        for(int j=n-2;j>-1;j--){
            for(int f=1;f<=n;f++){
                geq[j][f]=geq[j+1][f];
                if(a[j]==f){
                    geq[j][f]++;
                }
            }
        }
        for(int j=0;j<n;j++){
            ll ct=0;
            for(int f=j-1;f>-1;f--){
                if(a[f]==a[j]){
                    as+=ct;
                }
                ct+=geq[j+1][a[f]];
            }
        }
        cout<<as<<'\n';
    }
    return 0;
}

