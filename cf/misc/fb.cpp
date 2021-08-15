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
ll tt[61];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        ll sm=0;
        ll as=0;
        for(int j=0;j<m;j++){
            ll a;
            cin>>a;
            tt[(int)log2(a)]++;
            sm+=a;
        }
        if(sm<n){
            cout<<-1<<'\n';
        }else{
            for(int j=0;j<61;j++){
                if(n%2){
                    if(tt[j]==0){
                        int ix=j;
                        while(tt[ix]==0){
                            ix++;
                            as++;
                        }
                        tt[ix]--;
                        for(int f=ix-1;f>j;f--){
                            tt[f]++;
                        }
                        tt[j]+=2;
                    }
                    tt[j]--;
                }
                tt[j+1]+=tt[j]/2;
                n/=2;
            }
            cout<<as<<'\n';
        }
        for(int j=0;j<61;j++){
            tt[j]=0;
        }
    }
    return 0;
}

