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
const int MAXN = 5e5+100;
//store test cases here
/*


*/
ll n,q,p;
int t[4*MAXN][4];
int arr[MAXN][4];
ll a[MAXN];
ll binpow(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
void build(int curr,int l,int r){
    if(l==r){
        for(int j=0;j<4;j++){
            t[curr][j]=arr[l][j];
        }
    }else{
        int mid=(r+l)/2;
        build(curr*2,l,mid);
        build(curr*2+1,mid+1,r);
        for(int j=0;j<4;j++){
            t[curr][j]=t[curr*2][j]+t[curr*2+1][j];
        }
    }
}
int sum(int curr,int tl,int tr,int l,int r,int tp){
    if(l>r){
        return 0;
    }
    if(l==tl&&r==tr){
        return t[curr][tp];
    }
    int mid=(tl+tr)/2;
    return sum(curr*2,tl,mid,l,min(r,mid),tp)+sum(curr*2+1,mid+1,tr,max(l,mid+1),r,tp);
}
void update(int curr,int tl,int tr,int pos,vector<int> val){
    if(tl==tr){
        for(int j=0;j<4;j++){
            t[curr][j]=val[j];
        }
    }else{
        int mid=(tl+tr)/2;
        if(pos<=mid){
            update(curr*2,tl,mid,pos,val);
        }else{
            update(curr*2+1,mid+1,tr,pos,val);
        }
        for(int j=0;j<4;j++){
            t[curr][j]=t[curr*2][j]+t[curr*2+1][j];
        }
    }
}
int V(ll as){
    if(as==0){
        return 0;
    }
    int ct=1;
    while(as%binpow(p,ct)==0){
        ct++;
    }
    return ct-1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>q>>p;
        cout<<"Case #"<<(i+1)<<": ";
        for(int j=0;j<n;j++){
            cin>>a[j];
            for(int f=0;f<4;f++){
                arr[j][f]=V(pow(a[j],f+1)-pow(a[j]%p,f+1));
            }
        }
        build(1,0,n-1);
        for(int j=0;j<q;j++){
            int bs,cs,ds,as;
            cin>>bs>>cs>>ds;
            if(bs==1){
                vector<int> vs;
                a[cs-1]=ds;
                for(int f=0;f<4;f++){
                    vs.pb(V(pow(a[cs-1],f+1)-pow(a[cs-1]%p,f+1)));
                }
                update(1,0,n-1,cs-1,vs);
            }else{
                cin>>as;
                cout<<sum(1,0,n-1,ds-1,as-1,cs-1)<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}

