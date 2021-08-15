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
const int MAXN = 2e7;
//store test cases here
/*


*/
vector<int> p;
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<bool> ip(MAXN+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i*i<=MAXN;i++){
        if(ip[i]){
            p.pb(i);
            for(int j=i*i;j<=MAXN;j+=i)
                ip[j]=false;
        }
    }
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int ct=0;
        set<vector<int>> ts;
        for(int j=0;j<n;j++){
            vector<pii> ft;
            for(ll d:p){
                int ct=0;
                if(d*d>a[j])
                    break;
                while(a[j]%d==0){
                    ct++;
                    a[j]/=d;
                }
                if(ct){
                    ft.pb(mp(d,ct));
                }
            }
            if(a[j]!=1){
                ft.pb(mp(a[j],1));
            }
            vector<int> nd;
            for(int f=0;f<ft.size();f++){
                if(ft[f].s%2==1){
                    nd.pb(ft[f].f);
                }
            }
            sort(nd.begin(),nd.end());
            if(ts.find(nd)!=ts.end()){
                ts.clear();
                ct++;
            }
            ts.is(nd);
        }
        cout<<ct+1<<"\n";
    }
    return 0;
}

