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
string a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,m;cin>>n>>m;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        string ts;
        for(int f=0;f<m;f++){
            string tp=a[0];
            for(int l=0;l<26;l++){
                tp[f]=(char)(l+97);
                for(int y=0;y<n;y++){
                    int ct=0;
                    for(int x=0;x<m;x++){
                        if(tp[x]!=a[y][x]){
                            ct++;
                        }                        
                    }
                    if(ct>1){
                        break;
                    }
                    if(y==n-1){
                        ts=tp;
                    }
                }
            }
        }
        if(ts.size()){
            cout<<ts<<'\n'; 
        }else{
            cout<<"-1"<<'\n';
        }
    }
    return 0;
}

