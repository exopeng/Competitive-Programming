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
        string as;
        cin>>as;
        int l=0;
        int r=0;
        for(int j=0;j<as.size();j++){
            if(as[j]=='a'){
                l=j;
                break;
            }
        }
        bool bg=true;
        r=l;
        if(as[r]=='a'){
            for(int j=1;j<as.size();j++){
                char ts=(char)(97+j);
                if(l>0&&as[l-1]==ts){
                    l--;
                }else if(r<as.size()-1&&as[r+1]==ts){
                    r++;
                }else{
                    bg=false;
                    break;
                }
            }
        }else{
            bg=false;
        }
        if(bg){
            cout<<"yes";
        }else{
            cout<<"no";
        }
        cout<<'\n';
    }
    return 0;
}

