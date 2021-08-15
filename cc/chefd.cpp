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
int n,m;
int t[4*MAXN][3];
int arr[MAXN];
int fi[MAXN][3];
int dv[]={2,3,5};
void update(int v,int tl,int tr,int l,int r,int add,int tp){
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v][tp]+=add;
    }else{
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(r, tm),add,tp);
        update(v*2+1,tm+1,tr,max(l, tm+1),r,add,tp);
    }
}
int get(int v,int tl,int tr,int pos,int tp){
    if(tl==tr)
        return t[v][tp];
    int tm=(tl+tr)/2;
    if(pos<=tm)
        return t[v][tp]+get(v*2,tl,tm,pos,tp);
    else
        return t[v][tp]+get(v*2+1,tm+1,tr,pos,tp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a;
        if(a==1){
            int d;
            cin>>b>>c>>d;
            b--,c--;
            if(d==2){
                d=0;
            }else if(d==3){
                d=1;
            }else{
                d=2;
            }
            update(1,0,n-1,b,c,1,d);
        }else{
            cin>>b>>c;
            b--;
            for(int j=0;j<3;j++){
                fi[b][j]=get(1,0,n-1,b,j);
            }
            arr[b]=c;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int div=get(1,0,n-1,i,j)-fi[i][j];
            while(arr[i]%dv[j]==0&&div>0){
                arr[i]/=dv[j];
                div--;
            }
        }
        cout<<arr[i];
        if(i==n-1){
            cout<<"\n";
        }else{
            cout<<" ";
        }
    }
    return 0;
}

