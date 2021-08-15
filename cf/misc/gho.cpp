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
int g[101][101];
vector<pii> fs1;
vector<pii> fs2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int cd=0;
    int nf=0;
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if((i+j)%2==0){
    			fs1.pb(mp(i,j));
    		}else{
    			fs2.pb(mp(i,j));
    		}
    	}
    }
    for(int i=0;i<n*n;i++){
    	int a;
    	cin>>a;
    	int r1,r2,r3;
    	if(a==1){
    		if(fs2.size()==0){
    			r1=3,r2=fs1[fs1.size()-1].f,r3=fs1[fs1.size()-1].s;
    			fs1.pop_back();
    		}else{
    			r1=2,r2=fs2[fs2.size()-1].f,r3=fs2[fs2.size()-1].s;
    			fs2.pop_back();
    		}
    	}else if(a==2){
    		if(fs1.size()==0){
    			r1=3,r2=fs2[fs2.size()-1].f,r3=fs2[fs2.size()-1].s;
    			fs2.pop_back();
    		}else{
    			r1=1,r2=fs1[fs1.size()-1].f,r3=fs1[fs1.size()-1].s;
    			fs1.pop_back();
    		}
    	}else{
    		if(fs1.size()==0){
    			r1=2,r2=fs2[fs2.size()-1].f,r3=fs2[fs2.size()-1].s;
    			fs2.pop_back();
    		}else{
    			r1=1,r2=fs1[fs1.size()-1].f,r3=fs1[fs1.size()-1].s;
    			fs1.pop_back();
    		}
    	}
    	cout<<r1<<" "<<r2+1<<" "<<r3+1<<"\n";
    	cout.flush();
    }
    return 0;
}

