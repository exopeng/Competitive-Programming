#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
const long long MOD = 998244353;
const int MAXN = 2e6;
//store test cases here
/*


*/
//0 is same size(wraparounds or singlets), 1 is isn't
ll dp[MAXN];
//mk stores transitions
ll mk[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    auto t1 = high_resolution_clock::now();
    n*=2;
    //number of factors optimization, each contribute +1
    //
    ll ct=0;
    for(int i=2;i<=n;i+=2){
        //for every new size can create new wraparound
        //starting from size 2, can add to size*2,size*3...
        for(int j=0;i+j*i<=n;j++){
            dp[i+j*i]=(dp[i+j*i]+1)%MOD;
        }
        //for every past config, can transition to x+2, x+4,... with wraparound
        dp[i]=(dp[i]+ct)%MOD;
        ct=(ct+dp[i])%MOD;
    }
    cout<<(dp[n])%MOD<<"\n";
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    //std::cout << ms_int.count() << "ms\n";
    return 0;
}

