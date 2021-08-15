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
const int MAXN = 2e6;
//store test cases here
/*


*/
int n;
int dp[MAXN][2][2];
char a[MAXN];
void rec(int i,int j,int f){
    if(dp[i][j][f]){
        return;
    }
    dp[i][j][f]=1;
    //f=going to the right
    if(f){
        if(i!=n){
            if(a[i+1]!=j){
                rec(i+1,!j,f);
                dp[i][j][f]+=dp[i+1][!j][f];
            }
        }
    }else{
        if(i!=0){
            if(a[i]==j){
                rec(i-1,!j,f);
                dp[i][j][f]+=dp[i-1][!j][f];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                for(int f=0;f<2;f++){
                    dp[i][j][f]=0;
                }
            }
        }
        string s;
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='L'){
                a[i]=0;
            }else{
                a[i]=1;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                for(int f=0;f<2;f++){
                    rec(i,j,f);
                }
            }
        }
        for(int i=0;i<=n;i++){
            //cout<<dp[i][0][0]<<" "<<dp[i][0][1]<<"\n";
        }
        for(int i=0;i<=n;i++){
            cout<<dp[i][0][1]+dp[i][0][0]-1;
            if(i==n){
                cout<<"\n";
            }else{
                cout<<" ";
            }
        }
    }
    return 0;
}

