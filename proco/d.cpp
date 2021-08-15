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
const int MAXN = 1e3;
//store test cases here
/*


*/
int n,m;
//grid pos and speed and direction
//0 is north,1 east,2 south,3 west
map<pair<pii,pii>,int> ms;
bool g[MAXN][MAXN];
int vs[MAXN][MAXN];
int hs[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            g[i][j]=s[j-1]-'0';
            hs[i][j]=g[i][j]+hs[i][j-1];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            vs[i][j]=g[i][j]+vs[i-1][j];
        }
    }
    ms[mp(mp(1,1),mp(0,2))]=0;
    queue<pair<pii,pii>> q;
    q.push(mp(mp(1,1),mp(0,2)));
    bool g=false;
    while(!q.empty()){
        pair<pii,pii> ts=q.front();
        q.pop();
        if(ts.f.f==n&&ts.f.s==m){
            g=true;
            cout<<ms[ts];
            break;
        }
        if(ms[ts]==0){
            for(int j=0;j<4;j++){
                if(ms.find(mp(ts.f,mp(ts.s.f,j)))!=ms.end()){
                    ms[mp(ts.f,mp(ts.s.f,j))]=ms[ts]+1;
                    q.push(mp(ts.f,mp(ts.s.f,j)));
                }
            }
        }else{
            //decr
            if(ts.s.s==0){
                int nx=ts.f.f-(ts.s.f-1);
                pair<pii,pii> np=mp(mp(nx,ts.f.s),mp(ts.s.f-1,ts.s.s));
                if(nx>0&& vs[ts.f.f][ts.f.s]-vs[nx-1][ts.f.s]==0 &&
                    ms.find(np)==ms.end()){
                    ms[np]=ms[ts]+1;
                    q.push(np);
                }
            }else if(ts.s.s==1){
                int nx=ts.f.s+(ts.s.f-1);
                pair<pii,pii> np=mp(mp(ts.f.f,nx),mp(ts.s.f-1,ts.s.s));
                if(nx<=m&&hs[ts.f.f][nx]-hs[ts.f.f][ts.f.s-1]==0&&
                    ms.find(np)==ms.end()){
                    ms[np]=ms[ts]+1;
                    q.push(np);
                }
            }else if(ts.s.s==2){
                int nx=ts.f.f+(ts.s.f-1);
                pair<pii,pii> np=mp(mp(nx,ts.f.s),mp(ts.s.f-1,ts.s.s));
                if(nx<=n&&vs[nx][ts.f.s]-vs[ts.f.f-1][ts.f.s]==0 &&
                    ms.find(np)==ms.end()){
                    ms[np]=ms[ts]+1;
                    q.push(np);
                }
            }else{
                int nx=ts.f.s-(ts.s.f-1);
                pair<pii,pii> np=mp(mp(ts.f.f,nx),mp(ts.s.f-1,ts.s.s));
                if(nx>0&&hs[ts.f.f][ts.f.s]-hs[ts.f.f][nx-1]==0&&
                    ms.find(np)==ms.end()){
                    ms[np]=ms[ts]+1;
                    q.push(np);
                }
            }
        }
        //incr
        if(ts.s.s==0){
            int nx=ts.f.f-(ts.s.f+1);
            pair<pii,pii> np=mp(mp(nx,ts.f.s),mp(ts.s.f+1,ts.s.s));
            if(nx>0&& vs[ts.f.f][ts.f.s]-vs[nx-1][ts.f.s]==0 &&
                ms.find(np)==ms.end()){
                ms[np]=ms[ts]+1;
                q.push(np);
            }
        }else if(ts.s.s==1){
            int nx=ts.f.s+(ts.s.f+1);
            pair<pii,pii> np=mp(mp(ts.f.f,nx),mp(ts.s.f+1,ts.s.s));
            if(nx<=m&&hs[ts.f.f][nx]-hs[ts.f.f][ts.f.s-1]==0&&
                ms.find(np)==ms.end()){
                ms[np]=ms[ts]+1;
                q.push(np);
            }
        }else if(ts.s.s==2){
            int nx=ts.f.f+(ts.s.f+1);
            pair<pii,pii> np=mp(mp(nx,ts.f.s),mp(ts.s.f+1,ts.s.s));
            if(nx<=n&&vs[nx][ts.f.s]-vs[ts.f.f-1][ts.f.s]==0 &&
                ms.find(np)==ms.end()){
                ms[np]=ms[ts]+1;
                q.push(np);
            }
        }else{
            int nx=ts.f.s-(ts.s.f+1);
            pair<pii,pii> np=mp(mp(ts.f.f,nx),mp(ts.s.f+1,ts.s.s));
            if(nx>0&&hs[ts.f.f][ts.f.s]-hs[ts.f.f][nx-1]==0&&
                ms.find(np)==ms.end()){
                ms[np]=ms[ts]+1;
                q.push(np);
            }
        }
    }
    if(!g){
        cout<<-1;
    }
    cout<<"\n";
    return 0;
}

