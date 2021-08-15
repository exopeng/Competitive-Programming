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
const int MAXN = 2e3;
//store test cases here
/*


*/
char a[MAXN][MAXN];
char b[MAXN][MAXN];
int h[MAXN];
int v[MAXN];
int n;
bool rec(int i,int j){
    if(j==n){
        i++,j=0;
        if(i==n){
            return true;
        }
    }
    if(a[i][j]==b[i][j]){
        //nothing picked yet
        if(h[i]==0&&v[j]==0){
            h[i]=1,v[j]=1;
            bool f=rec(i,j+1);
            for(int m=0;m<n;m++){
                h[m]=v[m]=0;
            }
            h[i]=2,v[j]=2;
            bool f1=rec(i,j+1);
            for(int m=0;m<n;m++){
                h[m]=v[m]=0;
            }
            return max(f,f1);
            //one picked
        }else if(h[i]==0&&v[j]!=0||h[i]!=0&&v[j]==0){
            h[i]=max(h[i],v[j]);
            v[j]=max(h[i],v[j]);
            return rec(i,j+1);
            //both picked
        }else{
            return (h[i]==v[j]&&rec(i,j+1));
        }
    }else{
        //nothing picked yet
        if(h[i]==0&&v[j]==0){
            h[i]=1,v[j]=2;
            bool f=rec(i,j+1);
            for(int m=0;m<n;m++){
                h[m]=v[m]=0;
            }
            h[i]=2,v[j]=1;
            bool f1=rec(i,j+1);
            for(int m=0;m<n;m++){
                h[m]=v[m]=0;
            }
            return max(f,f1);
            //both picked
        }else if(h[i]!=0&&v[j]!=0){
            return (h[i]!=v[j]&&rec(i,j+1));
            //one picked
        }else{
            if(h[i]==0){
                h[i]=(v[j]%2)+1;
            }else{
                v[j]=(h[i]%2)+1;
            }
            return rec(i,j+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++)
                cin>>a[j][f];
        }
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++)
                cin>>b[j][f];
        }
        bool f=rec(0,0);
        if(f){
            cout<<"yes";
        }else{
            cout<<"no";
        }
        cout<<'\n';
    }
    return 0;
}

