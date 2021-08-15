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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool g=true;
        for(int j=k;j<n;j++){
            if(s[j]=='?'&&s[j-k]!='?'){
                s[j]=s[j-k];
            }else if(s[j-k]=='?'&&s[j]!='?'){
                s[j-k]=s[j];
            }else if(s[j-k]!=s[j]){
                g=false;
            }
        }
        int ct0=0;
        int ct1=0;
        for(int j=0;j<k-1;j++){
            if(s[j]=='0'){
                ct0++;
            }else if(s[j]=='1'){
                ct1++;
            }
        }
        for(int j=k-1;j<n;j++){
            if(j-k>=0){
                if(s[j-k]=='0'){
                    ct0--;
                }else if(s[j-k]=='1'){
                    ct1--;
                }
            }
            if(s[j]=='0'){
                ct0++;
            }else if(s[j]=='1'){
                ct1++;
            }
            if(ct0<=k/2&&ct1<=k/2){

            }else{
                g=false;
            }
        }
        if(!g){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
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
 */

