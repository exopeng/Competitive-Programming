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
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 1e4;
//store test cases here
/*


*/
int n;
int q;
map<int,int> ms[MAXN];
vector<pii> mr[MAXN];
int ct[MAXN];
map<char,int> mt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string st;
    cin>>st;
    for(int i=0;i<n;i++){
    	mt[st[i]]=i;
    }
    for(int i=0;i<n;i++){
    	ct[mt[st[i]]]++;
    	mr[mt[st[i]]].pb(mp(i, ct[mt[st[i]]]));
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<mr[i].size();j++){
    		for(int e=j;e<mr[i].size();e++){
    			pii l=mr[i][j];
    			pii r=mr[i][e];
    			ms[i][r.f-l.f-(r.s-l.s+1)+1]=max(ms[i][r.f-l.f-(r.s-l.s+1)+1], (r.s-l.s+1));
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(auto it=ms[i].begin();it!=ms[i].end();it++){
    		for(auto its=next(it);its!=ms[i].end();its++){
    			ms[i][its->f]=max(its->s,it->s);
    		}
    	}
    }
    cin>>q;
    for(int i=0;i<q;i++){
    	//check if greater
    	int a;
    	char b;
    	cin>>a>>b;
    	if(mt.find(b)==mt.end()){
    		cout<<a<<"\n";
    	}else{
    		if(n-ct[mt[b]]<=a){
	    		cout<<n<<"\n";
	    	} else{
	    		auto it=prev(ms[mt[b]].ub(a));
	    		cout<<it->s+a<<"\n";
	    	}
    	}
    	
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

