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
const int MAXN = 4e5;
//store test cases here
/*


*/
ll a[MAXN];
ll v[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,q;
    	cin>>n>>q;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
            v[j]=0;
    	}
        ll sum=0;
        for(int j=0;j<n;j++){
            if(j==0){
                if(n==1||a[j]>a[j+1]){
                    v[j]=a[j];
                }
            }else if(j==n-1){
                if(a[j]>a[j-1]){
                    v[j]=a[j];
                }
            }else{
                if(a[j]>a[j-1]&&a[j]>a[j+1]){
                    v[j]=a[j];
                }else if(a[j]<a[j-1]&&a[j]<a[j+1]){
                    v[j]=-1*a[j];
                }
            }
            sum+=v[j];
        }
        cout<<sum<<"\n";
        for(int m=0;m<q;m++){
            int l,r;
            cin>>l>>r;
            l--,r--;
            set<int> as;
            as.is(l+1);
            as.is(l-1);
            as.is(l);
            as.is(r+1);
            as.is(r-1);
            as.is(r);
            swap(a[l],a[r]);
            for(auto it=as.begin();it!=as.end();it++){
                if(*it>-1&&*it<n){
                    sum-=v[*it];
                    v[*it]=0;
                }
            }
            for(auto it=as.begin();it!=as.end();it++){
                if(*it<0||*it>n-1){
                    continue;
                }
                int j=*it;
                if(j==0){
                    if(n==1||a[j]>a[j+1]){
                        v[j]=a[j];
                    }
                }else if(j==n-1){
                    if(a[j]>a[j-1]){
                        v[j]=a[j];
                    }
                }else{
                    if(a[j]>a[j-1]&&a[j]>a[j+1]){
                        v[j]=a[j];
                    }else if(a[j]<a[j-1]&&a[j]<a[j+1]){
                        v[j]=-1*a[j];
                    }
                }
                sum+=v[j];
            }
            cout<<sum<<"\n";
        }
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

