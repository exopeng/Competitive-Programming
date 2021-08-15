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
long long x,y,x2,y2,n;
string s;
pair<long long,long long> pref[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>y>>x2>>y2>>n;
    cin>>s;
    if(s[0]=='U'){
        pref[0]=mp(0,1);
    }
    if(s[0]=='D'){
        pref[0]=mp(0,-1);

    }
    if(s[0]=='L'){
        pref[0]=mp(-1,0);
    }
    if(s[0]=='R'){
        pref[0]=mp(1,0);
    }
    for(int i=1;i<s.size();i++){
        if(s[i]=='U'){
            pref[i]=mp(pref[i-1].f,pref[i-1].s+1);
        }
        if(s[i]=='D'){
            pref[i]=mp(pref[i-1].f,pref[i-1].s-1);
        }
        if(s[i]=='L'){
            pref[i]=mp(pref[i-1].f-1,pref[i-1].s);
        }
        if(s[i]=='R'){
            pref[i]=mp(pref[i-1].f+1,pref[i-1].s);
        }
    }
    //long long
    long long lo=0;
    long long hi=1e15;
    long long result=0;
    pair<long long,long long> coord;
    long long cyc = hi / n;
    long long rem = hi % n;
    coord.f=x+cyc*pref[n-1].f;
    coord.s=y+cyc*pref[n-1].s;
    if(rem>0){
        coord.f+=pref[rem-1].f;
        coord.s+=pref[rem-1].s;
    }
    if(abs(coord.f-x2)+abs(coord.s-y2) > hi){
        cout<<"-1"<<"\n";
        return 0;
    }
    while(lo <= hi){
        long long mid = (lo + hi)/2;
        cyc = mid / n;
        rem = mid % n;
        coord.f=x+cyc*pref[n-1].f;
        coord.s=y+cyc*pref[n-1].s;
        if(rem>0){
            coord.f+=pref[rem-1].f;
            coord.s+=pref[rem-1].s;
        }
        if(abs(coord.f-x2)+abs(coord.s-y2) <= mid){
            result = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }   
    }
    cout<<result<<"\n";
    
}
/* REMINDERS
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

