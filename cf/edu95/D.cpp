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
const int MAXN = 2e5+100;
//store test cases here
/*


*/
int n,q;
set<int> ac;
multiset<int,greater<int>> gp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        ac.is(p);
    }
    for(auto it=ac.begin();it!=ac.end();it++){
        if(next(it)!=ac.end()){
            gp.is(*next(it)-*it);
        }
    }
    cout<<*prev(ac.end())-*ac.begin()-*gp.begin()<<"\n";
    for(int i=0;i<q;i++){
        int t,x;
        cin>>t>>x;
        if(t==0){
            auto it=ac.find(x);
            if(it!=ac.begin()){
                gp.erase(gp.find(x-*prev(it)));
            }
            if(it!=prev(ac.end())){
                gp.erase(gp.find(*next(it)-x));
            }
            if(it!=ac.begin()&&it!=prev(ac.end())){
                gp.is(*next(it)-*prev(it));
            }
            ac.erase(it);
        }else{
            auto it=ac.ub(x);
            if(it!=ac.end()){
                gp.is(*it-x);
            }
            if(it!=ac.begin()){
                gp.is(x-*prev(it));
            }
            if(it!=ac.end()&&it!=ac.begin()){
                gp.erase(gp.find(*it-*prev(it)));
            }
            ac.is(x);
        }
        if(ac.size()<3){
            cout<<0<<"\n";
        }else{
            cout<<*prev(ac.end())-*ac.begin()-*gp.begin()<<"\n";
        }
    }
    //check empty set, set of 1 and 2 piles
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
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

