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
int a[MAXN];
set<int,greater<int> > rs;
set<pii> os;
set<pii> ts;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int fs=0;
    vector<pii> bs;
    for(int i=0;i<n;i++){
        cin>>a[i];
        rs.is(i+1);
    }
    bool g=false;
    for(int i=n-1;i>-1;i--){
        if(a[i]==1){
            if(rs.size()==0){
                g=true;
                break;
            }else{
                bs.pb(mp(*rs.begin(),i+1));
                os.is(mp(*rs.begin(),i+1));
                rs.erase(rs.begin());
            }
        }else if(a[i]==2){
            if(os.size()==0){
                g=true;
                break;
            }else{
                bs.pb(mp(os.begin()->f,i+1));
                ts.is(mp(os.begin()->f,i+1));
                os.erase(os.begin());
            }
        }else if(a[i]==3){
            auto it=ts.rbegin();
            if(it==ts.rend()||rs.lb(it->f-1)==rs.end()){
                it=os.rbegin();
                if(it==os.rend()||rs.lb(it->f-1)==rs.end()){
                    g=true;
                    break;
                }else{
                    auto it1=rs.lb(it->f-1);
                    bs.pb(mp(*it1,i+1));
                    bs.pb(mp(*it1,it->s));
                    rs.erase(it1);
                    os.erase(mp(it->f,it->s));
                }
            }else{
                auto it1=rs.lb(it->f-1);
                bs.pb(mp(*it1,i+1));
                bs.pb(mp(*it1,it->s));
                rs.erase(it1);
                ts.erase(mp(it->f,it->s));
            }
        }
    }
    if(g){
        cout<<-1<<"\n";
    }else{
        cout<<bs.size()<<"\n";
        for(int i=0;i<bs.size();i++){
            cout<<bs[i].f<<" "<<bs[i].s<<"\n";
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

