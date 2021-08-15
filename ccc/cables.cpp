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
int x[MAXN];
int y[MAXN];
int z[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cables.in","r",stdin);
    freopen("cables.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	int a,b,c;
    	cin>>x[i]>>y[i]>>z[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    sort(z,z+n);
    long long pre=0;
    long long pre1=0;
    long long pre2=0;
    for(int i=1;i<n;i++){
    	pre+=x[i]-x[0];
    	pre1+=y[i]-y[0];
    	pre2+=z[i]-z[0];
    }
    long long xs=pre;
    long long ys=pre1;
    long long zs=pre2;
    for(int i=1;i<n;i++){
    	pre=pre+(2*i-n)*(x[i]-x[i-1]);
    	xs+=pre;
    	pre1=pre1+(2*i-n)*(y[i]-y[i-1]);
    	ys+=pre1;
    	pre2=pre2+(2*i-n)*(z[i]-z[i-1]);
    	zs+=pre2;
    }
    cout<<xs/2+ys/2+zs/2<<"\n";
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

