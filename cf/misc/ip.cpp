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
ll dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,x;
        string s;
        cin>>n>>x>>s;
        for(int j=1;j<=n;j++){
            dp[j]=dp[j-1];
            if(s[j-1]=='0'){
                dp[j]++;
            }
        }
        ll as=0;
        set<ll> tk;
        for(ll j=0;j<n;j++){
            if(2*dp[n]-n!=0&&(x+j-2*dp[j])%(2*dp[n]-n)==0
                &&(x+j-2*dp[j])/(2*dp[n]-n)>=0){
                tk.is(j+n*(x+j-2*dp[j])/(2*dp[n]-n));
            }
        }
        if(dp[n]==n/2&&n%2==0){
            set<ll> ss;
            for(int j=1;j<=n;j++){
                ss.is(dp[j]-(j-dp[j]));
            }
            if(ss.find(x)!=ss.end()){
                cout<<-1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else{
            cout<<tk.size()<<'\n';
        }

    }
    return 0;
}

