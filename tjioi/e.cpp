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
const int MAXN = 1e3+10;
//store test cases here
/*


*/
int pa[MAXN][MAXN];
int pb[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,q;
    cin>>n>>t>>q;
    for(int i=0;i<t;i++){
        char a;
        int c,d;
        cin>>a>>c>>d;
        if(a=='A'){
            pa[c][d]++;
        }else{
            pb[c][d]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pa[i][j]+=pa[i-1][j]+pa[i][j-1]-pa[i-1][j-1];
            pb[i][j]+=pb[i-1][j]+pb[i][j-1]-pb[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(pa[c][d]-pa[a-1][d]-pa[c][b-1]+pa[a-1][b-1]!=0&&
            pb[c][d]-pb[a-1][d]-pb[c][b-1]+pb[a-1][b-1]!=0&&
            pa[c][d]-pa[a-1][d]-pa[c][b-1]+pa[a-1][b-1]==2*
            (pb[c][d]-pb[a-1][d]-pb[c][b-1]+pb[a-1][b-1])){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}

