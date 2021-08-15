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
const int MAXN = 2e6;
//store test cases here
/*


*/
ll sm[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll as=0;
    int a,b,c,d;cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++){
        sm[i+b]++;
        sm[i+c+1]--;
    }
    ll ct=0;
    for(int i=0;i<=a+b+c+d;i++){
        ct+=sm[i];
        sm[i]=ct;
    }
    for(int i=a+b+c+d;i>=0;i--){
        sm[i]+=sm[i+1];
    }
    for(int i=c;i<=d;i++){
        as+=sm[i+1];
    }
    cout<<as<<'\n';
    return 0;
}

