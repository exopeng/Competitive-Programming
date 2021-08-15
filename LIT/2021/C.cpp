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
const int MAXN = 55;
//store test cases here
/*


*/
int ex1,ey1,ex2,ey2;
char g1[MAXN][MAXN];
char g2[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN][MAXN];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x1,y1,x2,y2;

    cin>>n>>m>>x1>>y1>>x2>>y2>>ex1>>ey1>>ex2>>ey2;
    x1--,y1--,x2--,y2--,ex1--,ey1--,ex2--,ey2--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int f=0;f<n;f++){
                for(int t=0;t<m;t++){
                    dp[i][j][f][t]=2*INF;
                }
            }
        }
    }
    dp[x1][y1][x2][y2]=0;
    queue<pair<pii,pii>> q;
    q.push(mp(mp(x1,y1),mp(x2,y2)));
    while(!q.empty()){
        pair<pii,pii> c=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx1=max(0,min(n-1,c.f.f+dx[i]));
            int ny1=max(0,min(m-1,c.f.s+dy[i]));
            int nx2=max(0,min(n-1,c.s.f+dx[i]));
            int ny2=max(0,min(m-1,c.s.s+dy[i]));
            if(g1[nx1][ny1]=='#'){
                nx1-=dx[i],ny1-=dy[i];
            }
            if(g2[nx2][ny2]=='#'){
                nx2-=dx[i],ny2-=dy[i];
            }
            if(dp[nx1][ny1][nx2][ny2]>dp[c.f.f][c.f.s][c.s.f][c.s.s]+1){
                dp[nx1][ny1][nx2][ny2]=dp[c.f.f][c.f.s][c.s.f][c.s.s]+1;
                q.push(mp(mp(nx1,ny1),mp(nx2,ny2)));
            }
        }
    }
    if(dp[ex1][ey1][ex2][ey2]==2*INF){
        cout<<-1<<'\n';
    }else{
        cout<<dp[ex1][ey1][ex2][ey2]<<'\n';
    }
    return 0;
}

