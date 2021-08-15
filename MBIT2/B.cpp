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
const int MAXN = 1e5+5;

//store test cases here
/*


*/ 
long long ans = 0;
int n;
vector<int> a;
vector<int> b;
vector<pii> eq;
int dist[MAXN+1];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    cin>>n;
    int e=0;
    int l=0;
    int r=0;
    int edge=0;
    for(int i=0;i<n;i++){
        int af;
        cin>>af;
        a.pb(af);
        dist[af]=i;
        if(i==n-1){
            edge=af;
        }
    }
    
    for(int i=0;i<n;i++){
        int af;
        cin>>af;
        b.pb(af);
        if(dist[af]==i&&i!=0){
            e++;
        }
        if(dist[af]>i){
            l++;
        }
        if(dist[af]<i){
            r++;
            eq.pb(mp(i-dist[af],af));
        }
        dist[af]=(dist[af]-i);
        ans+=abs(dist[af]);
    }
    int beg = 0;
    sort(eq.begin(),eq.end());
    for(int i=0;i<n-1;i++){
        //add left
        l+=e;
        e=0;
        ans+=l;
        //add right 
        if((n-abs(dist[b[i]]-i)-1)-abs(dist[b[i]]))
        //add equal
        while(eq[beg].f== i){
            r--;
            e++;
            beg++;
        }
        ans+=(n-abs(dist[b[i]]-i)-1)-abs(dist[b[i]]);
        
    }


    

    cout << ans << "\n";
    return 0;
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
