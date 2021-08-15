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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        map<int,int> ts;
        set<int> tp;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            ts[a]++;
            tp.is(j);
        }
        vector<int> nt;
        for(auto it=ts.begin();it!=ts.end();it++){
            nt.pb(it->s);
        }
        sort(nt.begin(),nt.end(),greater<int>());
        int l=0;
        int r=n;
        while(l!=r){
            set<int> tl=tp;
            int m=(l+r+1)/2;
            bool bg=true;
            for(int j=0;j<nt.size();j++){
                int lt=*tl.begin();
                tl.erase(lt);
                for(int f=1;f<nt[j];f++){
                    int np=lt+m+1;
                    auto it=tl.lb(np);
                    if(it!=tl.end()){
                        lt=*it;
                        tl.erase(lt);
                    }else{
                        bg=false;
                        break;
                    }
                }
                if(!bg){
                    break;
                }
            }
            if(bg){
                l=m;
            }else{
                r=m-1;
            }
        }
        cout<<l<<'\n';
    }
    
    return 0;
}

