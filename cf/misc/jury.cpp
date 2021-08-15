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
const int MAXN = 2e3+5;
//store test cases here
/*


*/
int k,n;
int ks[MAXN];
int av[MAXN];
set<int> poss;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>n;
    for(int i=0;i<k;i++){
    	cin>>ks[i];
    }
    for(int i=0;i<n;i++){
    	cin>>av[i];
    }
    for(int i=0;i<k;i++){
    	multiset<int> temp;
    	for(int j=0;j<n;j++){
    		temp.is(av[j]);
    	}
    	int ls=*temp.begin();
    	temp.erase(temp.begin());
    	int curr=ls;
    	for(int j=i+1;j<k;j++){
    		curr+=ks[j];
    		if(temp.find(curr)!=temp.end()){
    			temp.erase(temp.find(curr));
    		}
    	}
    	curr=ls;
    	for(int j=i;j>0;j--){
    		curr-=ks[j];
    		if(temp.find(curr)!=temp.end()){
    			temp.erase(temp.find(curr));
    		}
    	}
    	curr-=ks[0];
    	if(temp.size()==0){
    		poss.is(curr);
    	}
    }
    
    cout<<poss.size()<<"\n";
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

