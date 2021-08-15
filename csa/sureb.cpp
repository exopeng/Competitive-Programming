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
const int MAXN = 2e5;
//store test cases here
/*


*/
int n;
vector<double> as;
vector<double> bs;
double ans = -1*INF;
pdd calc(pdd curr, int mid){
	pdd ret;
	ret.f=curr.f-(mid);
	ret.s=bs[mid]-(curr.s);
	return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	double a,b;
    	cin>>a>>b;
    	as.pb(a);
    	bs.pb(b);
    }
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    as.pb(0);
    bs.pb(0);
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    for(int i=1;i<=n;i++){
    	//cout<<as[i]<<"\n";
    	as[i]=as[i-1]+as[i]-1;
    }
    for(int i=1;i<=n;i++){
    	//cout<<bs[i]<<"\n";
    	bs[i]=bs[i-1]+bs[i]-1;
    }
    for(int i=0;i<=n;i++){
    	int lo=0;
    	int hi=n;
    	//not use bs
    	while(lo!=hi){
    		int mid=(lo+hi+1)/2;
    		pdd pr=calc(mp(as[i],i), mid);
    		if(pr.f>=pr.s){
    			lo=mid;
    		}else{
    			hi=mid-1;
    		}
    	}
    	pdd pr=calc(mp(as[i],i),lo);
    	ans=max(ans,min(pr.f,pr.s));
    	//check 3rd
    	if(lo+1<=n){
    		pdd pr1=calc(mp(as[i],i),lo+1);
    		ans=max(ans,min(pr1.f,pr1.s));
    	}
    }
	printf("%.4lf",ans);
	cout<<"\n";
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

