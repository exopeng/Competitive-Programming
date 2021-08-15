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

int g[1000][1000];
bool vis[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int r,c;
        cin>>r>>c;
        ll ans=0;
        priority_queue< pair<int,pii>, vector<pair<int,pii>>> q;
        for(int j=0;j<r;j++){
            for(int f=0;f<c;f++){
                cin>>g[j][f];
                vis[j][f]=false;
                q.push(mp(g[j][f],mp(j,f)));
            }
        }
        while(!q.empty()){
            pii ts=q.top().s;
            q.pop();
            if(vis[ts.f][ts.s]){
                continue;
            }
            vis[ts.f][ts.s]=true;
            for(int j=0;j<4;j++){
                int xs=ts.f+dx[j];
                int ys=ts.s+dy[j];
                if(xs<r&&xs>-1&&ys<c&&ys>-1){
                    if(abs(g[ts.f][ts.s]-g[xs][ys])>1){
                        ans+=abs(g[ts.f][ts.s]-g[xs][ys])-1;
                        g[xs][ys]=g[ts.f][ts.s]-1;
                        q.push(mp(g[xs][ys],mp(xs,ys)));
                    }
                }
            }
        }
        //cout<<ans<<"\n";
    	cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 */

