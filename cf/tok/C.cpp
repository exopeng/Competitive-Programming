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
const int MAXN = 5e5;
//store test cases here
/*


*/
int p[MAXN];
int sz[MAXN];
int tot=0;
ll binpow(ll a,ll b,ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
void make_set(int v){
    p[v]=v;
    sz[v]=1;
    tot++;
}
int find_set(int v){
    if(v==p[v])
        return v;
    return p[v]=find_set(p[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        tot--;
        if(sz[a]<sz[b])
            swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
}
int a[MAXN];
int b[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        tot=0;
        int n;
        cin>>n;
        for(int j=1;j<=n;j++){
            make_set(j);
        }
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
            union_sets(a[j],b[j]);
        }
        cout<<binpow(2,tot,MOD)<<"\n";
    }
    return 0;
}

