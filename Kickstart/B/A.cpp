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
int dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	string s;
    	cin>>n>>s;
    	dp[0]=1;

    	cout<<"Case #"<<(i+1)<<": 1";
    	for(int j=1;j<n;j++){
    		if(s[j]>s[j-1]){
    			dp[j]=1+dp[j-1];
    		}else{
    			dp[j]=1;
    		}
    		cout<<" "<<dp[j];
    	}
    	cout<<"\n";
    }
    return 0;
}

