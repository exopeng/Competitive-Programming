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
int s[MAXN];
ll ms[MAXN];
ll add[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		ll ans=0;
		for(int j=0;j<n;j++){
			cin>>s[j];
			ms[j]=0;
			add[j]=0;
		}
		add[n]=0;
		ll curr=0;
		for(int j=0;j<n;j++){
			curr+=add[j];
			ms[j]+=curr;
			int pos=j+s[j];
			if(pos<n){
				add[pos+1]--;
			}
			if(pos-ms[j]+1<n){
				//might be updated multiple times
				if(pos-ms[j]+1<j+2){
					ms[j+1]+=j+1-pos+ms[j];
					add[j+2]++;
				}else{
					add[pos-ms[j]+1]++;
				}
			}
			s[j]-=ms[j];
			if(s[j]>1){
				ans+=s[j]-1;
				if(j+2<n){
					add[j+2]++;
				}
				if(j+s[j]<n){
					add[j+s[j]+1]--;
				}
			}
		}
		cout<<ans<<"\n";
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

