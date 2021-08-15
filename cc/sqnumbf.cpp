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
ll gcd(ll a,ll b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
ll a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
   	//if gcd of all pairs=1, for each pair, check up to fourth root
   	for(int i=0;i<t;i++){
   		int n;
   		cin>>n;
   		for(int j=0;j<n;j++){
   			cin>>a[j];
   		}
   		ll as=1;
   		for(int j=0;j<n;j++){
   			for(int f=j+1;f<n;f++){
   				as=max(as,gcd(a[j],a[f]));
   			}
   		}
   		if(as==1){
   			for(int j=0;j<n;j++){
   				bool g=true;
   				for(ll f=2;f*f<=a[j];f++){
   					if(a[j]%(f*f)==0){
   						as=f;
   						g=false;
   						break;
   					}
   				}
   				if(!g){
   					break;
   				}
   			}
   		}
   		cout<<as<<"\n";
   	}
    return 0;
}

