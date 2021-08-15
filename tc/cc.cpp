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
vector<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int mn=0;
    int mx=0;
    int me=0;
    int md=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        st.pb(a);
        mn+=a;
    }
    sort(st.begin(),st.end());
    for(int i=0;i<n;i++){
        int ct=0;
        int bg=i;
        while(i<n&&st[i]==st[bg]){
            ct++;
            i++;
        }
        i--;
        if(ct>=mx){
            mx=ct;
            md=st[i];
        }
    }   
    if(n%2==0){
        me=(st[n/2]+st[n/2-1])/2;
    }else{
        me=st[n/2];
    }
    cout<<mn/n<<"\n"<<me<<"\n"<<md<<'\n';
    return 0;
}

