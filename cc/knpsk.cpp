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
const int MAXN = 2e6;
//store test cases here
/*


*/
int n;
int c1[MAXN];
int c2[MAXN];
ll sum1[MAXN];
ll sum2[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int s1=0;
    int s2=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a;
        if(a==1){
            cin>>c1[s1+1];
            s1++;
            tot++;
        }else{
            cin>>c2[s2+1];
            s2++;
            tot+=2;
        }
    }
    sort(c1+1,c1+s1,greater<int>());
    sort(c2+1,c2+s2,greater<int>());
    for(int i=1;i<=s1;i++){
        sum1[i]=c1[i];
        if(i){
            sum1[i]+=sum1[i-1];
        }
    }
    for(int i=1;i<=s2;i++){
        sum2[i]=c2[i];
        if(i){
            sum2[i]+=sum2[i-1];
        }
    }
    int oi=1;
    int ti=0;
    cout<<c1[1]<<" ";
    for(int i=2;i<=tot;i++){
        //can't take anything
        cout<<sum1[oi]+sum2[ti];
        if(i==tot){
            cout<<"\n";
        }else{
            cout<<" ";
        }
    }
    return 0;
}

