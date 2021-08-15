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
    int n;
    srand(time(nullptr));
    cin>>n;
    int l=1;
    int r=n;
    while(l!=r){
        int mid=(l+r)/2;
        cout<<"? "<<mid<<'\n';
        cout.flush();
        int a;
        cin>>a;
        cout<<"? "<<(mid+1)<<'\n';
        int b;
        cout.flush();
        cin>>b;
        if(b>a){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<"! "<<l<<'\n';
    return 0;
}

