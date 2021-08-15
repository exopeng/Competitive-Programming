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
    	int n;
    	cin>>n;
        unordered_set<ll> tk;
        ll sm=0;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            sm+=a;
            tk.is(sm);
        }
        vector<bool> as(n,false);
        for(int j=1;j<=n;j++){
            if(sm%j==0){
                for(int f=1;f<=j;f++){
                    if(tk.find(f*(sm/j))==tk.end()){
                        break;
                    }
                    if(f==j){
                        as[j-1]=true;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            cout<<as[j];
        }
        cout<<"\n";
    }
    return 0;
}

