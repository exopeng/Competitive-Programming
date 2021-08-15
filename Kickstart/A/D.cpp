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
int n;
int a[1000][1000];
int b[1000][1000];
int r[1000];
int c[1000];
int ts[1000][1000];
bool ck(){

}
vector<vector<pair<pii,int>>> poss;
vector<pair<pii,int>> q
void rec(int i,int j){
    if(j==n){
        j=0;
        i++;
    }
    if(i==n){
        poss.pb(q);
        return;
    }
    if(a[i][j]==-1){
        q.pb(mp(0,mp(i,j)));
        rec(i,j+1);
        q.pop_back();
        q.pb(mp(1,mp(i,j)));
        rec(i,j+1);
        q.pop_back();
    }else{
        rec(i,j+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	cin>>n;
        int mn=INF;
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++){
                cin>>a[j][f];
            }
        }
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++){
                cin>>b[j][f];
            }
        }
        for(int j=0;j<n;j++){
            cin>>r[j];
        }
        for(int j=0;j<n;j++){
            cin>>c[j];
        }
        rec(0,0);
        for(int j=0;j<poss.size();j++){

        }
    	cout<<"Case #"<<i+1<<": "<<abs(k-st)<<"\n";
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

