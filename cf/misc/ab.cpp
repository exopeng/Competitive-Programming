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
int g[55][55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,m,a,b;cin>>n>>m>>a>>b;
        int nx=n;
        int mx=m;
        int rx=0;
        int cx=0;
        if(a*n!=b*m){
            cout<<"NO"<<'\n';
        }else{
            cout<<"YES"<<'\n';
            while(n>=b&&m>=a){
                m-=a,n-=b;
                for(int j=rx;j<rx+b;j++){
                    for(int f=cx;f<cx+a;f++){
                        g[j][f]=1;
                    }
                }
                rx+=b,cx+=a;
            }
            for(int j=0;j<nx;j++){
                for(int f=0;f<mx;f++){
                    cout<<g[j][f];
                }
                cout<<'\n';
            }
            for(int j=0;j<nx;j++){
                for(int f=0;f<mx;f++){
                    g[j][f]=0;
                }
            }
        }
        
    }

    return 0;
}

