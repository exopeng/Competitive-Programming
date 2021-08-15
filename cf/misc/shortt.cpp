#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
const int MAXN = 1e7+2;
//store test cases here
/*


*/
ll cs[MAXN+5];
ll sd[MAXN+5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=MAXN;i++){
        for(int j=i;j<=MAXN;j+=i)
            sd[j]+=i;
        if(sd[i]<=1e7){
            if(cs[sd[i]]==0){
                cs[sd[i]]=i;
            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int c;
        cin>>c;
        if(cs[c]==0){
            cout<<-1<<"\n";
        }else{
            cout<<cs[c]<<"\n";
        }
    }
    return 0;
}

