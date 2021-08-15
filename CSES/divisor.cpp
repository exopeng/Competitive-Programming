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
int n,x;
vector<int> getp(){
	vector<int> primes;
	vector<bool> is_prime(1e6+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= 1e6+1; i++) {
	    if (is_prime[i]) {
	    	primes.pb(i);
	        for (int j = i * i; j <= 1e6+1; j += i)
	            is_prime[j] = false;
	    }
	}
	return primes;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> prime = getp();
    for(int j=0;j<n;j++){
    	cin>>x;
    	vector<int> pows;
    	for(int i=0;i<prime.size();i++){
    		if(prime[i] > x){
    			break;
    		}
    		if(x%prime[i]==0){
    			pows.pb(1);
    			x/=prime[i];
    			while(x%prime[i]==0){
    				x/=prime[i];
    				pows[pows.size()-1]++;
    			}
    		}
    	}
    	if(x!=1){
    		pows.pb(1);
    	}
    	long long ans=1;
    	for(int i=0;i<pows.size();i++){
    		ans*=(pows[i]+1);
    	}
    	cout<<ans<<"\n";
    }
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

