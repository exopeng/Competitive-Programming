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
int a[MAXN];
int bt[51];
ll pw(ll curr, ll exp){
    ll as=1;
    for(int i=0;i<exp;i++){
        as*=curr;
    }
    return as;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
        cin>>n;
        for(int j=0;j<50;j++){
            bt[j]=0;
        }
        for(int j=0;j<n;j++){
            cin>>a[j];
            int ix=0;
            while(a[j]!=0){
                bt[ix]+=a[j]%2;
                a[j]/=2;
                ix++;
            }
        }
        ll as=0;
        for(int j=0;j<50;j++){
            if(bt[j]){
                as+=pw(2,j);
            }
            bt[j+1]+=bt[j]/2;
        }
        cout<<as<<"\n";
    }
    return 0;
}

