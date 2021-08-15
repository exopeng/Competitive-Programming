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
int ct(string s){
    int as=0;
    for(int i=0;i+3<s.size();i++){
        if(s.substr(i,4)=="haha"){
            as++;
        }
    }
    return as;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        map<string,pair<pair<string,string>,pll>> vs;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            string a,b;
            cin>>a>>b;
            if(b=="="){
                string c,d,e;
                string f1,f2;
                cin>>c>>d>>e;
                if(vs[c].s.s<3){
                    f1=vs[c].f.f;
                    if(vs[e].s.s<3-vs[c].s.s){
                        f1+=vs[e].f.f;
                    }else{
                        f1+=vs[e].f.f.substr(0,3-vs[c].s.s);
                    }
                }else{
                    f1=vs[c].f.f.substr(0,3);
                }
                if(vs[e].s.s<3){
                    f2=vs[e].f.s;
                    if(vs[c].s.s<3-vs[e].s.s){
                        f2=vs[c].f.s+f2;
                    }else{
                        f2=vs[c].f.s.substr(0,3-vs[e].s.s)+f2;
                    }
                }else{
                    f2=vs[e].f.s.substr(0,3);
                }
                vs[a]=mp(mp(f1,f2),
                    mp(vs[c].s.f+vs[e].s.f+ct(vs[c].f.s+vs[e].f.f),vs[c].s.s+vs[e].s.s));
            }else{
                string f;
                cin>>f;
                string f1,f2;
                if(f.size()<3){
                    f1=f;
                    f2=f;
                }else{
                    f1=f.substr(0,3),f2,f2=f.substr(f.size()-3);
                }
                vs[a]=mp(mp(f1,f2),mp(ct(f),f.size()));
            }
            if(j==n-1){
                cout<<vs[a].s.f<<"\n";
            }
        }
    }
    return 0;
}

