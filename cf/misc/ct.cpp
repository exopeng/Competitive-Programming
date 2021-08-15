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
const int MAXN = 3e5;
//store test cases here
/*


*/
ll binpow(ll a,ll b,ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll ps[MAXN];
ll dp[MAXN];
//(m-2 C m-2),(m-1 C m-2)...,(n C m-2)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<int> a;
        for(int j=0;j<n;j++){
            int b;
            cin>>b;
            a.pb(b);
        }
        if(m==1){
            cout<<n<<"\n";
            continue;
        }
        sort(a.begin(),a.end());
        ll as=0;
        dp[0]=1;
        ps[0]=1;
        for(int j=1;j<=n;j++){
            dp[j]=((dp[j-1]*(m-2+j)%MOD)*binpow(j,MOD-2,MOD))%MOD;
            ps[j]=(ps[j-1]+dp[j])%MOD;
        }
        for(int j=0;j<n;j++){
            auto it=lb(a.begin(),a.end(),a[j]-k);
            if(it==a.end()||(it-a.begin())>=j||j-(it-a.begin())-1<m-2){

            }else{
                as=(as+ps[j-(it-a.begin())-1-(m-2)])%MOD;
            }
        }
        cout<<as<<"\n";
    }
    return 0;
}

