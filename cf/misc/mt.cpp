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
const int MAXN = 1e6+2;
//store test cases here
/*


*/
int bit[MAXN];
int n,q;
void add(int nod, int val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        bit[nod] += val;
}
int sum(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += bit[nod];
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        add(a,1);
    }
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t<0){
            //query abs(t)th element
            int lo=1;
            int hi=n;
            while(lo!=hi){
                int mi=(lo+hi)/2;
                if(sum(mi)>=-1*t){
                    hi=mi;
                }else{
                    lo=mi+1;
                }
            }
            add(lo,-1);
        }else{
            add(t,1);
        }
    }
    bool g=true;
    if(sum(n)){
        int hi=n;
        int lo=1;
        while(lo!=hi){
            int md=(lo+hi+1)/2;
            if(sum(n)-sum(md-1)){
                lo=md;
            }else{
                hi=md-1;
            }
        }
        cout<<(lo)<<'\n';
    }else{
        cout<<0<<'\n';
    }
    return 0;
}

