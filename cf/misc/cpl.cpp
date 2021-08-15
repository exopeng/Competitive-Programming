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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
        map<int,pii> px,py;
        map<int,pii> ax,ay;
        vector<pii> at;
        cin>>n;
        vector<int> ab(n,-2);
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            at.pb(mp(a,b));
            for(int f=0;f<2;f++){
                if(f){
                    swap(a,b);
                }
                if(px.find(a)!=px.end()){
                    if(px[a].f>b){
                        px[a]=mp(b,j);
                    }
                }else{
                    px[a]=mp(b,j);
                }
                if(py.find(a)!=py.end()){
                    if(py[a].f>b){
                        py[a]=mp(b,j);
                    }
                }else{
                    py[a]=mp(b,j);
                }
            }
        }
        ax[px.begin()->f]=px.begin()->s;
        for(auto it=next(px.begin());it!=px.end();it++){
            if(prev(ax.end())->s.f>it->s.f){
                ax[it->f]=it->s;
            }else{
                ax[it->f]=prev(ax.end())->s;
            }
        }
        ay[py.begin()->f]=py.begin()->s;
        for(auto it=next(py.begin());it!=py.end();it++){
            if(prev(ay.end())->s.f>it->s.f){
                ay[it->f]=it->s;
            }else{
                ay[it->f]=prev(ay.end())->s;
            }
        }
        for(int j=0;j<n;j++){
            if(ax.find(at[j].f)!=ax.begin()&&
                prev(ax.find(at[j].f))->s.f<at[j].s){
                ab[j]=prev(ax.find(at[j].f))->s.s;
            }
            if(ay.find(at[j].s)!=ay.begin()&&
                prev(ay.find(at[j].s))->s.f<at[j].f){
                ab[j]=prev(ay.find(at[j].s))->s.s;
            }
            cout<<(ab[j]+1)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

