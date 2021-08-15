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
int t;
int dp[23][23][2];
set<pii> ts[23][23];
int x[2]={-1,1};
int y[2]={1,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<23;j++){
            for(int f=0;f<23;f++){
                dp[f][j][0]=INF;
                dp[f][j][1]=0;
                ts[f][j].clear();
            }
        }
        int g,e;
        cin>>g>>e;
        dp[g][e][0]=0,dp[g][e][1]=1;
        queue<pii> q;
        q.push(mp(g,e));
        while(!q.empty()){
            pii c=q.front();
            q.pop();
            if(c.f==2&&c.s==0||c.f==1&&c.s==0
                ||c.f==0&&c.s==1){
                if(dp[0][0][0]>dp[c.f][c.s][0]+1){
                    dp[0][0][0]=dp[c.f][c.s][0]+1;
                    dp[0][0][1]=dp[c.f][c.s][1];
                    ts[0][0].is(mp(c.f,c.s));
                }else if(dp[0][0][0]==dp[c.f][c.s][0]+1
                    &&ts[0][0].find(mp(c.f,c.s))
                    ==ts[0][0].end()){
                    dp[0][0][1]+=dp[c.f][c.s][1];
                    ts[0][0].is(mp(c.f,c.s));
                }
            }else{
                for(int j=0;j<2;j++){
                    int nx=c.f-x[j];
                    int ny=c.s-y[j];
                    if(nx>=0&&ny>=0&&nx<23&&ny<23){
                        if(dp[nx][ny][0]>dp[c.f][c.s][0]+1){
                            dp[nx][ny][0]=dp[c.f][c.s][0]+1;
                            dp[nx][ny][1]=dp[c.f][c.s][1];
                            q.push(mp(nx,ny));
                            ts[nx][ny].is(mp(c.f,c.s));
                        }else if(dp[nx][ny][0]==dp[c.f][c.s][0]+1
                            &&ts[nx][ny].find(mp(c.f,c.s))
                            ==ts[nx][ny].end()){
                            dp[nx][ny][1]+=dp[c.f][c.s][1];
                            ts[nx][ny].is(mp(c.f,c.s));
                        }
                    }   
                }
            }
        }
        cout<<dp[0][0][1]<<"\n";
    }
    return 0;
}

