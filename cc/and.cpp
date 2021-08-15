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
const int MAXN = 3e5;
//store test cases here
/*


*/
int n;
int a[MAXN];
ll ct[32];
ll sm=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int b=a[i];
        int ix=0;
        while(b!=0){
            ct[ix]+=b%2;
            b/=2;
            ix++;
        }
    }
    for(int i=0;i<n;i++){
        int ix=0;
        sm-=a[i];
        while(a[i]!=0){
            if(a[i]%2){
                sm+=pow(2,ix)*ct[ix];
            }
            a[i]/=2;
            ix++;
        }

    }
    cout<<sm/2<<"\n";
    return 0;
}

