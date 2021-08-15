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
const int MAXN = 2e5+100;
//store test cases here
/*


*/
int gcd(int a,int b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
int t[4*MAXN];
int arr[MAXN];
void build(int curr,int l,int r){
    if(l==r){
        t[curr]=arr[l];
    }else{
        int mid=(r+l)/2;
        build(curr*2,l,mid);
        build(curr*2+1,mid+1,r);
        t[curr]=gcd(t[curr*2],t[curr*2+1]);
    }
}
int sum(int curr,int tl,int tr,int l,int r){
    if(l>r){
        return 0;
    }
    if(l==tl&&r==tr){
        return t[curr];
    }
    int mid=(tl+tr)/2;
    return gcd(sum(curr*2,tl,mid,l,min(r,mid)),sum(curr*2+1,mid+1,tr,max(l,mid+1),r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        build(1,0,n-1);
        int l=0;
        int r=n-1;
        while(l!=r){
            int m=(l+r)/2;
            bool bg=true;
            int init=sum(1,0,n-1,0,m);
            for(int j=1;j<n;j++){
                int pt=1;
                if(j+m>=n){
                    pt=gcd(sum(1,0,n-1,j,n-1),sum(1,0,n-1,0,j+m-n));
                }else{
                    pt=sum(1,0,n-1,j,j+m);
                }
                if(pt!=init){
                    bg=false;
                    break;
                }
            }
            if(bg){
                r=m;
            }else{
                l=m+1;
            }
        }
        cout<<l<<'\n';
    }
    return 0;
}

