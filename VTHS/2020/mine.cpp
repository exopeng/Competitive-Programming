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
const int MAXN = 31;
//store test cases here
/*


*/
int n,m,e;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
pii start1,start2;
pii end;
void bfs() {
	queue<pair<pii,pii> > q;
	q.push(mp(start1,start2));
	while(!q.empty()){
		pii bo=q.top().f;
		pii cr=q.top().s;
		q.pop();
		int move = 0;
		int dx={0,0,1,-1};
		int dy={1,-1,0,0};
		pii minx=mp(-1,-1);
		pii miny=mp(-1,-1);
		vector<pii> v;
		vector<pii> h;
		bool hori=false;
		bool vert=false;
		for(int i=0;i<4;i++){
			pii ne = mp(cr.f+dx,cr.f+dy);
			if(ne.f==n||ne.f==m||ne.f<0||ne.s<0|| grid[ne.f][ne.s]==0){

			} else{
				if(i<2){
					vert=true;
					v.pb(ne);
				}else{
					hori=true;
					h.pb(ne);
				}
			}
		}
		if(v.size()>1){
			int fs=abs(v[0].f-bo.f);
			int ff=abs(v[1].f-bo.f);
			if(cr.f==bo.f){
				v.clear();
			} else if(fs < ff){
				pii tem = v[1];
				v.clear();
				v.pb(tem);
			}
		}
		if(h.size()>1){
			int fs=abs(h[0].s-bo.s);
			int ff=abs(h[1].s-bo.s);
			if(cr.s==bo.s){
				v.clear();
			} else if(fs < ff){
				pii tem = h[1];
				h.clear();
				h.pb(tem);
			}
		}
		if(h.size() ==1&&v.size()==1){
			int fs=abs(h[0].s-bo.s);
			int ff=abs(v[0].f-bo.f);
			mx=v[0];
			if(fs < ff){
				mx=h[0];
			} else if(ff==fs){
				double dist1=sqrt(pow(v[0].f-b.f,2)+pow(v[0].s-b.s,2));
				double dist2=sqrt(pow(h[0].f-b.f,2)+pow(h[0].s-b.s,2))

				if(dist1==dist2){
					
				}
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>e;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		char c;
    		cin>>c;
    		if(c=='P'){
    			start1.f=i,start1.s=j;
    		}
    		if(c=='C'){
    			start2.f=i,start2.s=j;
    		}
    		if(c=='E'){
    			end.f=i,end.s=j;
    		}
    		if(c=='X'){
    			grid[i][j]=1;
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		for(int e=0;e<n;e++){
    			for(int f=0;f<m;f++){
    				dp[i][j][e][f]=INF;
    			}
    		}
    	}
    }
    dp[start1.f][start1.s][start2.f][start2.s]=0;
    bfs();
    long long ans=INF;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ans=min(ans,dp[end.f][end.s][i][j]);
    	}
    }
    cout<<ans<<"\n";
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

