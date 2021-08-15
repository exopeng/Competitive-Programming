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
const int MAXN = 5e3+1;
//store test cases here
/*


*/
string s;
string bs;
bool dp[MAXN][MAXN][10];
long long ans[13];
long long hsh[MAXN];
long long hsh1[MAXN];
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
void calc_hashes1(string s) {
    hsh1[0] = 1;
    for (int i = 0; i < s.size(); i++)
        hsh1[i + 1] = ((hsh1[i] * P) % M + s[i]) % M;
}

long long get_hash(int a, int b) { // Endpoints of the substring
	long long ab=(hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % M + M) % M;
    return ab;
}
long long get_hash1(int a, int b) { // Endpoints of the substring
	long long ab=(hsh1[b + 1] - (hsh1[a] * pw[b - a + 1]) % M + M) % M;
    return ab;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    bs=s;
    calc_hashes(s);
    for(int i=0;i<s.size();i++){
    	bs[i]=s[s.size()-i-1];
    }
    calc_hashes1(bs);
    for(int k=0;k<=ceil(log2(s.size()));k++){
    	for(int i=0;i<s.size();i++){
	    	for(int j=i;j<s.size();j++){
	    		if(k==0){
	    			if(get_hash(i,j)==get_hash1(s.size()-1-j,s.size()-i-1)){
	    				dp[i][j][k]=true;
	    				ans[k]++;
	    			}
	    		}else{
	    			if(get_hash(i,i+(j-i+1)/2-1)==get_hash(j-(j-i+1)/2+1,j)
	    				&&dp[i][i+(j-i+1)/2-1][k-1]&&dp[j-(j-i+1)/2+1][j][k-1]){
	    				dp[i][j][k]=true;
	    				ans[k]++;
	    			}
	    		}
	    	}
	    }
    }
    for(int i=0;i<s.size();i++){
    	cout<<ans[i]<<" ";
    }
    cout<<"\n";
    
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

