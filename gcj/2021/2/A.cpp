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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool bd=true;
    int t,n;
    cin>>t>>n;
    for(int i=0;i<t;i++){
    	for(int j=1;j<n;j++){
    		cout<<"M "<<j<<" "<<n<<"\n";
    		cout.flush();
    		int a;
    		cin>>a;
    		if(a==-1){
    			bd=false;
	    		break;
	    	}
    		if(a!=j){
    			cout<<"S "<<j<<" "<<a<<"\n";
    			cout.flush();
    			cin>>a;
    			if(a==-1){
	    			bd=false;
		    		break;
		    	}
    		}
    	}
    	if(!bd){
    		break;
    	}
    	cout<<"D"<<"\n";
    	cout.flush();
    	int b;
    	cin>>b;
    	if(b==-1){
    		break;
    	}
    }
    return 0;
}

