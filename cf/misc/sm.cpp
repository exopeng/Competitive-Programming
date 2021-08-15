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
const int MAXN = 100;
//store test cases here
/*


*/
int n,m;
char g[MAXN][MAXN];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int gp[MAXN][MAXN];
int cu=1;
void dfs(int i,int j){
    if(gp[i][j]){
        return;
    }
    gp[i][j]=cu;
    for(int l=0;l<4;l++){
        if(i+dx[l]>=1&&i+dx[l]<=n
            && j+dy[l]>=1&&j+dy[l]<=m){
            if(g[i+dx[l]][j+dy[l]]!='#'){
                dfs(i+dx[l],j+dy[l]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        cu=1;
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                cin>>g[j][f];
                gp[j][f]=0;
            }
        }
        bool gs=true;
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                if(g[j][f]=='B'){
                     for(int l=0;l<4;l++){
                        if(j+dx[l]>=1&&j+dx[l]<=n
                            && f+dy[l]>=1&&f+dy[l]<=m){
                            if(g[j+dx[l]][f+dy[l]]=='.'){
                                g[j+dx[l]][f+dy[l]]='#';
                            }
                        }
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                if(g[j][f]!='#'){
                    if(!gp[j][f]){
                        cu++;
                        dfs(j,f);
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                if(g[j][f]=='G'){
                    if(gp[j][f]!=gp[n][m]){
                        gs=false;
                    }
                }else if(g[j][f]=='B'){
                    if(gp[j][f]==gp[n][m]){
                        gs=false;
                    }
                }
            }
        }
        if(gs){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}

