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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,d,m;
int a[MAXN];
ll ds[MAXN];
ll wt[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    sort(a,a+n);
    int ix=-1;
    for(int i=n-1;i>-1;i--){
        if(a[i]<=m){
            ix=i;
            break;
        }
        if(i!=n-1){
            ds[(n-1)-i]+=ds[(n-1)-i-1];
        }
        ds[(n-1)-i]+=a[i];
    }
    ll as=0;
    for(int i=ix;i>-1;i--){
        wt[ix-i]+=a[i];
        if(i!=ix){
            wt[ix-i]+=wt[ix-i-1];
        }
        as=wt[ix-i];
    }
    for(int i=1;i<n;i++){
        wt[i]=max(wt[i-1],wt[i]);
    }
    for(int i=0;i*(d+1)+1<=n;i++){
        ll ts=0;
        ts+=ds[i];
        ts+=wt[n-i*(d+1)-1-1];
        as=max(as,ts);
    }
    cout<<as<<"\n";
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

