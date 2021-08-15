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
long double a[MAXN];
long double b[MAXN];
long double ab[MAXN*2];
long double mt[MAXN*2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<=2*n;i++){
		ab[i]=1;
		mt[i]=1;
    }
    for(int i=0;i<n;i++){
    	cin>>a[n-1-i];
    }
    for(int i=0;i<n;i++){
    	cin>>b[n-1-i];
    }
    for(int i=0;i<n;i++){
    	mt[i]*=a[i];
    	mt[i+n]/=a[i];
    }
    for(int i=0;i<n;i++){
    	mt[i]*=b[i];
    	mt[i+n]/=b[i];
    }
    long double cs=1;
    for(int i=0;i<2*n-1;i++){
    	cout<<mt[i]<<" ";
    	cs*=mt[i];
    	ab[i]=cs;
    }
    cout<<2*n-1<<"\n";
    for(int i=2*n-2;i>-1;i--){
    	cout<<setprecision(9)<<ab[i]<<"\n";
    }


    return 0;
}

