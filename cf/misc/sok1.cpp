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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        //positionsof boxes,pos of specs,psums
        vector<int> ts,ts1,ts2,ts3,af,af1;
    	int n,m;
        cin>>n>>m;
        set<int> oc;
        for(int j=0;j<n;j++){
            int l;
            cin>>l;
            if(l>0){
                ts.pb(l);
            }else{
                ts1.pb(l);
            }
            oc.is(l);
        }
        for(int j=0;j<m;j++){
            int l;
            cin>>l;
            if(l>0){
                ts2.pb(l);
            }else{
                ts3.pb(l);
            }
        }
        sort(ts.begin(),ts.end()),sort(ts3.begin(),ts3.end(),greater<int>()),
        sort(ts1.begin(),ts1.end(),greater<int>()),sort(ts2.begin(),ts2.end());
        af.pb(0);
        for(int j=ts2.size()-2;j>-1;j--){
            int tot=0;
            if(oc.find(ts2[j+1])!=oc.end()){
                tot++;
            }
            tot+=af[af.size()-1];
            af.pb(tot);
        }
        reverse(af.begin(),af.end());
        //move all boxesup to each special position, and query how many special pos
        //between cur and cur-boxes+1, track number of boxes <= cur pos
        //also track number of spec pos to the right that are occupied
        int as=0;
        for(int j=0;j<ts2.size();j++){
            int bt=ub(ts.begin(),ts.end(),ts2[j])-ts.begin();
            int st=ub(ts2.begin(),ts2.end(),ts2[j])
            -lb(ts2.begin(),ts2.end(),ts2[j]-bt+1);
            as=max(as,min(bt,st)+af[j]);
        }
        af1.pb(0);
        for(int j=ts3.size()-2;j>-1;j--){
            int tot=0;
            if(oc.find(ts3[j+1])!=oc.end()){
                tot++;
            }
            tot+=af1[af1.size()-1];
            af1.pb(tot);
        }
        reverse(af1.begin(),af1.end());
        int as1=0;
        for(int j=0;j<ts3.size();j++){
            int bt=ub(ts1.begin(),ts1.end(),ts3[j],greater<int>())-ts1.begin();
            int st=ub(ts3.begin(),ts3.end(),ts3[j],greater<int>())
            -lb(ts3.begin(),ts3.end(),ts3[j]+bt-1,greater<int>());
            as1=max(as1,min(bt,st)+af1[j]);
        }
        //cout<<as<<" "<<as1<<"\n";
        cout<<(as+as1)<<"\n";
    }
    return 0;
}

