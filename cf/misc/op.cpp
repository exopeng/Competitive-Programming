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
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<vector<int>> r(n);
    for(int i=0;i<n;i++){
        g[i]=vector<int>(m);
        r[i]=vector<int>(m);
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    ll as=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            int x=g[i][j];
            if(x<=n*m&&x>=j+1&&(x-j-1)%m==0){
                x=(x-j-1)/m;
                r[((i-x+m*n)%n)][j]++;
            }
        }
        int at=INF;
        for(int i=0;i<n;i++){
            at=min(at,n-r[i][j]+i);
        }
        as+=at;
    }
    cout<<as<<'\n';
    return 0;
}

