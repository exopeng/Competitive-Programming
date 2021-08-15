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
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        int mn=INF;
        int mx=0;
        int p1=0;
        int p2=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
            if(a[j]<mn){
                mn=a[j];
                p1=j;
            }
            if(a[j]>mx){
                mx=a[j];
                p2=j;
            }
        }
        int ans=INF;
        if(p1<p2){
            ans=p1+n-1-p2+2;
            ans=min(ans,p2+1);
            ans=min(ans,n-1-p1+1);
        }else{
            ans=min(ans,p1+1);
            ans=min(ans,p2+n-1-p1+2);
            ans=min(ans,n-1-p2+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

