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
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
        cin>>n;
        map<int,int> tk;
        int ls=0;
        int l=0,r=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            ls=(ls+a[j])%n;
            if(tk.find(ls)!=tk.end()){
                l=tk[ls]+1,r=j;
                break;
            }else if(ls==0){
                l=0,r=j;
                break;
            }
            tk[ls]=j;
        }
        cout<<r-l+1<<"\n";
        for(int j=l;j<=r;j++){
            cout<<j+1;
            if(j==r){
                cout<<"\n";
            }else{
                cout<<" ";
            }
        }
    }
    return 0;
}

