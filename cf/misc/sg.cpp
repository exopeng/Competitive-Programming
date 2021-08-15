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
ll gcd(ll a,ll b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //prime factorization in log(n) with sqrtn space compleixty
    vector<ll> p;
    vector<ll> ip(MAXN+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i<=MAXN;i++){
        if(ip[i]&&(ll)i*i<=MAXN){
            for(int j=i*i;j<=MAXN;j+=i)
                ip[j]=false;
        }
        if(ip[i]){
            p.pb(i);
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll a,m;
        ll as=0;
        cin>>a>>m;
        ll nt=gcd(a,m);
        ll np=m/nt;
        vector<ll> ps;
        for(ll d:p){
            int ct=0;
            if(d*d>np)
                break;
            while(np%d==0){
                ct++;
                np/=d;
            }
            if(ct){
                ps.pb(pow(d,ct));
            }
        }
        if(np!=1){
            ps.pb(a[j]);
        }
        for(int j=0;j<pow(2,ps.size());j++){
            int b=j;
            vector<int> tp;
            while(b!=0){
                tp.pb(b%2);
                b/=2;
            }
            ll tr=nt;
            for(int f=0;f<tp.size();f++){
                if(tp[f]){
                    nt*=ps[f];
                }
            }
            if(nt>=a&&nt<a+m){
                as++;
            }
        }
        cout<<as<<'\n';
    }
    
    return 0;
}

