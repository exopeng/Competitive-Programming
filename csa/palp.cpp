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
#define pdd pair<double,double>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 1e6+10;
//store test cases here
/*


*/
int t;
long long hsh[MAXN];
long long pw[MAXN]; // Stores the powers of P modulo M
const long long P = 9973; // Change M and P if you want to
const long long M = 1e9 + 9;
void calc_hashes(string s) {
    hsh[0] = 1;
    pw[0]=1;
    for(int i=1;i<s.size();i++){
    	pw[i]=(pw[i-1]*P) % M;
    }
    for (int i = 0; i < s.size(); i++)
        hsh[i + 1] = ((hsh[i] * P) % M + s[i]) % M;
}

long long get_hash(int a, int b) { // Endpoints of the substring
	long long ab=(hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % M + M) % M;
    return ab;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
    	string s;
    	int ans=0;
    	cin>>s;
    	calc_hashes(s);
    	int start=0;
    	for(int j=0;j<s.size()/2;j++){
    		while(j<s.size()/2&&get_hash(start,j)!=get_hash(s.size()-1-j,s.size()-start-1)){
    			//cout<<s.substr(start,j-start+1)<<" "<<s.substr(s.size()-1-j,j-start+1)<<"\n";
    			j++;
    		}
    		if(j==s.size()/2){
    			ans++;
    		}else{
    			ans+=2;
    		}
    		start=j+1;
    		if(j==s.size()/2-1&&s.size()%2==1){
    			ans++;
    		}
    	}
    	cout<<max(1,ans)<<"\n";
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

