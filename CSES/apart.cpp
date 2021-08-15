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
const int MAXN = 5e5;
//store test cases here
/*


*/
long long n,m,k;
int ans=0;
vector<pair<long long,int> > ap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
    	pii ar;
    	cin>>ar.f;
    	ar.f-=k;
    	ar.s=0;
    	ap.pb(ar);
    }
    for(int i=0;i<m;i++){
    	pii ar;
    	cin>>ar.f;
    	ar.s=1;
    	ap.pb(ar);
    }
    sort(ap.begin(),ap.end());
    queue<long long> al;
    for(int i=0;i<ap.size();i++){
    	pii cur=ap[i];
    	//handle neg sizes
    	while(al.size()>0){
    		if(al.front()+2*k<cur.f){
    			al.pop();
    		} else {
    			break;
    		}
    	}
    	if(cur.s==0){
    		al.push(cur.f);
    	}else if(al.size()>0){	
    		ans++;
    		al.pop();
    	}
    }
    cout<<ans<<"\n";
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

