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

int n,m;
set<pii> cd;
multiset<int> sz;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    cd.is(mp(-1,0));
    cd.is(mp(INF,1));
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            int st=0;
            while(s[i]=='0'){
                i++;
                st++;
            }
            i--;
            sz.is(st);
            if(st==1){
                cd.is(mp(i-st+1,0));
            } else{
                cd.is(mp(i-st+1,0));
                cd.is(mp(i,1));
            }
        } else{
            int st=0;
            while(s[i]=='1'){
                i++;
                st++;
            }
            i--;
            sz.is(st);
            if(st==1){
                cd.is(mp(i-st+1,2));
            } else{
                cd.is(mp(i-st+1,2));
                cd.is(mp(i,3));
            }
        }
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        auto it=cd.lb(mp(a,0));
        //between 1
        //between 0

        if(it->f==a){
            if(it->s==0){
                if(a==0){
                    
                }else if(a==n-1){
                    
                }
            }else if(it->s==1){

            } else if(it->s==2){

            }else{

            }
        }else{  
            if(it->s==1&&prev(it)->s==0){

            }else{

            }
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

