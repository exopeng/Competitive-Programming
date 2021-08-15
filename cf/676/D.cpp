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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int c[6];
map<pii,long long> ms;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long x,y;
		cin>>x>>y;
		for(int j=0;j<6;j++){
			cin>>c[j];
		}
		queue<pair<pii,long long> > q;
		vector<int> xs={0,1,-1};
		vector<int> ys={0,1,-1};
		for(int j=0;j<3;j++){
			for(int e=0;e<3;e++){
				ms[mp(xs[j],ys[e])]=INF;
			}
		}
		q.push(mp(mp(1,1),c[0]));
		q.push(mp(mp(0,1),c[1]));
		q.push(mp(mp(-1,0),c[2]));
		q.push(mp(mp(-1,-1),c[3]));
		q.push(mp(mp(0,-1),c[4]));
		q.push(mp(mp(1,0),c[5]));
		ms[mp(0,0)]=0;
		while(!q.empty()){
			pair<pii,long long> ts=q.front();
			q.pop();
			if(ms.find(ts.f)!=ms.end()&&ts.s<ms[ts.f]){
				ms[ts.f]=ts.s;
				for(int j=0;j<3;j++){
					for(int e=0;e<3;e++){
						q.push(mp(mp(ts.f.f+xs[j],ts.f.s+ys[e]),ts.s+ms[mp(xs[j],ys[e])]));
					}
				}
			}
		}
		long long ans=0;
		if(x>=0&&y>=0){
			int fs=min(x,y);
			ans+=fs*ms[mp(1,1)];
			x-=fs;
			y-=fs;
			ans+=x*ms[mp(1,0)];
			ans+=y*ms[mp(0,1)];
		}else if(x<=0&&y<=0){
			int fs=max(x,y);
			ans+=fs*ms[mp(-1,-1)];
			x-=fs;
			y-=fs;
			ans+=abs(x)*ms[mp(-1,0)];
			ans+=abs(y)*ms[mp(0,-1)];
		}else if(x>=0&&y<=0){
			int fs=max(x,abs(y));
			ans+=fs*ms[mp(1,-1)];
			y+=fs;
			x-=fs;
			ans+=x*ms[mp(1,0)];
			ans+=abs(y)*ms[mp(0,-1)];
		}else{
			int fs=max(abs(x),y);
			ans+=fs*ms[mp(-1,1)];
			x+=fs;
			y-=fs;
			ans+=y*ms[mp(0,1)];
			ans+=abs(x)*ms[mp(-1,0)];
		}
		cout<<ans<<"\n";
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

