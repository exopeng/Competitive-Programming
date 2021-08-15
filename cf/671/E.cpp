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
const int MAXN = 2e6;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	ll n;
    	cin>>n;
        int ct=0;
    	set<int> div;
        set<int> ps;
        map<int,vector<int>> ms;
        for(int j=2;j<=pow(n,0.5);j++){
            if(n%j==0){
                div.is(j);
                div.is(n/j);
            }
        }
        div.is(n);
        int curr=n;
        int di=2;
        while(curr!=1&&curr>=di&&di<=pow(n,0.5)){
            while(curr%di==0){
                ps.is(di);
                curr/=di;
            }
            di++;
        }
        if(curr!=1){
            ps.is(curr);
        }
        if(ps.size()==2){
            if(div.size()>3){
                int p1=*ps.begin();
                int p2=*next(ps.begin());
                ms[p1].pb(p1*p2);
                div.erase(p1*p2);
                if(n%((ll)pow(p1,2))==0){
                    ms[p2].pb(p1*p1*p2);
                    div.erase(p1*p1*p2);
                }else{
                    ms[p2].pb(p1*p2*p2);
                    div.erase(p1*p2*p2);
                }
            }else{
                ct++;
            }
        }else if(ps.size()>2){
            for(auto it=ps.begin();it!=ps.end();it++){
                ll mt=(*it)*(*ps.begin());
                if(it!=prev(ps.end())){
                    mt=(*it)*(*next(it));
                }
                div.erase(mt);
                ms[*it].pb(mt);
            }
        }
        for(auto it=div.begin();it!=div.end();it++){
            for(auto it1=ps.begin();it1!=ps.end();it1++){
                if((*it)%(*it1)==0){
                    ms[*it1].pb(*it);
                    break;
                }
            }
        }
        for(auto it=ms.begin();it!=ms.end();it++){
            reverse(ms[it->f].begin(),ms[it->f].end());
            for(int j=0;j<ms[it->f].size();j++){
                cout<<ms[it->f][j]<<" ";
            }
        }
        cout<<"\n";
        cout<<ct<<"\n";
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
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

