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
const int MAXN = 3e5+100;
//store test cases here
/*


*/
int a[MAXN];
int ks[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        multiset<int> lt;
        multiset<int> rt;
        for(int j=0;j<k;j++){
            cin>>a[j];
        }
        for(int j=0;j<k;j++){
            cin>>ks[a[j]];
        }
        for(int j=0;j<k;j++){
            rt.is(ks[a[j]]+a[j]);
        }
        for(int j=1;j<=n;j++){
            if(lt.size()&&rt.size()){
                cout<<min(*lt.begin()+j,*rt.begin()-j);
            }else if(lt.size()){
                cout<<(*lt.begin()+j);
            }else{
                cout<<(*rt.begin()-j);
            }
            if(ks[j]){
                rt.erase(rt.find(ks[j]+j));
                lt.is(ks[j]-j);
            }
            cout<<" ";
        }
        cout<<'\n';
        for(int j=1;j<=n;j++){
            a[j]=0;
            ks[j]=0;
        }
    }
    return 0;
}

