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
const int MAXN = 4e5;
//store test cases here
/*


*/
int a[MAXN];
int n;
int ip(int i){
    return(i>0&&i<n-1&&(a[i]<min(a[i-1],a[i+1])||a[i]>max(a[i-1],a[i+1])));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int it=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            it+=ip(j);
        }
        int mx=0;
        for(int j=0;j<n;j++){
            int cs=INF;
            int cu=ip(j-1)+ip(j)+ip(j+1);
            int oj=a[j];       
            if(j!=0){
                a[j]=a[j-1];
                cs=min(cs,ip(j-1)+ip(j)+ip(j+1)); 
            }
            if(j!=n-1){
                a[j]=a[j+1];
                cs=min(cs,ip(j-1)+ip(j)+ip(j+1)); 
            }
            a[j]=oj;
            mx=max(mx,cu-cs);
            //cout<<cu<<" "<<cs<<": ";
        }
        cout<<it-mx<<"\n";
    }
    return 0;
}

