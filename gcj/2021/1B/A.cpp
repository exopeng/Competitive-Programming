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
ll tpn=1;

bool gs(ll a,ll b,ll c){
	if((a%tph)/tpm==b/tpm && (b%tpm)/tps==c/tps){
		return true;
	}
	return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	ll a,b,c;
    	int h,m,s,ns;
    	cin>>a>>b>>c;
    	if(gs(a,b,c)){

    	}else if(gs(b,a,c)){

    	}else if(gs(a,c,b)){

    	}else if(gs(b,c,a)){

    	}else if(gs(c,b,a)){

    	}else{

    	}
    	cout<<"Case "
    }
    return 0;
}

