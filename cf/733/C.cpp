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
        vector<int> a;
        vector<int> b;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int bs;
            cin>>bs;
            a.pb(bs);
        }
        for(int j=0;j<n;j++){
            int bs;
            cin>>bs;
            b.pb(bs);
        }
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
        int lo=0;
        int hi=1e5;
        while(lo!=hi){
            int mid=(lo+hi)/2;
            ll as=0;
            ll bs=0;
            if(mid>=(n+mid)-(n+mid)/4){
                as+=100*mid;
            }else{
                as+=100*mid;
                for(int j=0;j<(n+mid)-(n+mid)/4-mid;j++){
                    as+=a[j];
                }
            }
            for(int j=0;j<min(n,(n+mid)-(n+mid)/4);j++){
                bs+=b[j];
            }
            if(as>=bs){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        cout<<lo<<'\n';
    }
    return 0;
}

