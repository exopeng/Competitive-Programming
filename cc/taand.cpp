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
int n;
vector<int> bs[33];
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //deal dups separately
    map<int,int> dp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int b=a[i];
        int ct=0;
        dp[a[i]]++;
        while(b!=0){
            if(b%2){
                bs[ct].pb(a[i]);
            }
            ct++;
            b/=2;
        }
    }
    int ans=0;
    for(auto it=dp.begin();it!=dp.end();it++){
        if(it->s>1){
            ans=max(ans,it->f);
        }
    }
    multiset<int,greater<int>> act;
    for(int i=32;i>-1;i--){
        if(act.size()<2){
            act.clear();
            for(auto it=bs[i].begin();it!=bs[i].end();it++){
                act.is(*it);
            }
        }else{
            multiset<int,greater<int>> ts;
            for(auto it=bs[i].begin();it!=bs[i].end();it++){
                if(act.find(*it)!=act.end()){
                    ts.is(*it);
                }
            }
            //
            if(ts.size()>=2){
                act=ts;
            }
        }
    }
    if(act.size()>=2){
        ans=max(ans,*act.begin()&*(next(act.begin())));
    }
    cout<<ans<<"\n";
    return 0;
}

