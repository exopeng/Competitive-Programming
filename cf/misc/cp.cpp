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
const int MAXN = 5e5;
//store test cases here
/*


*/
pair<int,pii> dp[MAXN];
int a[MAXN];
int b[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<MAXN;i++){
        dp[i]=mp(-1,mp(0,0));
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        vector<int> on,tw;
        cin>>n>>m;
        ll sm=0;
        ll ms=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
            ms+=a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
            sm+=b[j];
        }
        if(ms<m){
            cout<<-1<<"\n";
            continue;
        }
        for(int j=0;j<n;j++){
            if(b[j]==1){
                on.pb(a[j]);
            }else{
                tw.pb(a[j]);
            }   
        }
        sort(on.begin(),on.end()),sort(tw.begin(),tw.end());
        reverse(on.begin(),on.end()),reverse(tw.begin(),tw.end());
        int ix=0;
        dp[0].f=0;
        while(true){
            if(dp[ix].f!=-1){
                if(dp[ix].f>=m){
                    cout<<ix<<"\n";
                    break;
                }
                if(dp[ix].s.f!=on.size()){
                    if(dp[ix+1].f<dp[ix].f+on[dp[ix].s.f]){
                        dp[ix+1].f=dp[ix].f+on[dp[ix].s.f];
                        dp[ix+1].s.f=dp[ix].s.f+1;
                        dp[ix+1].s.s=dp[ix].s.s;
                    }
                }
                if(dp[ix].s.s!=tw.size()){
                    if(dp[ix+2].f<dp[ix].f+tw[dp[ix].s.s]){
                        dp[ix+2].f=dp[ix].f+tw[dp[ix].s.s];
                        dp[ix+2].s.s=dp[ix].s.s+1;
                        dp[ix+2].s.f=dp[ix].s.f;
                    }
                }
            }
            ix++;
        }
        for(int j=0;j<=sm;j++){
            dp[j]=mp(-1,mp(0,0));
        }
    }
    return 0;
}

