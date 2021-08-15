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
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        double h,c,t;cin>>h>>c>>t;
        if((h+c)/2>=t){
            cout<<2<<"\n";
        }else{
            //overflow
            int y=ceil((c-t)/(h+c-2*t));
            int z=(c-t)/(h+c-2*t);
            if(abs((z*h+(z-1)*c)/(2*z-1)-t)<=
                abs((y*h+(y-1)*c)/(2*y-1)-t)){
                cout<<(2*z-1)<<"\n";
            }else{
                cout<<(2*y-1)<<'\n';
            }
        }
    }
    return 0;
}

