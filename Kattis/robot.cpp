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
char grid[8][8];
//NESW->0123
int d[8][8][4];
string p[8][8][4];
void dijkstrapq() {
    for(int i=0;i<8;i++){
    	for(int j=0;j<8;j++){
    		for(int k=0;k<4;k++){
	    		 d[i][j][k]=INF;
	    		 p[i][j][k]="-1";
    		}
    	}
    }
    d[7][0][1] = 0;
    p[7][0][1]="-1";
    //first is dist, second first is x,y, second second is direction
    priority_queue< pair<int,pair<pii,int> >, vector<pair<int,pair<pii,int>> >, greater<pair<int,pair<pii,int> >> > q;
    q.push({0, mp(mp(7,0),1)});
    while (!q.empty()) {
        int vx = q.top().s.f.f;
        int vy=q.top().s.f.s;
        int dir = q.top().s.s;
        int d_v = q.top().f;
        q.pop();
        if (d_v != d[vx][vy][dir])
            continue;
        int dr[2]={1,3};
        string dri[2]={"R","L"};
        for(int i=0;i<2;i++){
        	if (d[vx][vy][dir] + 1 < d[vx][vy][(dir+dr[i])%4]) {
                d[vx][vy][(dir+dr[i])%4] = d[vx][vy][dir] + 1;
                p[vx][vy][(dir+dr[i])%4] = dri[i];
                q.push({d[vx][vy][(dir+dr[i])%4], mp(mp(vx,vy),(dir+dr[i])%4)}); 
        	}
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
        	int plus=1;
        	string ch="";
        	if(dir==i){
        		if(vx+dx[i]<8&&vx+dx[i]>-1&&vy+dy[i]<8&&vy+dy[i]>-1) {
	        		if(grid[vx+dx[i]][vy+dy[i]]!='C'){
	        			if(grid[vx+dx[i]][vy+dy[i]]=='I'){
	        				plus++;
	        				ch="X";
	        			}
	        			if (d[vx][vy][dir] + plus < d[vx+dx[i]][vy+dy[i]][dir]) {
			                d[vx+dx[i]][vy+dy[i]][dir] = d[vx][vy][dir] + plus;
			                p[vx+dx[i]][vy+dy[i]][dir] = ch+"F";
			                q.push({d[vx+dx[i]][vy+dy[i]][dir], mp(mp(vx+dx[i],vy+dy[i]),dir)}); 
				        }
	        		}
	        	}
        	}
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   	int x,y;
    for(int i=0;i<8;i++){
    	for(int j=0;j<8;j++){
    		cin>>grid[i][j];
    		if(grid[i][j]=='D'){
    			x=i;
    			y=j;
    		}
    	}
    }
    dijkstrapq();
    int sv=INF;
    int st=0;
    for(int i=0;i<4;i++){
    	if(d[x][y][i]<sv){
    		sv=d[x][y][i];
    		st=i;
    	}
    }
    if(sv==INF){
    	cout<<"no solution"<<"\n";
    }else{
    	vector<string> path;
    	while(p[x][y][st]!="-1"){
    		path.pb(p[x][y][st]);
    		if(p[x][y][st][p[x][y][st].size()-1]=='F'){
    			if(st==0){
					x++;
				}else if(st==1){
					y--;
				}else if(st==2){
					x--;
				}else if(st==3){
					y++;
				}
    		}else {
    			if(p[x][y][st]=="L"){
    				st = (st+1) % 4;
    			}else{
    				st = (st+3) % 4;
    			}
    		}
    	}
    	reverse(path.begin(),path.end());
    	for(int i=0;i<path.size();i++){
    		cout<<path[i];
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

