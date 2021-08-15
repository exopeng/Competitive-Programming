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
const int MAXN = 1e2+5;
//store test cases here
/*


*/
bool dp[MAXN*2000][MAXN];
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int sm=0;
    int od=0;
    int ix=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sm+=a[i];
        if(a[i]%2){
            od=a[i];
            ix=i;
        }
    }
    dp[0][0]=true;
    for(int i=0;i<=sm;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]){
                dp[i][j+1]=true;
                if(i+a[j+1]<MAXN*2000){
                    dp[i+a[j+1]][j+1]=true;
                }
            }
        }
    }
    int as=0;
    if(sm%2==1||sm%2==0&&!dp[sm/2][n]){
        cout<<0<<"\n";
    }else{
        cout<<1<<'\n';
        if(od){
            cout<<ix<<'\n';
        }else{
            while(true){
                ix=0;
                for(int i=1;i<=n;i++){
                    a[i]/=2;
                    if(a[i]%2){
                        ix=i;
                        break;
                    }
                }
                if(ix){
                    cout<<ix<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}

