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
int mn=10;
string s;
string cu;
void rec(int ix){
    if(ix==10){
        int ct=0;
        int cy=0;
        bool g=true;
        for(int i=0;i<10;i++){
            if(i%2==0){
                if(cu[i]=='1'){
                    ct++;
                }
            }else{
                if(cu[i]=='1'){
                    cy++;
                }
            }
            if(ct>cy){
               int ix=i;
               if(ix%2==0){
                ix--;
               }
               if((9-ix)/2+cy<ct){
                mn=min(mn,i+1);
                g=false;
                break;
               }
            }else if(cy>ct){
                int ix=i;
               if(ix%2==1){
                ix--;
               }
               if((9-ix)/2+ct<cy){
                mn=min(mn,i+1);
                g=false;
                break;
               }
            }
        }
    }else{
        if(s[ix]=='?'){
            cu[ix]='0';
            rec(ix+1);
            cu[ix]='1';
            rec(ix+1);
        }else{
            cu[ix]=s[ix];
            rec(ix+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        mn=10;
        rec(0);
        cout<<mn<<'\n';
    }
    return 0;
}

