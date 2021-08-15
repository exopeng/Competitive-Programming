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
const int MAXN = 2e5+10;
//store test cases here
/*


*/
int ct[26];
int need[26];
int cur=0;
const long long M = 1e9 + 9;
const long long M1 = 1e9 + 7;

const long long P = 9973; // Change M and P if you want to
const long long P1 = 19469; // Change M and P if you want to
long long pw[MAXN]; // Stores the powers of P modulo M
long long pw1[MAXN]; // Stores the powers of P modulo M
long long hsh[MAXN];
long long hsh1[MAXN];
void calc_hashes(string s) {
    hsh[0] = 1;
    pw[0]=1;
    for(int i=1;i<s.size();i++){
    	pw[i]=(pw[i-1]*P) % M;
    }
    for (int i = 0; i < s.size(); i++)
        hsh[i + 1] = ((hsh[i] * P) % M + s[i]) % M;

    hsh1[0] = 1;
    pw1[0]=1;
    for(int i=1;i<s.size();i++){
    	pw1[i]=(pw1[i-1]*P1) % M1;
    }
    for (int i = 0; i < s.size(); i++)
        hsh1[i + 1] = ((hsh1[i] * P1) % M1 + s[i]) % M1;
}

pair<long long,long long> get_hash(int a, int b) { // Endpoints of the substring
	long long ab=(hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % M + M) % M;
	long long bc=(hsh1[b + 1] - (hsh1[a] * pw1[b - a + 1]) % M1 + M1) % M1;
    return mp(ab,bc);
}
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_set<pair<long long,long long>,HASH> taken;
string ne,ha;
int ans=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>ne>>ha;
    for(int i=0;i<ne.size();i++){
    	//97
    	need[(int)ne[i]-97]++;
    }
    if(ha.size()<ne.size()){
    	cout<<0<<"\n";
    	return 0;
    }
    calc_hashes(ha);
    for(int i=0;i<ne.size();i++){
    	int st=(int)ha[i]-97;
    	if(ct[st]<need[st]){
    		cur++;
    	}else{
    		cur--;
    	}
    	ct[st]++;
    	if(cur==ne.size()){
    		ans++;
    		pair<long long,long long> hs = get_hash(0,ne.size()-1);
    		taken.is(hs);
    	}
    }
    for(int i=ne.size();i<ha.size();i++){
    	int st=(int)ha[i]-97;
    	int st1=(int)ha[i-ne.size()]-97;
    	if(ct[st]<need[st]){
    		cur++;
    	}else {
    		cur--;
    	}
    	ct[st]++;
    	if(ct[st1]>need[st1]){
    		cur++;
    	}else {
    		cur--;
    	}
    	ct[st1]--;
    	pair<long long,long long> hs=get_hash(i-ne.size()+1,i);
		if(cur==ne.size()&&taken.find(hs)==taken.end()){
    		ans++;
    		taken.is(hs);
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

