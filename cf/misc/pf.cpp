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
const int MAXN = 2e2+5;
//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        vector<int> ps;
        string a,b;
        cin>>n>>a>>b;
        string c=a;
        int ix=n-1;
        int dir=-1;
        int ct=0;
        int hf=0;//# of transformations
        while(ct<n){
            a[ix]^=hf%2;
            if(a[ix]==b[n-ct-1]){
                ct++;
                ix+=dir;
                continue;
            }
            a[ix]^=hf%2;
            if(ct==n-1){
                ps.pb(1);
            }else{
                a[ix+dir*(n-ct-1)]^=hf%2;
                if(a[ix+dir*(n-ct-1)]==b[n-1-ct]){
                    ps.pb(1);
                    ps.pb(n-ct);
                }else{
                    ps.pb(n-ct);
                }
            }
            hf++;
            ix=(ix+dir*(n-ct-1)-dir);
            dir*=-1;
            ct++;
        }
        cout<<ps.size()<<' ';
        for(int j=0;j<ps.size();j++){
            cout<<ps[j]<<" ";
        }
        cout<<'\n';
        /*
        for(int j=0;j<ps.size();j++){
            for(int f=0;f<ps[j];f++){
                c[f]^=1;
            }
            reverse(c.begin(),c.begin()+ps[j]);
        }
        cout<<c<<" ";
        if(c==b){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
        */
    }
    return 0;
}

