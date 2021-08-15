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
int cta[26];
int ctb[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,k;
        vector<pii > as;
        string a,b;
        for(int j=0;j<26;j++){
            cta[j]=0;
            ctb[j]=0;
        }
        cin>>n>>k>>a>>b;
        for(int j=0;j<n;j++){
            cta[(int)a[j]-97]++;
            ctb[(int)b[j]-97]++;
        }
        for(int j=0;j<26;j++){
            if(ctb[j]!=0){
                if(cta[j]!=0){
                    if(cta[j]>=ctb[j]){
                        cta[j]-=ctb[j];
                        ctb[j]=0;
                    }else{
                        ctb[j]-=cta[j];
                        cta[j]=0;
                    }
                }
            }
            if(cta[j]!=0){
                as.pb(mp(0,cta[j]));
            }
            if(ctb[j]!=0){
                as.pb(mp(1,ctb[j]));
            }
        }
        int nd=0;
        bool g=false;
        for(int j=as.size()-1;j>-1;j--){
            if(as[j].s%k!=0){
                g=true;
                break;
            }
            if(j==0){
                if(as[j].f==0){
                    if(as[j].s!=nd){
                        g=true;
                    }
                }else{
                    g=true;
                }
            }else{
                if(as[j].f==1){
                    nd+=as[j].s;
                }else{
                    if(nd>=as[j].s){
                        nd-=as[j].s;
                    }else{
                        g=true;
                        break;
                    }
                }
            }
        }
        if(!g){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
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

