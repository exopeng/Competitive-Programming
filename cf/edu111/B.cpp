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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        if(a>=0&&b>=0||a<=0&&b>=0){
            cout<<(b+a)*n<<'\n';
        }else{
            vector<int> ws;
            vector<int> bs;
            for(int j=0;j<n;j++){
                int ct=1;
                if(s[j]=='1'){
                    while(j+1<n&&s[j+1]=='1'){
                        ct++;j++;
                    }
                    bs.pb(ct);
                }else{
                    while(j+1<n&&s[j+1]=='0'){
                        ct++;j++;
                    }
                    ws.pb(ct);
                }
            }
            cout<<(a*n+b*(1+min((int)ws.size(),(int)bs.size())))<<'\n';
        }
    }
    return 0;
}

