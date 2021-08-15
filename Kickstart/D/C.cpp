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
set<pll> ts;
void rs(int tr,auto it,ll s){
    ll tp=it->f;
    if(tr==0){
        //on left pt    
        if(next(it)->f-it->f==1){
            ts.erase(next(it));
            ts.erase(it);
            ts.is(mp(tp+1,2));
        }else{
            ts.erase(it);
            ts.is(mp(tp+1,0));
        }
    }else if(tr==1){
        //on right pt
        if(it->f-prev(it)->f==1){
            ts.erase(prev(it));
            ts.erase(it);
            ts.is(mp(tp-1,2));
        }else{
            ts.erase(it);
            ts.is(mp(tp-1,1));
        }
    }else if(tr==2){
        //on monos
        ts.erase(it);
    }else{
        //inside an interval and not on endpt
        auto it2=prev(it);
        if(it->f!=s+1){
            ts.is(mp(s+1,0));
        }else{
            ts.is(mp(it->f,2));
            ts.erase(it);
        }
        if(it2->f!=s-1){
            ts.is(mp(s-1,1));
        }else{
            ts.is(mp(it2->f,2));
            ts.erase(it2);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++){
            ll a,b;
            cin>>a>>b;
            if(a==b){
                ts.is(mp(a,2));
            }else{
                ts.is(mp(a,0));
                ts.is(mp(b,1));
            }
        }
        cout<<"Case #"<<(i+1)<<": ";
        //track monos
        for(int j=0;j<m;j++){
            ll s;
            cin>>s;
            auto it1=ts.lb(mp(s,0));
            //edge cases
            if(it1==ts.end()){
                cout<<prev(ts.end())->f<<" ";
                rs(prev(ts.end())->s,prev(ts.end()),s);
            }else if(it1==ts.begin()){
                cout<<ts.begin()->f<<" ";
                rs(ts.begin()->s,ts.begin(),s);
            }else{
                if(s==it1->f){
                    cout<<s<<" ";
                    rs(it1->s,it1,s);
                }else{
                    if(it1->s==1){
                        cout<<s<<" ";
                        rs(3,it1,s);
                    }else if(it1->s==2||it1->s==0){
                        if(s-prev(it1)->f<=it1->f-s){
                            cout<<prev(it1)->f<<" ";
                            rs(prev(it1)->s,prev(it1),s);
                        }else{
                            cout<<it1->f<<" ";
                            rs(it1->s,it1,s);
                        }
                    }
                }
            }
        }
        ts.clear();
        cout<<'\n';
    }
    return 0;
}

