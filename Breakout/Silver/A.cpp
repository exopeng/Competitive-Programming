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
int moves[51][51][8];
pii start;
int mi = INF;
void bfs(){
	//
	deque<pair<pii,int> > q;
	moves[start.f][start.s][0]=1;
	moves[start.f][start.s][1]=1;
	moves[start.f][start.s][2]=1;
	moves[start.f][start.s][3]=1;
	moves[start.f][start.s][4]=1;
	moves[start.f][start.s][5]=1;
	moves[start.f][start.s][6]=1;
	moves[start.f][start.s][7]=1;

	q.pb(mp(start,0));
	q.pb(mp(start,1));
	q.pb(mp(start,2));
	q.pb(mp(start,3));
	q.pb(mp(start,4));
	q.pb(mp(start,5));
	q.pb(mp(start,6));
	q.pb(mp(start,7));
	while(!q.empty()){
		pair<pii,int> temp1 = q.front();
		int temp2 = temp1.s;
		pii temp = temp1.f;
		q.pop_front();
		if(temp.f==r-1||temp.f==0||temp.s==c-1||temp.s==0){
			mi=min(mi,moves[temp.f][temp.s][temp2]);
		}
		//add if not equal to length
		int add1=1;
		int add2=1;
		int add3=1;
		int add4=1;
		int add5=1;
		int add6=1;
		int add7=1;
		int add8=1;
		if(temp2==2){
			add1=0;
		}
		if(temp2==6){
			add2=0;
		}
		if(temp2==0){
			add3=0;
		}
		if(temp2==4){
			add4=0;
		}
		if(temp2==1){
			add5=0;
		}
		if(temp2==7){
			add6=0;
		}
		if(temp2==3){
			add7=0;
		}
		if(temp2==5){
			add8=0;
		}
		//right
		if(temp.s+1<c&&grid[temp.s][temp.s+1]=='_'&& moves[temp.f][temp.s][temp2]+add1 < moves[temp.f][temp.s+1][2]){
			moves[temp.f][temp.s+1][2]=moves[temp.f][temp.s][temp2]+add1;
			if(temp2==2){
				q.push_front(mp(mp(temp.f,temp.s+1),2));
			}else{
				q.pb(mp(mp(temp.f,temp.s+1),2));
			}
		}
		//left
		if(temp.s-1>-1&&grid[temp.f][temp.s-1]=='_'&&moves[temp.f][temp.s][temp2]+add2 < moves[temp.f][temp.s-1][6]){
			moves[temp.f][temp.s-1][6]=moves[temp.f][temp.s][temp2]+add2;
			if(temp2==6){
				q.push_front(mp(mp(temp.f,temp.s-1),6));
			}else{
				q.pb(mp(mp(temp.f,temp.s-1),6));
			}
			//dont push if less than or equal to 
		}
		//up
		if(temp.f-1>-1&&grid[temp.f-1][temp.s]=='_'&&moves[temp.f][temp.s][temp2]+add3 < moves[temp.f-1][temp.s][0]){
			moves[temp.f-1][temp.s][0]=moves[temp.f][temp.s][temp2]+add3;
			if(temp2==0){
				q.push_front(mp(mp(temp.f-1,temp.s),0));
			}else{
				q.pb(mp(mp(temp.f-1,temp.s),0));
			}
		}
		//down
		if(temp.f+1<r&&grid[temp.f+1][temp.s]=='_'&&moves[temp.f][temp.s][temp2]+add4 < moves[temp.f+1][temp.s][4]){
			moves[temp.f+1][temp.s][4]=moves[temp.f][temp.s][temp2]+add4;
			if(temp2==4){
				q.push_front(mp(mp(temp.f+1,temp.s),4));
			}else{
				q.pb(mp(mp(temp.f+1,temp.s),4));
			}
		}
		//up right
		if(temp.f-1>-1&&temp.s+1<c&&grid[temp.f-1][temp.s+1]=='_'&&moves[temp.f][temp.s][temp2]+add5 < moves[temp.f-1][temp.s+1][1]){
			moves[temp.f-1][temp.s+1][1]=moves[temp.f][temp.s][temp2]+add5;
			if(temp2==1){
				q.push_front(mp(mp(temp.f-1,temp.s+1),1));
			}else{
				q.pb(mp(mp(temp.f-1,temp.s+1),1));
			}
		}
		//up left
		if(temp.f-1>-1&&temp.s-1>-1&&grid[temp.f-1][temp.s-1]=='_'&&moves[temp.f][temp.s][temp2]+add6 < moves[temp.f-1][temp.s-1][7]){
			moves[temp.f-1][temp.s-1][7]=moves[temp.f][temp.s][temp2]+add6;
			if(temp2==7){
				q.push_front(mp(mp(temp.f-1,temp.s-1),7));
			}else{
				q.pb(mp(mp(temp.f-1,temp.s-1),7));
			}
		}
		//down right
		if(temp.f+1<r&&temp.s+1<c&&grid[temp.f+1][temp.s+1]=='_'&&moves[temp.f][temp.s][temp2]+add7 < moves[temp.f+1][temp.s+1][3]){
			moves[temp.f+1][temp.s+1][3]=moves[temp.f][temp.s][temp2]+add7;
			if(temp2==3){
				q.push_front(mp(mp(temp.f+1,temp.s+1),3));
			}else{
				q.pb(mp(mp(temp.f+1,temp.s+1),3));
			}
		}
		//down left
		if(temp.f+1<r&&temp.s-1>-1&&grid[temp.f+1][temp.s-1]=='_'&&moves[temp.f][temp.s][temp2]+add8 < moves[temp.f+1][temp.s-1][5]){
			moves[temp.f+1][temp.s-1][5]=moves[temp.f][temp.s][temp2]+add8;
			if(temp2==5){
				q.push_front(mp(mp(temp.f+1,temp.s-1),5));
			}else{
				q.pb(mp(mp(temp.f+1,temp.s-1),5));
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
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		moves[i][j][0]=INF;
    		moves[i][j][1]=INF;
    		moves[i][j][2]=INF;
    		moves[i][j][3]=INF;
    		moves[i][j][4]=INF;
    		moves[i][j][5]=INF;
    		moves[i][j][6]=INF;
    		moves[i][j][7]=INF;
    	}
    }
    bfs();
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<< moves[i][j][0]<<" ";
    	}
    	cout<<"\n";
    }
    	cout<<"\n";
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<< moves[i][j][2]<<" ";
    	}
    	    	cout<<"\n";

    }
    	cout<<"\n";
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<< moves[i][j][4]<<" ";
    	}
    	    	cout<<"\n";

    }
    	cout<<"\n";
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<< moves[i][j][6]<<" ";
    	}
    	    	cout<<"\n";

    }
    	cout<<"\n";
    if(mi==INF){
    	cout<<"-1"<<"\n";
    } else{
    	cout<<mi<<"\n";
    }
    /**
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<<moves[i][j]<<" ";
    	}
    	cout<<"\n";
    }
	**/
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

