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
int g[30][30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int h,w;
        cin>>h>>w;
        for(int j=0;j<h;j++){
            for(int f=0;f<w;f++){
               g[j][f]=0;
            }
        }
        for(int j=0;j<w;j++){
            if(j%2==0){
                g[0][j]=1;
            }else{
                g[0][j]=0;
            }
        }
        if(h>2){
            for(int j=0;j<w;j++){
                if(j%2==0){
                    g[h-1][j]=1;
                }else{
                    g[h-1][j]=0;
                }
            }
        }
        for(int j=2;j<h-2;j+=2){
            for(int f=0;f<w;f++){
                if(f==0||f==w-1){
                    g[j][f]=1;
                }else{
                    g[j][f]=0;
                }
            }
        }
        for(int j=0;j<h;j++){
            for(int f=0;f<w;f++){
                cout<<g[j][f];
            }
            cout<<'\n';
        }
        
        cout<<'\n';
    }
    return 0;
}

