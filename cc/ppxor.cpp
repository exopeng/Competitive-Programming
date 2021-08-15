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
ll dp[MAXN][34];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
        vector<vector<int>> a;
        vector<int> ts(34,0);
        for(int j=0;j<n;j++){
            a.pb(ts);
            int b;
            cin>>b;
            int ix=0;
            while(b!=0){
                a[j][ix]=b%2;
                b/=2;
                ix++;
            }
        }
        ll as=0;
        for(int j=0;j<34;j++){
            int ct=0;
            ll l1=0;
            for(int f=0;f<n;f++){
                ct+=a[f][j];
                dp[f][j]=0;
                if(f){
                    dp[f][j]=dp[f-1][j];
                }
                if(ct%2==0){
                    dp[f][j]++;
                }
                if(a[f][j]){
                    if(ct%2){
                        as+=pow(2,j)*(1+dp[f][j]);
                        l1=pow(2,j)*(1+dp[f][j]);
                    }else{
                        as+=pow(2,j)*(f+1-dp[f][j]);
                        l1=pow(2,j)*(f+1-dp[f][j]);
                    }
                }else{
                    as+=l1;
                }
                
            }
        }
        cout<<as<<"\n";
    }
    return 0;
}

