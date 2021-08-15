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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,c;
        cin>>n>>c;
        //maps number of intervals to the number of pts that have that many intervals
        //encompassing it 
        map<ll,ll,greater<ll>> ct;
        //f location, s.f is the number of l endpoints, s.s is # of r endpts
        vector<pair<ll,pii>> ps;
        map<ll,pii> ns;
        for(int j=0;j<n;j++){
            ll l,r;
            cin>>l>>r;
            ns[l].f++;
            ns[r].s++;
        }
        for(auto it=ns.begin();it!=ns.end();it++){
            ps.pb(mp(it->f,it->s));
        }
        sort(ps.begin(),ps.end());
        ll cu=0;
        for(int j=0;j<ps.size();j++){
            if(j){
                ct[cu]+=ps[j].f-ps[j-1].f-1;
            }
            cu-=ps[j].s.s;
            ct[cu]++;
            cu+=ps[j].s.f;
        }
        ll as=0;
        for(auto it=ct.begin();it!=ct.end();it++){
            //cout<<it->f<<" "<<it->s<<'\n';
            if(c<=0){
                break;
            }
            if(c<it->s){
                as+=c*it->f;
                c=0;
            }else{
                as+=it->s*it->f;
                c-=it->s;
            }
        }
        cout<<"Case #"<<(i+1)<<": "<<(as+n)<<'\n';
    }
    return 0;
}

