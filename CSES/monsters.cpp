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
const int MAXN = 1e3+1;
//store test cases here
/*


*/
int n,m;
char grid[MAXN][MAXN];
bool taken[MAXN][MAXN];
bool taken1[MAXN][MAXN];
char path[MAXN][MAXN];
pii valid;
void bfs(pair<pii,pii> start,vector<pair<pii,pii> > mon) {
	queue<pair<pii,pii> > q;
	for(int i=0;i<mon.size();i++){
		q.push(mon[i]);
	}
	q.push(start);
	while(!q.empty()){
		//s.f is i, s.s is j
		pair<pii,pii> curr = q.front();
		q.pop();
		if(curr.f.f==1) {
			if(!taken[curr.s.f][curr.s.s] && !taken1[curr.s.f][curr.s.s]){
				taken[curr.s.f][curr.s.s]=true;
				if(curr.f.s!=0) {
					path[curr.s.f][curr.s.s]=(char)curr.f.s;
				}
				if (curr.s.s==m-1||curr.s.s==0||curr.s.f==n-1||curr.s.f==0) {
					valid = mp(curr.s.f,curr.s.s);
					//cout<<"here";
					break;
				}
				if(curr.s.s+1<m && grid[curr.s.f][curr.s.s+1]=='.') {
					q.push(mp(mp(curr.f.f,(int)'R'),mp(curr.s.f,curr.s.s+1)));
				}
				if(curr.s.s-1>-1 && grid[curr.s.f][curr.s.s-1]=='.') {
					q.push(mp(mp(curr.f.f,(int)'L'),mp(curr.s.f,curr.s.s-1)));
				}
				if(curr.s.f+1<n && grid[curr.s.f+1][curr.s.s]=='.') {
					q.push(mp(mp(curr.f.f,(int)'D'),mp(curr.s.f+1,curr.s.s)));
				}
				if(curr.s.f-1>-1 && grid[curr.s.f-1][curr.s.s]=='.') {
					q.push(mp(mp(curr.f.f,(int)'U'),mp(curr.s.f-1,curr.s.s)));
				}
			} 
		} else {
			if(!taken1[curr.s.f][curr.s.s]){
				taken1[curr.s.f][curr.s.s]=true;
				if(curr.s.s+1<m && grid[curr.s.f][curr.s.s+1]!='#') {
					q.push(mp(mp(curr.f.f,curr.f.s),mp(curr.s.f,curr.s.s+1)));
				}
				if(curr.s.s-1>-1 && grid[curr.s.f][curr.s.s-1]!='#') {
					q.push(mp(mp(curr.f.f,curr.f.s),mp(curr.s.f,curr.s.s-1)));
				}
				if(curr.s.f+1<n && grid[curr.s.f+1][curr.s.s]!='#') {
					q.push(mp(mp(curr.f.f,curr.f.s),mp(curr.s.f+1,curr.s.s)));
				}
				if(curr.s.f-1>-1 && grid[curr.s.f-1][curr.s.s]!='#') {
					q.push(mp(mp(curr.f.f,curr.f.s),mp(curr.s.f-1,curr.s.s)));
				}
			} 
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    pair<pii,pii> start;
    vector<pair<pii,pii> > mon;
    valid = mp(-1,-1);
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>grid[i][j];
    		if(grid[i][j]=='A'){
    			start.f.f=1;
    			start.f.s=0;
    			start.s.f=i;
    			start.s.s=j;
    		} 
    		if(grid[i][j]=='M'){
    			mon.pb(mp(mp(0,0),mp(i,j)));
    		}
    		path[i][j]='*';
    	}
    }
    /*
    for(int i=0;i<mon.size();i++){
    	cout<<mon[i].s.f << " " << mon[i].s.s<<"\n";
    }
    */
    //cout<<start.s.f<<" "<<start.s.s;
    bfs(start,mon);
    /*
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<path[i][j];
    	}
    	cout<<"\n";
    }
    */
    //cout<<valid.f<<" "<<valid.s<<"\n";
    
    if(valid.f==-1){
    	cout<<"NO"<<"\n";
    }else {
    	vector<char> p;
    	while(grid[valid.f][valid.s]!='A'){
    		p.pb(path[valid.f][valid.s]);
    		if(path[valid.f][valid.s]=='L'){
    			valid.s++;
    		} else if (path[valid.f][valid.s]=='R') {
    			valid.s--;
    		} else if (path[valid.f][valid.s]=='U') {
    			valid.f++;
    		} else if (path[valid.f][valid.s]=='D') {
    			valid.f--;
    		}
    	}
    	cout<<"YES"<<"\n";
    	cout<<p.size()<<"\n";
    	for(int i=p.size()-1;i>-1;i--){
    		cout<<p[i];
    	}
    	cout<<"\n";
    }
    
    
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

