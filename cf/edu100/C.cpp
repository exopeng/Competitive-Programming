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
#define pll pair<long long,long long>
#define is insert
#define ll long long
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
    	int n;
    	vector<pll> t;
    	vector<pll> in;
    	cin>>n;
    	int ans=0;
    	for(int j=0;j<n;j++){
    		int a,b;
    		cin>>a>>b;
    		t.pb(mp(a,b));
    	}
    	long long currx=0;
    	long long currt=0;
    	for(int j=0;j<n;j++){
    		if(t[j].f>=currt){
                in.pb(mp(t[j].f,currx));
    			currt=t[j].f+abs(t[j].s-currx);
    			currx=t[j].s;
    		}
    	}
        in.pb(mp(currt,currx));
        t.pb(mp(4*INF+5,0));
        for(int j=0;j<n;j++){
            auto it=ub(in.begin(),in.end(),mp(t[j].f,5*INF+5));
            int ind=(it-in.begin())-1;
            //pos dir
            if(in[ind].s<in[ind+1].s){
                ll st=min(t[j].f-in[ind].f+in[ind].s,in[ind+1].s);
                ll en=min(st+t[j+1].f-t[j].f,in[ind+1].s);
                if(t[j].s>=st&&t[j].s<=en){
                    ans++;
                }
                //cout<<st<<" "<<t[j].s<<" "<<en<<"\n";
                //negative
            }else{
                ll st=max(in[ind].f-t[j].f+in[ind].s,in[ind+1].s);
                ll en=max(st-t[j+1].f+t[j].f,in[ind+1].s);
                if(t[j].s<=st&&t[j].s>=en){
                    ans++;
                }
                //cout<<st<<" "<<t[j].s<<" "<<en<<"\n";
            }
        }
        cout<<ans<<"\n";
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

