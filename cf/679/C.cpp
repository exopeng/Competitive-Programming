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
const int MAXN = 250000+5;
//store test cases here
/*


*/
int a[6];
int as[MAXN];
//first stores index, second is the number
vector<pii> arr;
int occ[MAXN];
int n;
bool check(int diff){
    int ct=0;
    for(int i=0;i<n;i++){
        occ[i]=0;
    }
    int st=0;
    for(int i=0;i<6*n;i++){
        while(arr[i].f-arr[st].f>diff){
            occ[arr[st].s]--;
            if(occ[arr[st].s]==0){
                ct--;
            }
            st++;
        }
        occ[arr[i].s]++;
        if(occ[arr[i].s]==1){
            ct++;
        }
        if(ct==n){
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>as[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            arr.pb(mp(as[i]-a[j],i));
        }
    }
    sort(arr.begin(),arr.end());
    int lo=0;
    int hi=1e9+5;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo<<"\n";
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

