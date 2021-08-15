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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x,y;
        cin>>n>>x>>y;
        int mx=1;
        int mn=0;
        int kx=x-1;
        int ky=y-1;
        int tkx=n-x;
        int tky=n-y;
        mx+=min(kx,tky)+min(ky,tkx);
        kx-=min(kx,tky),ky-=min(ky,tkx);
        mx+=min(kx,ky);

        if(x-1==tky){
            mn+=max(0,x-2);
            tky-=max(0,x-2);
        }else{
            //which one is +1
            //if x-1 greater it should take more
            mn+=min(x-1,tky);
            tky-=min(x-1,tky);
        }
        if(y-1==tkx){
            mn+=max(0,y-2);
            tkx-=max(0,y-2);
        }else{
            mn+=min(y-1,tkx);
            tkx-=min(y-1,tkx);
        }
        mn+=min(tkx,tky);
        cout<<n-mn<<" "<<mx<<'\n';
    }
    return 0;
}

