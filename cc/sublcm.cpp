#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;
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
int a[MAXN];
vector<int> ps;
vector<pii> pt[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> ip(1e6+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i*i<=1e6;i++) {
        if(ip[i]){
            ps.pb(i);
            for(int j=i*i;j<=1e6;j+=i)
                ip[j]=false;
        }
    }
    int t;
    cin>>t;
    //auto start = high_resolution_clock::now();
    for(int i=0;i<t;i++){
    	int n;
        vector<int> av(MAXN,0);
        cin>>n;
        int ans=-1;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        //pfactor of1
        int st=0;
        for(int j=0;j<n;j++){
            int b=a[j];
            if(pt[a[j]].size()==0){
                for(ll d:ps) {
                    int ct=0;
                    if(d*d>b)
                        break;
                    while(b%d==0){
                        ct++;
                        b/=d;
                    }
                    if(ct){
                        pt[a[j]].pb(mp(d,ct));
                    }
                }
                if(b>1)
                    pt[a[j]].pb(mp(b,1));
            }
        }
        for(int j=0;j<n;j++){
            for(int f=0;f<pt[a[j]].size();f++){
                while(av[pt[a[j]][f].f]!=0){
                    for(int l=0;l<pt[a[st]].size();l++){
                        av[pt[a[st]][l].f]-=pt[a[st]][l].s;
                    }
                    st++;
                }
                av[pt[a[j]][f].f]+=pt[a[j]][f].s;
            }
            ans=max(ans,j-st+1);
        }
        if(ans==1){
            cout<<-1<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    }
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<milliseconds>(stop - start);
    //cout<<duration.count()<<"\n";
    return 0;
}

