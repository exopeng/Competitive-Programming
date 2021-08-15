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
int x,n;
set<int> un;
set<pair<int,pii>, greater<pair<int,pii> > > dist;
map<pii,int> ms;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>n;
    un.is(0);
    un.is(x);
    //ms.is(mp(mp(0,x),x));
    dist.is(mp(x,mp(0,x)));
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        auto it=un.lb(a);
        auto it1=prev(un.lb(a));    
        //cout<<*it<<" "<<*it1<<"\n";
        //ms.erase(mp(*it1, *it));
        dist.erase( mp(*it - *it1,mp(*it1, *it)) );
        //ms.is(mp(mp(a,*it), *it-a));
        //ms.is(mp(mp(*it1,a), a-*it1));
        dist.is(mp( *it-a,mp(a,*it)));
        dist.is(mp( a-*it1,mp(*it1,a)));
        un.is(a);
        cout<<dist.begin()->f<<" ";
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
 