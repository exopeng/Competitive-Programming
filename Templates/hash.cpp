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
const ll INF = 1e9;
const ll MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
ll hsh[MAXN][2];
ll pw[MAXN][2]; // Stores the powers of P modulo M
const ll P=9973; // Change M and P if you want to
const ll M=1e9+9;
const ll M1=1e9+7;
void calc_hashes(string s){
    hsh[0][0]=hsh[0][1]=1;
    pw[0]=1;
    for(int i=1;i<s.size();i++){
    	pw[i][0]=(pw[i-1][0]*P)%M;
        pw[i][1]=(pw[i-1][1]*P)%M1;
    }
    for(int i=0;i<s.size();i++)
        hsh[i+1][0]=((hsh[i][0]*P)%M+s[i])%M;
        hsh[i+1][1]=((hsh[i][1]*P)%M1+s[i])%M1;
}

ll get_hash(int a,int b,int fs){ // Endpoints of the substring
    ll ab=(hsh[b+1][1]-(hsh[a][1]*pw[b-a+1][1])%M1+M1)%M1;
    if(fs==0){
        ab=(hsh[b+1][0]-(hsh[a][0]*pw[b-a+1][0])%M+M)%M;
    }
    return ab;
}
struct hash_pair{ 
    template <class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const
    { 
        auto hash1=hash<T1>{}(p.first); 
        auto hash2=hash<T2>{}(p.second); 
        return hash1^hash2; 
    } 
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
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

