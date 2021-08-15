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
vector<int> adj[MAXN];
int p[MAXN];
stack<int> pa;
stack<int> fin;
bool f=true;
void cyc(int curr, int mr){
	if(p[curr]==0){
        pa.push(curr+1);
		p[curr]=mr;
		for(int i=0;i<adj[curr].size();i++){
			cyc(adj[curr][i],mr);
		}
		p[curr]=-1;
        pa.pop();
	} else if(p[curr]==mr){
        pa.push(curr+1);
        fin=pa;
        pa.pop();
		f=false;
	}
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    }
    int curr=1;
    for(int i=0;i<n;i++){
        if(f){
            cyc(i,curr);
            curr++;
        } else{
            break;
        }
    }
    if(f){
    	cout<<"IMPOSSIBLE"<<"\n";
    	return 0;
    }
    vector<int> path;
    int last = fin.top();
    path.pb(last);
    fin.pop();
    int sz=fin.size();
    for(int i=0;i<sz;i++){
        path.pb(fin.top());
        if(fin.top()==last) {
            break;
        }
        fin.pop();
    }
    cout<<path.size()<<"\n";
    for(int i=path.size()-1;i>-1;i--){
        cout<<path[i]<<" ";
    }
    cout<<"\n";
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

