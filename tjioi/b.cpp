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
const long long INF = 1e18+100;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
ll sm[MAXN];
vector<ll> mn(MAXN,-1*INF);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,x,y;
    cin>>n>>q>>x>>y;
    mn[0]=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==1){
            sm[i]-=x;
        }else{
            sm[i]+=y;
        }
        sm[i]+=sm[i-1];
        mn[i]=min(mn[i-1],sm[i]);
    }
    for(int i=0;i<q;i++){
        int e;
        cin>>e;
        auto it=ub(mn.begin(),mn.end(),-1*e,greater<ll>());
        cout<<(it-mn.begin()-1)<<"\n";
    }
    return 0;
}

