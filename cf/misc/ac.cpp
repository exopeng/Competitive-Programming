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
const int MAXN = 5e3+5;
//store test cases here
/*


*/
int n;
vector<int> oc,uc;
int dp[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a){
            oc.pb(i);
        }else{
            uc.pb(i);
        }
    }
    for(int i=0;i<=oc.size();i++){
        for(int j=0;j<=uc.size();j++){
            dp[i][j]=INF;
        }
    }
    //dp[i][j]=min time after having paired the first i-1 occ after considering the first j unocc spots
    //dp[i+1][j+1]=min(it,dp[i][j]+abs(oc[i]-uc[j])
    //dp[i][j+1]=min(dp[i][j],it);
    dp[0][0]=0;
    //get rid of impossible states
    for(int i=0;i<=oc.size();i++){
        for(int j=0;j<uc.size();j++){
            if(dp[i][j]==INF){
                continue;
            }
            if(i!=oc.size()){
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(oc[i]-uc[j]));
            }
            //have to go all the way because last taken ending pos not not be oc.size()-1
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
        }
    }
    cout<<dp[oc.size()][uc.size()]<<"\n";
    return 0;
}

