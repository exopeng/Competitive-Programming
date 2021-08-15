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
vector<int> p;
int gcd(int a,int b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
int pf(int a){
    int pa=0;
    for(ll d:p){
        if(d*d>a)
            break;
        while(a%d==0){
            pa++;
            a/=d;
        }
    }
    if(a!=1){
        pa++;
    }
    return pa;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mx=pow(1e9,0.5)+1000000;
    vector<int> ip(mx+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i<=mx;i++){
        if(ip[i]&&(ll)i*i<=mx){
            for(int j=i*i;j<=mx;j+=i)
                ip[j]=false;
        }
        if(ip[i]){
            p.pb(i);
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,k;
        cin>>a>>b>>k;
        int c=gcd(a,b);
        int pa=pf(a);
        int pb=pf(b);
        int pc=pf(c);
        int lo=0;
        int hi=0;
        if(a!=c){
            lo++;
            hi+=pa-pc;
        }
        if(b!=c){
            lo++;
            hi+=pb-pc;
        }
        bool g=true;
        //cout<<lo<<" "<<hi<<"\n";
        if(k>=lo&&k<=hi){
        }else if(k>=hi){
            lo=max(lo,2);
            hi+=2*pc;
            if(k<=hi&&k>=lo){

            }else{
                g=false;
            }
        }else{
            g=false;
        }
        if(g){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
       
    }
    return 0;
}

