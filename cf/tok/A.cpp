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
char ts[2]={'R','W'};
char g[51][51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        bool od=true;
        for(int j=0;j<n;j++){
            for(int f=0;f<m;f++){
                cin>>g[j][f];
                if(g[j][f]=='R'&&(f+j)%2){
                    od=false;
                }
                if(g[j][f]=='W'&&(f+j)%2==0){
                    od=false;
                }
            }
        }
        bool gs=true;
        for(int j=0;j<n;j++){
            for(int f=0;f<m;f++){
                char gt;
                if(!od){
                    if((f+j)%2){
                        gt='R';
                    }else{
                        gt='W';
                    }
                }
                if(od){
                    if((f+j)%2){
                        gt='W';
                    }else{
                        gt='R';
                    }
                }
                if(g[j][f]!='.'&&(g[j][f])!=gt){
                    gs=false;
                }   
                g[j][f]=gt;
            }
        }
        if(!gs){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
            for(int j=0;j<n;j++){
                for(int f=0;f<m;f++){
                    cout<<g[j][f];
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}

