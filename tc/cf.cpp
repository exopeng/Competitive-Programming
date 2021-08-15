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
const long long INF = 1e10;
const long long MOD = 1e9+7;
const int MAXN = 2e3;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        ll n,k;cin>>n>>k;
        int fs=-1;
        int ss=-1;
        for(ll j=1;j<=pow(2*n,0.5);j++){
            if(n%j==0){
                ll a=j;
                ll b=(2*n)/j;
                //try both ways?
                if(a>b){
                    swap(a,b);
                }
                if((b-a+1)%2==0){
                    ll x=(b-a+1)/2;
                    ll y=b+(a-b-1)/2;
                    if(x<=y&&x>=1&&y<n){
                        fs=x,ss=y+1;
                    }
                }
                swap(a,b);
                if((b-a+1+2*INF)%2==0){
                    ll x=(b-a+1)/2;
                    ll y=b+(a-b-1)/2;
                    if(x<=y&&x>=1&&y<n){
                        fs=x,ss=y+1;
                    }
                }
            }
        }
        cout<<fs<<" "<<ss<<'\n';
    }    

}

