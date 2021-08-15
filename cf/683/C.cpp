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
    	long long n,w;
        vector<int> ans;
    	cin>>n>>w;
        set<pll> ws;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            ws.is(mp(a,j));
        }
        long long c=0;
        if(w%2==0){
            c=w/2;
        }else{
            c=w/2+1;
        }
        auto it=ws.lb(mp(c,0));
        if(it!=ws.end()&&it->f<=w&&it->f>=c){
            cout<<1<<"\n"<<it->s+1<<"\n";
        }else{
            long long sum=0;
            auto ts=it;
            if(it!=ws.begin()){
                for(auto it1=prev(it);it1!=ws.begin();it1--){
                    sum+=it1->f;
                    if(sum>=c){
                        ts=it1;
                        break;
                    }
                }
            }
            if(sum<c&&ws.begin()->f+sum<=w){
                sum+=ws.begin()->f;
                ts=ws.begin();
            }
            if(sum>=c){ 
                for(;ts!=it;ts++){
                    ans.pb(ts->s+1);
                }
                cout<<ans.size()<<"\n";
                for(int j=0;j<ans.size();j++){
                    cout<<ans[j]<<" ";
                }
                cout<<"\n";
            }else{
                cout<<-1<<"\n";
            }
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
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

