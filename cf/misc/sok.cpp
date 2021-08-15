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
        vector<pii> ts,ts1;
        vector<int> ts2,ts3;
        set<int> tk,m1;
    	int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++){
            int l;
            cin>>l;
            if(l>0){
                ts.pb(mp(l,0));
            }else{
                ts1.pb(mp(l,1));
            }
            tk.is(l);
        }
        int rg1=0;
        int rg2=0;
        for(int j=0;j<m;j++){
            int l;
            cin>>l;
            if(l>0){
                ts.pb(mp(l,1));
                ts2.pb(l);
                if(tk.find(l)!=tk.end()){
                    rg1++;
                    m1.is(l);
                }
            }else{
                ts1.pb(mp(l,0));
                ts3.pb(l);
                if(tk.find(l)!=tk.end()){
                    rg2++;
                    m1.is(l);
                }
            }
        }
        //move all boxesup to each special position, and query how many special pos
        //between cur and cur-boxes+1, track number of boxes <= cur pos
        int as=0;
        int as1=0;
        sort(ts.begin(),ts.end()),sort(ts2.begin(),ts2.end()),
        sort(ts3.begin(),ts3.end(),greater<int>()),sort(ts1.begin(),ts1.end(),greater<pii>());
        int ct=0;
        //rg1 is how many boxes are on special pos
        //as is max # on special pos
        as=rg1;
        for(int j=0;j<ts.size();j++){
            if(ts[j].s==0){
                ct++;
                if(m1.find(ts[j].f)!=m1.end()){
                    rg1--;
                }
            }else{
                if(ct==0){
                    as=max(as,rg1);
                }else{
                    as=max(as,(int)(lb(ts2.begin(),ts2.end(),ts[j].f)-
                    lb(ts2.begin(),ts2.end(),ts[j].f-ct+1))+1+rg1);
                }
            }
        }
        ct=0;
        as1=rg2;
        for(int j=0;j<ts1.size();j++){
            if(ts1[j].s==1){
                ct++;
                if(m1.find(ts1[j].f)!=m1.end()){
                    rg2--;
                }
            }else{
                if(ct==0){
                    as1=max(as1,rg2);
                }else{
                    as1=max(as1,(int)(lb(ts3.begin(),ts3.end(),ts1[j].f)-
                    lb(ts3.begin(),ts3.end(),ts1[j].f+ct-1))+1+rg2);
                }
            }
        }
        //cout<<as<<" "<<as1<<"\n";
        cout<<(as+as1)<<"\n";
    }
    return 0;
}

