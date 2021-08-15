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
const int MAXN = 3e5;
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
        cin>>n;
        multiset<int> ts;
        for(int j=0;j<pow(2,n);j++){
            ll a;
            cin>>a;
            if(a){
                ts.is(a);
            }
        }
        vector<int> rem;
        multiset<int> act;
        act.is(0);
        for(int j=0;j<n;j++){
            int ns=*ts.begin();
            rem.pb(ns);
            vector<int> ad;
            for(auto it=act.begin();it!=act.end();it++){
                ts.erase(ts.find(*it+ns));
                ad.pb(*it+ns);
            }
            for(int f=0;f<ad.size();f++){
                act.is(ad[f]);
            }
        }
        sort(rem.begin(),rem.end());
        for(int j=0;j<n;j++){
            cout<<rem[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

