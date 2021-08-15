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
int ct[3][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
        ct[s[i]-65][i]++;
        if(i){
            ct[0][i]+=ct[0][i-1];
            ct[1][i]+=ct[1][i-1];
            ct[2][i]+=ct[2][i-1];
        }
    }
    int mx=0;
    for(int i=0;i<3;i++){
        int mt=0;
        for(int j=0;j<n;j++){
            if(ct[i][j]>=ct[(i+1)%3][j]&&ct[i][j]>=ct[(i+2)%3][j]){
                mt++;
            }
        }
        mx=max(mx,mt);
    }
    cout<<mx<<'\n';
}

