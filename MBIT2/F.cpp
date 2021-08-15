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
const int MAXN = 1e3+5;

//store test cases here
/*


*/ 
long long ans = 0;
int n,m,k,b;
int grid[MAXN][MAXN];
//0 is e, 1 is w
set<pii> r[MAXN];
//0 is n, 1 is s
set<pii> c[MAXN];
string be;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    cin>>n>>m>>k>>b;
    cin>>be;
    for(int i=0;i<k;i++){
        int f,y;
        cin>>f>>y;
        grid[f][y]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && j!=m-1&&grid[i][j+1]==0){
                r[i].is(mp(j+1,0));
            }
            if(grid[i][j]==1 && j!=0&&grid[i][j-1]==0){
                                    r[i].is(mp(j-1,1));

            }
            if(grid[i][j]==1 && i!=n-1&&grid[i+1][j]==0){
                if(c[i].find(mp(i+1,1)) == c[i].end()){
                    c[i].is(mp(i+1,0));
                }
            }
            if(grid[i][j]==1 && i!=0&&grid[i-1][j]==0){
                if(c[i].find(mp(i-1,1)) == c[i].end()){
                    c[i].is(mp(i-1,1));
                }
            }
        }
    }

    for(int i=0;i<be.size();i++){
        char c = be[i];
        if(c=='N'){
            for(int j=0;j<m;j++){
                vector<pii> del;
                for(auto it=c[j].begin();it!=c[j].end();it++){
                    if(it->second==0){
                        if(grid[it->first][j]==0){
                            grid[it->first][j]==1;
                            if()
                        }
                    }
                }
            }
        }
        if(c=='S'){

        }
        if(c=='E'){

        }
        if(c=='W'){

        }
    }
    

    cout << ans/2 << "\n";
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
