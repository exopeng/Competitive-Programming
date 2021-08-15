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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s,t;
        cin>>s>>t;
        bool g=false;
        int ix=s.size()-1;
        for(int j=t.size()-1;j>-1;j--){
            if(ix<0){
                g=true;
                break;
            }
            if(s[ix]==t[j]){
                ix--;
                continue;
            }
            while(ix>=0&&s[ix]!=t[j]){
                ix-=2;
            }
            if(ix>=0&&s[ix]==t[j]){
                ix--;
                continue;
            }else{
                g=true;
                break;
            }
        }
        if(g){
            cout<<"no"<<'\n';
        }else{
            cout<<"yes"<<'\n';
        }
    }
    return 0;
}

