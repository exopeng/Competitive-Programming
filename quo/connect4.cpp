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
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int grid[100][100];
int nex[100];
bool rc(int i, int j){
	int sum=0;
	for(int f=0;f<4;f++){
		sum+=grid[i][j+f];
	}
	if(sum==4||sum==-4){
		return true;
	}
	return false;
}
bool cr(int i, int j){
	int sum=0;
	for(int f=0;f<4;f++){
		sum+=grid[i+f][j];
	}
	if(sum==4||sum==-4){
		return true;
	}
	return false;
}
bool dc(int i,int j){
	int sum=0;
	for(int f=0;f<4;f++){
		sum+=grid[i+f][j+f];
	}
	if(sum==4||sum==-4){
		return true;
	}
	return false;
}
bool dc1(int i,int j){
	int sum=0;
	for(int f=0;f<4;f++){
		sum+=grid[i+f][j-f];
	}
	if(sum==4||sum==-4){
		return true;
	}
	return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    for(int i=0;i<42;i++){
    	int a;
    	cin>>a;
    	a--;
    	if(i%2==0){
    		grid[nex[a]][a]=1;
    	}else{
    		grid[nex[a]][a]=-1;
    	}
    	for(int j=max(0,a-3);j<=a&&j+3<7;j++){
    		if(rc(nex[a],j)){
    			if(i%2==0){
    				cout<<"RED "<<i+1<<"\n";
    			}else{
    				cout<<"YELLOW "<<i+1<<"\n";
    			}
    			return 0;
    		}
    	}
    	for(int j=max(0,nex[a]-3);j<=nex[a]&&j+3<6;j++){
    		if(cr(j,a)){
    			if(i%2==0){
    				cout<<"RED "<<i+1<<"\n";
    			}else{
    				cout<<"YELLOW "<<i+1<<"\n";
    			}
    			return 0;
    		}
    	}
    	
    	for(int j=3;j>=0;j--){
    		//reverse diag
    		int ci=nex[a]-j;
    		int cj=a-j;
    		if(ci>=0&&cj>=0&&ci+3<6&&cj+3<7){
    			if(dc(ci,cj)){
    				if(i%2==0){
    					cout<<"RED "<<i+1<<"\n";
	    			}else{
	    				cout<<"YELLOW "<<i+1<<"\n";
	    			}
	    			return 0;
    			}
    		}
    	}
    	for(int j=3;j>=0;j--){
    		//reverse diag
    		int ci=nex[a]-j;
    		int cj=a+j;
    		if(ci>=0&&cj>=0&&ci+3<6&&cj-3>=0){
    			if(dc1(ci,cj)){
    				if(i%2==0){
    					cout<<"RED "<<i+1<<"\n";
	    			}else{
	    				cout<<"YELLOW "<<i+1<<"\n";
	    			}
	    			return 0;
    			}
    		}
    	}
    	
    	nex[a]++;
    }
    cout<<"DRAW"<<"\n";
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

