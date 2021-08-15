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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int p[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int ct0=0;
    int ct1=0;
    int lt=-1;
    for(int j=0;j<n;j++){
        cin>>p[j];
        if(p[j]!=0){
            p[j]%=2;
            if(p[j]){
                ct1++;
            }else{
                ct0++;
            }
            if(lt==-1){

            }else{
                
            }
        }else{
            p[j]=-1;
        }
    }
    int r0=n/2-ct0;
    int r1=n-ct0-ct1-r0;




    return 0;
}

