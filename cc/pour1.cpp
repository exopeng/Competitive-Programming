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
map<pii,int> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        dp.clear();
    	int a,b,c;
        int ans=-1;
        cin>>a>>b>>c;
        queue<pii> q;
        q.push(mp(0,0));
        dp[mp(0,0)]=0;
        while(!q.empty()){
            pii ts=q.front();
            if(ts.f==c||ts.s==c){
                ans=dp[ts];
                break;
            }   
            q.pop();
            if(dp.find(mp(a,ts.s))==dp.end()){
                dp[mp(a,ts.s)]=dp[ts]+1;
                q.push(mp(a,ts.s));
            }
            if(dp.find(mp(ts.f,b))==dp.end()){
                dp[mp(ts.f,b)]=dp[ts]+1;
                q.push(mp(ts.f,b));
            }
            if(dp.find(mp(0,ts.s))==dp.end()){
                dp[mp(0,ts.s)]=dp[ts]+1;
                q.push(mp(0,ts.s));
            }
            if(dp.find(mp(ts.f,0))==dp.end()){
                dp[mp(ts.f,0)]=dp[ts]+1;
                q.push(mp(ts.f,0));
            }
            if(dp.find(mp(min(a,ts.f+ts.s),ts.s-(min(a,ts.f+ts.s)-ts.f)))==dp.end()){
                dp[mp(min(a,ts.f+ts.s),ts.s-(min(a,ts.f+ts.s)-ts.f))]=dp[ts]+1;
                q.push(mp(min(a,ts.f+ts.s),ts.s-(min(a,ts.f+ts.s)-ts.f)));
            }
            if(dp.find(mp(ts.f-(min(b,ts.s+ts.f)-ts.s),min(b,ts.s+ts.f)))==dp.end()){
                dp[mp(ts.f-(min(b,ts.s+ts.f)-ts.s),min(b,ts.s+ts.f))]=dp[ts]+1;
                q.push(mp(ts.f-(min(b,ts.s+ts.f)-ts.s),min(b,ts.s+ts.f)));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

