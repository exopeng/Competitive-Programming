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
        bool ts=false;
        for(int j=0;j<s.size();j++){
            string lt;
            for(int f=j;f<s.size();f++){
                lt=s.substr(j,f-j+1);
                if(lt==t){
                    ts=true;
                    break;
                }
                for(int m=f-1;m>-1;m--){
                    lt+=s[m];
                    if(lt==t){
                        ts=true;
                        break;
                    }
                }
            }
            if(ts){
                break;
            }
        }
        if(ts){
            cout<<"yes"<<'\n';
        }else{
            cout<<"no"<<'\n';
        }
    }
    return 0;
}

