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
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define is insert
const long long INF = 1e13;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
string s;
long long x,y;
long long dp[MAXN][2];
pair<long long,long long> oz[MAXN][2];
bool vis[MAXN][2];
pii rec(int i, int j){
    pii ret;
    if(vis[i][j]){
        return oz[i][j];
    }
    vis[i][j]=true;
    if(i==s.size()){
        oz[i][j]=mp(0,0);
        return mp(0,0);
    }
    if(!(s[i]==(j+'0')||s[i]=='?')){
        dp[i][j]=INF;
        oz[i][j]=mp(INF,INF);
        return mp(INF,INF);
    }else{
        pii ns=rec(i+1,1);
        pii nn=rec(i+1,0);
        if(j==0){
            if(x*ns.f+dp[i+1][1]<x*nn.f+dp[i+1][0]){
                dp[i][j]=x*ns.f+dp[i+1][1];
                oz[i][j]=ns;
            }else{
                dp[i][j]=x*nn.f+dp[i+1][0];
                oz[i][j]=nn;
            }
            oz[i][j].s++;
            return oz[i][j];
        }else{
            if(y*ns.s+dp[i+1][1]<y*nn.s+dp[i+1][0]){
                dp[i][j]=y*ns.s+dp[i+1][1];
                oz[i][j]=ns;
            }else{
                dp[i][j]=y*nn.s+dp[i+1][0];
                oz[i][j]=nn;
            }
            oz[i][j].f++;
            return oz[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    cin>>x>>y;
    for(int i=0;i<s.size();i++){
        dp[i][0]=INF;
        dp[i][1]=INF;
        oz[i][0]=mp(INF,INF);
        oz[i][1]=mp(INF,INF);
    }
    for(int i=s.size()-1;i>-1;i--){
        if(i==s.size()-1){
            if(s[i]=='?'||s[i]=='1'){
                dp[i][1]=0;
                oz[i][1]=mp(1,0);
            }
            if(s[i]=='?'||s[i]=='0'){
                dp[i][0]=0;
                oz[i][0]=mp(0,1);
            }
        }else{
            if(s[i]=='?'||s[i]=='1'){
                if(y*oz[i+1][1].s+dp[i+1][1]<y*oz[i+1][0].s+dp[i+1][0]){
                    dp[i][1]=y*oz[i+1][1].s+dp[i+1][1];
                    oz[i][1]=mp(oz[i+1][1].f+1,oz[i+1][1].s);
                }else{
                    dp[i][1]=y*oz[i+1][0].s+dp[i+1][0];
                    oz[i][1]=mp(oz[i+1][0].f+1,oz[i+1][0].s);
                }
            }
            if(s[i]=='?'||s[i]=='0'){
                 if(x*oz[i+1][1].f+dp[i+1][1]<x*oz[i+1][0].f+dp[i+1][0]){
                    dp[i][0]=x*oz[i+1][1].f+dp[i+1][1];
                    oz[i][0]=mp(oz[i+1][1].f,oz[i+1][1].s+1);
                }else{
                    dp[i][0]=x*oz[i+1][0].f+dp[i+1][0];
                    oz[i][0]=mp(oz[i+1][0].f,oz[i+1][0].s+1);
                }
            }
        }
    }
    cout<<min(dp[0][0],dp[0][1])<<"\n";
    return 0;
}
/* REMINDERS
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

