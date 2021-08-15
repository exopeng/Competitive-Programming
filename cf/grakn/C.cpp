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
double a[MAXN];
vector<double> fr;
vector<double> br;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        fr.clear();
        br.clear();
    	int n,l;
    	cin>>n>>l;
        a[0]=0;
    	for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        a[n+1]=l;
        double last=0;
        double last1=l;
        fr.pb(0);
        br.pb(0);
        for(int j=1;j<=n+1;j++){
            fr.pb(fr[j-1]+(a[j]-last)/(j));
            br.pb(br[j-1]+(last1-a[n-j+1])/(j));
            last=a[j];
            last1=a[n-j+1];
        }
        double lo=0;
        double hi=1e9+5;
        while(hi-lo>=(double)(1)/(1e8)){
            double mid=(lo+hi)/2;
            double ft=*prev(ub(fr.begin(),fr.end(),mid));
            double lt=*prev(ub(br.begin(),br.end(),mid));
            int ix=(prev(ub(fr.begin(),fr.end(),mid))-fr.begin());
            double d1=a[ix]+(ix+1)*(mid-ft);
            int ix1=(prev(ub(br.begin(),br.end(),mid))-br.begin());
            double d2=a[n-ix1+1]-(ix1+1)*(mid-lt);
            if(d2<d1){
                hi=mid-((double)1/1e8);
            }else if(d2==d1){
                lo=mid;
                break;
            }else{
                lo=mid+((double)1/1e8);
            }
            //cout<<lo<<"\n";
        }
    	cout<<setprecision(15)<<lo<<"\n";
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
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

