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
const int MAXN = 2e7;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	ll x,y;
    	cin>>x>>y;
        ll as=0;
        ll z=pow(x+1,0.5);
        for(ll j=1;j<=min(z,y);j++){
            as+=j-1;
        }
        ll f=(y+1)/x;
        ll m=(z+1)/x;
        if(z<y){
            as+=(f*(f-1)*x)/2+f*(y-f*x+2)-(m*(m-1)*x)/2-m*(z-m*x+2);
        }
        /*
        for(ll j=min(z,y)+1;j<=y;j++){
            as+=x/(j+1);
        }
        */

        /*
        for(ll j=1;j<=y;j++){
            as+=min(x/(j+1),j-1);
            if(j-1<=x/(j+1)){
                cout<<1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }
        */
        cout<<as<<'\n';
    }
    return 0;
}

