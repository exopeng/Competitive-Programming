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
const long long INF = 1e9;
const long long MOD = 998244353;
const int MAXN = 1e3+5;
//store test cases here
/*


*/
string gs[3]={"DRAW","ALICE","BOB"};
int dp[MAXN][MAXN][2][2];
int rec(int a,int b,bool rev,bool md){
    if(dp[a][b][rev][md]!=INF){
        return dp[a][b][rev][md];
    }
    if(b==0&&a>0){
        dp[a][b][rev][md]=1-rec(a-1,b+1,0,md);
    }else if(!rev&&b!=0){
        dp[a][b][rev][md]=-1*rec(a,b,1,md);
    }
    if(!md){
        dp[a][b][rev][md]=min(dp[a][b][rev][md],1-rec(a,b,0,1));
    }
    if(b!=0){
        dp[a][b][rev][md]=min(dp[a][b][rev][md],1-rec(a,b-1,0,md));
    }
    return dp[a][b][rev][md];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<MAXN;j++){
            for(int f=0;f<2;f++){
                for(int m=0;m<2;m++){
                    dp[i][j][f][m]=INF;
                }
            }
        }
    }
    dp[0][0][0][1]=dp[0][0][1][1]=0;
    for(int i=0;i<t;i++){
        int n;
        string s;
        cin>>n>>s;
        int ct0=0;
        int ct1=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='0'&&s[n-1-i]=='0'){
                ct0++;
            }else if(s[i]=='0'&&s[n-1-i]=='1'||
                s[i]=='1'&&s[n-1-i]=='0'){
                ct1++;
            }
        }
        int g=0;
        if(n%2&&s[n/2]=='0'){
            rec(ct0,ct1,0,0);
            if(dp[ct0][ct1][0][0]<0){
                g=1;
            }else if(dp[ct0][ct1][0][0]==0){
                g=0;
            }else{
                g=2;
            }
        }else{
            rec(ct0,ct1,0,1);
            if(dp[ct0][ct1][0][1]<0){
                g=1;
            }else if(dp[ct0][ct1][0][1]==0){
                g=0;
            }else{
                g=2;
            }
        }
        cout<<gs[g]<<"\n";
    }    
    return 0;
}

