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
const int MAXN = 2e5;

//store test cases here
/*


*/ 
long long ans = 0;
int n,k;
vector<long long> arr;
vector<long long> sum;
vector<int> cut;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.pb(a);
        sum.pb(0);
        cut.pb(0);
    }
    sort(arr.begin(),arr.end());
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])>k){
            cut[i]=1;
        }
    }
    int f=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            if(cut[i]==1){
                if(f==0){
                   ans=max(ans,sum[i-1]);
                }else{
                   ans=max(ans,sum[i-1]-sum[f-1]);
                }
            }else{
                if(f==0){
                    ans=max(ans,sum[i]);
                }else{
                   ans=max(ans,sum[i]-sum[f-1]);
                }
            }
        } else{
            if(cut[i]==1){
                if(f==0){
                   ans=max(ans,sum[i-1]);
                }else{
                   ans=max(ans,sum[i-1]-sum[f-1]);
                }
                f=i;
            }
        }
        

    }

    cout << ans << "\n";
    return 0;
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
