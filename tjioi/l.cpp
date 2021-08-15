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
const int MAXN = 1e3+5;
//store test cases here
/*


*/
int n,m;
int c[MAXN];
//subset rep the range
int sub[MAXN];
//next occurence of each color
int nc[MAXN][10];
//max number of boxes with color subset j ending on index i
int dp[MAXN][1024];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            nc[i][j]=-1;
        }
    }
    int nd=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        c[i]--;
        nd|=(int)pow(2,c[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nc[i][c[j]]==-1){
                nc[i][c[j]]=j;
                if(c[j]==c[i]){
                    for(int f=i;f<j;f++){
                        sub[i]|=(int)pow(2,c[f]);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(nc[i][c[i]]!=-1){
            dp[nc[i][c[i]]][sub[i]]=nc[i][c[i]]-i+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<1024;j++){
            if(dp[i][j]){
                for(int f=i+1;f<n;f++){
                    if(c[f]!=c[i]&&nc[f][c[f]]!=-1){
                        dp[nc[f][c[f]]][j|sub[f]]=
                        max(dp[nc[f][c[f]]][j|sub[f]], dp[i][j]+nc[f][c[f]]-f+1);
                    }
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,dp[i][nd]);
    }
    if(mx){
        cout<<mx<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}

