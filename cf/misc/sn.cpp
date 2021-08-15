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
const int MAXN = 3e6;
//store test cases here
/*


*/
int as[MAXN][6];
string at[6]={"abc","acb","bca","cab","bac","cba"};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=0;i<6;i++){
        for(int j=0;j<n;j++){
            if(s[j]!=at[i][j%3]){
                as[j+1][i]++;
            }
            if(j){
                as[j+1][i]+=as[j][i];
            }
        }
    }
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        int mn=INF;
        for(int j=0;j<6;j++){
            mn=min(mn,as[r][j]-as[l-1][j]);
        }
        cout<<mn<<'\n';
    }
    return 0;
}

