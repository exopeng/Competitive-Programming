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
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<ll> ps;
    vector<bool> ip(1e5+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i*i<=1e5;i++){
        if(ip[i]){
            ps.pb(i);
            for(int j=i*i;j<=1e5;j+=i)
                ip[j]=false;
        }
    }
    for(int i=0;i<t;i++){
    	int n;
        map<int,pii> pm;
        cin>>n;
        vector<pii> tm(n,mp(0,0));
        for(int j=0;j<n;j++){
            cin>>a[j];
            vector<int> pt;
            for(int f=0;f<ps.size();f++){
                if(ps[f]*ps[f]>a[j]){
                    break;
                }
                bool g=true;
                while(a[j]%ps[f]==0){
                    a[j]/=ps[f];
                    if(g){
                        pt.pb(ps[f]);
                    }
                    g=false;
                }
            }
            if(a[j]!=1){
                pt.pb(a[j]);
            }
            for(int f=0;f<pt.size();f++){
                if(pm.find(pt[f])==pm.end()){
                    pm[pt[f]].f=j;
                    pm[pt[f]].s=j;
                }else{
                    pm[pt[f]].f=min(pm[pt[f]].f,j);
                    pm[pt[f]].s=max(pm[pt[f]].s,j);
                }
            }
        }
        for(auto it=pm.begin();it!=pm.end();it++){
            tm[it->s.f].f++;
            tm[it->s.s].s++;
        }
        int l=0;
        for(int j=0;j<n;j++){
            l+=tm[j].f,l-=tm[j].s;
            if(l==0){
                cout<<j+1<<"\n";
                break;
            }
        }
    }
    return 0;
}

