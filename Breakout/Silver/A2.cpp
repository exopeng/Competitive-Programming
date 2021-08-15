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
int r,c;
char grid[51][51];
int d[51][51][8];
pii start;
int mi = INF;
void bfs(){
	//
	deque<pair<pii,int> > q;
	d[start.f][start.s][0]=1;
	d[start.f][start.s][1]=1;
	d[start.f][start.s][2]=1;
	d[start.f][start.s][3]=1;
	d[start.f][start.s][4]=1;
	d[start.f][start.s][5]=1;
	d[start.f][start.s][6]=1;
	d[start.f][start.s][7]=1;

	q.pb(mp(start,0));
	q.pb(mp(start,1));
	q.pb(mp(start,2));
	q.pb(mp(start,3));
	q.pb(mp(start,4));
	q.pb(mp(start,5));
	q.pb(mp(start,6));
	q.pb(mp(start,7));
	while(!q.empty()) {
        pair<pii,int> v = q.front();
        q.pop_front();
        if(v.f.f==r-1||v.f.f==0||v.f.s==c-1||v.f.s==0){
			mi=min(mi,d[v.f.f][v.f.s][v.s]);
		}
        vector<pair<pii,int> > adj;
        if(v.f.s+1<c){
        	adj.pb(mp(mp(v.f.f,v.f.s+1),2));
        }
        if(v.f.s-1>-1){
        	adj.pb(mp(mp(v.f.f,v.f.s-1),6));
        }
        if(v.f.f+1<r){
        	adj.pb(mp(mp(v.f.f+1,v.f.s),4));
        }
        if(v.f.f-1>-1){
        	adj.pb(mp(mp(v.f.f-1,v.f.s),0));
        }
        if(v.f.s+1<c&&v.f.f+1<r){
        	adj.pb(mp(mp(v.f.f+1,v.f.s+1),3));
        }
        if(v.f.s+1<c&&v.f.f-1>-1){
        	adj.pb(mp(mp(v.f.f-1,v.f.s+1),1));
        }
        if(v.f.s-1>-1&&v.f.f-1>-1){
        	adj.pb(mp(mp(v.f.f-1,v.f.s-1),7));
        }
        if(v.f.s-1>-1&&v.f.f+1<r){
        	adj.pb(mp(mp(v.f.f+1,v.f.s-1),5));
        }
       // cout<<"("<<v.f.f<<","<<v.f.s<<"):"<<
        for(auto edge:adj){
        	if(grid[edge.f.f][edge.f.s]=='_'){
        		if(v.s==edge.s){
 					if(d[v.f.f][v.f.s][v.s]<d[edge.f.f][edge.f.s][edge.s]){
                        d[edge.f.f][edge.f.s][edge.s]=d[v.f.f][v.f.s][v.s];
                        q.push_front((edge));
                    }
        		}else{
					if(d[v.f.f][v.f.s][v.s]+1<d[edge.f.f][edge.f.s][edge.s]){
                        d[edge.f.f][edge.f.s][edge.s]=d[v.f.f][v.f.s][v.s]+1;
                        q.pb((edge));
                    }
        		}
        	}
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c;

    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cin>>grid[i][j];
    		if(grid[i][j]=='Q'){
    			start.f=i;
    			start.s=j;
    		}
    	}
    }
    if(start.f==r-1||start.f==0||start.s==c-1||start.s==0){
		cout<<0<<"\n";
		return 0;
	}
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		d[i][j][0]=INF;
			d[i][j][1]=INF;
			d[i][j][2]=INF;
    		d[i][j][3]=INF;
    		d[i][j][4]=INF;
    		d[i][j][5]=INF;
    		d[i][j][6]=INF;
    		d[i][j][7]=INF;
    	}
    }
    bfs();
   
    if(mi==INF){
    	cout<<"-1"<<"\n";
    } else{
    	cout<<mi<<"\n";
    }
    /*
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<<d[i][j]<<" ";
    	}
    	cout<<"\n";
    }
	*/
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

