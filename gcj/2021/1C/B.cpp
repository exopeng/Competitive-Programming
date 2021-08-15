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
ll pw(int v){
    ll re=1;
    for(int j=0;j<v;j++){
        re*=10;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll s;
        cin>>s;
        s++;
        bool ro=false;
        while(true){
            string ts=to_string(s);
            for(int j=1;j<ts.size();j++){
                ll curr=stoll(ts.substr(0,j));
                ll ls=curr+1;
                int st=j;
                int et=log10(curr+1)+st;
                while(et<=ts.size()-1){
                    if(stoll(ts.substr(st,et-st+1))!=ls){
                        break;
                    }
                    if(et==ts.size()-1){
                        ro=true;
                        break;
                    }
                    ls++;
                    st=et+1;
                    et=log10(ls)+st;
                }
                if(ro){
                    break;
                }
            }
            if(ro){
                break;
            }
            s++;
        }
        cout<<"Case #"<<(i+1)<<": "<<s<<"\n";
    }
    return 0;
}

