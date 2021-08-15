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
int dp[501][501][21];
int adj[501][501][4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		for(int t=1;t<=k;t++){
    			dp[i][j][t]=INF;
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m-1;j++){
    		int a;
    		cin>>a;
    		adj[i][j][1]=a;
    		adj[i][j+1][3]=a;
    	}
    }
    for(int i=0;i<n-1;i++){
    	for(int j=0;j<m;j++){
    		int a;
    		cin>>a;
    		adj[i][j][2]=a;
    		adj[i+1][j][0]=a;
    	}
    }
    for(int t=2;t<=k;t+=2){
    	for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(i){
	    			dp[i][j][t]=min(dp[i][j][t],2*adj[i][j][0]+dp[i-1][j][t-2]);
	    		}
	    		if(i!=n-1){
	    			dp[i][j][t]=min(dp[i][j][t],2*adj[i][j][2]+dp[i+1][j][t-2]);
	    		}
	    		if(j){
	    			dp[i][j][t]=min(dp[i][j][t],2*adj[i][j][3]+dp[i][j-1][t-2]);
	    		}
	    		if(j!=m-1){
	    			dp[i][j][t]=min(dp[i][j][t],2*adj[i][j][1]+dp[i][j+1][t-2]);
	    		}
	    	}
   	 	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(dp[i][j][k]!=INF){
    			cout<<dp[i][j][k];
    		}else{
    			cout<<-1;
    		}
    		if(j==m-1){
    			cout<<"\n";
    		}else{
    			cout<<" ";
    		}
    	}
    }
    return 0;
}

