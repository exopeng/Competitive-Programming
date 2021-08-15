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
#define is insert
const long long INF = 1000000000;
const long long MOD = 1000000007;
const int MAXN = 1e5+1;
//store test cases here
/*


*/
int n;
vector<int> adj[MAXN];
int s[MAXN];
int p[MAXN];
bool f=false;
int dfs(int curr,int h){
    if(h%2==0){
        int m = INF;
        for(int i=0;i<adj[curr].size();i++){
            m = min(m,dfs(adj[curr][i],h+1)-s[p[curr]]);
            if(m<0){
                f=true;
            }
        }
        if(adj[curr].size()==0){
            s[curr]=s[p[curr]];
        }else{
            s[curr]=s[p[curr]]+m;
        }
    } else{
        for(int i=0;i<adj[curr].size();i++){
            dfs(adj[curr][i],h+1);
        }
    }
    return s[curr];
}
long long ans=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        a--;
        adj[a].pb(i+1);
        p[i+1]=a;
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    dfs(0,1);
    ans=s[0];
    for(int i=1;i<n;i++){
        ans+=s[i]-s[p[i]];
    }
    if(f){
        ans=-1;
    }
    cout<<ans<<"\n";
}
/* REMINDERS
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

