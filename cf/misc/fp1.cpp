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
int dp[MAXN][MAXN];
int ds[MAXN];
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,k;cin>>n>>k;
        for(int j=0;j<n;j++){
            cin>>a[j];
            if(a[j]>j+1){
                ds[j]=INF;
            }else{
                ds[j]=j+1-a[j];
            }
        }
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++){
                dp[j][f]=INF;
            }
        }
        for(int j=0;j<n;j++){
            dp[j][0]=ds[j];
        }
        int as=INF;
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++){
                if(ds[f]==INF){
                    continue;
                }
                if(dp[f][j]!=INF){
                    for(int m=f-1;m>-1;m--){
                        if(a[m]<a[f]&&ds[m]<=ds[f]&&ds[m]!=INF){
                            dp[m][j+1]=min(dp[m][j+1],dp[f][j]);
                        }
                    }
                    if(j>=k-1){
                        as=min(as,dp[f][j]);
                    }
                }
            }
        }
        if(as==INF){
            as=-1;
        }
        cout<<as<<"\n";
    }
    return 0;
}

