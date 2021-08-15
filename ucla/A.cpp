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
int x[10]={7,4,1,8,5,2,9,6,3,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        int as=0;
        cin>>n;
        for(int j=0;j<10;j++){
            if(n%10==x[j]){
                if(n>=7*(j+1)){
                    as=(j+1);
                }
            }
        }
        if(as){
            cout<<as<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}

