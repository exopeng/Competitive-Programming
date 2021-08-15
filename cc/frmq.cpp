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
int st[MAXN+1][26];
int lg[MAXN+1];
int a[MAXN];
int nx[MAXN];
int ny[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m>>nx[0]>>ny[0];
    x=nx[0],y=ny[0];
    for(int i=0;i<n;i++)
        st[i][0]=a[i];
    for(int j=1;j<=25;j++)
        for(int i=0;i+(1<<j)<=n;i++)
            st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    lg[1]=0;
    ll as=0;
    for(int i=1;i<=n;i++){
        nx[i]=(nx[i-1]+7)%(n-1);
        ny[i]=(ny[i-1]+11)%n;
    }
    for(int i=2;i<=MAXN;i++)
        lg[i]=lg[i/2]+1;
    int i1=0;
    int i2=0;
    for(int i=0;i<m;i++){
        int l=min(x,y);int r=max(x,y);
        int j=lg[r-l+1];
        as+=max(st[l][j],st[r-(1<<j)+1][j]);
        if(i1==n-1){
            i1=0;
        }
        if(i2==n){
            i2=0;
        }
        i1++,i2++;
        x=nx[i1];
        y=ny[i2];
    }
    cout<<as<<"\n";
    return 0;
}

