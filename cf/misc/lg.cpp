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
int p[MAXN];
int ld[MAXN];
int rd[MAXN];
multiset<int,greater<int>> rs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    ld[1]=1,rd[n]=1;
    for(int i=2;i<=n;i++){
        if(p[i]>p[i-1]){
            ld[i]+=ld[i-1];
        }
        ld[i]++;
    }
    for(int i=n-1;i>0;i--){
        if(p[i]>p[i+1]){
            rd[i]+=rd[i+1];
        }
        rd[i]++;
    }
    int as=0;
    for(int i=1;i<=n;i++){
        rs.is(rd[i]),rs.is(ld[i]);
    }
    for(int i=1;i<=n;i++){
        rs.erase(rs.find(ld[i])),
        rs.erase(rs.find(rd[i]));
        if(*rs.begin()<max(ld[i],rd[i])){
            if(min(ld[i],rd[i])>1){
                if(ld[i]==rd[i]&&ld[i]%2){
                    as++;
                }
            }  
        }
        rs.is(ld[i]),rs.is(rd[i]);
    }
    cout<<as<<"\n";
    return 0;
}

