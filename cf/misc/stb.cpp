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
const int MAXN = 2e6;
//store test cases here
/*


*/
vector<int> p;
int a[MAXN];
int ct[MAXN];
int fo[MAXN];
pii cs[100];
int mx=0;
int cp=0;
int binpow(int a,int b){
    int res = 1;
    while(b>0){
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
void rec(int ix,int ns){
    if(ix==cp){
        mx=max(mx,fo[ns]);
        return;
    }
    for(int j=0;j<=cs[ix].s;j++){
        rec(ix+1,ns*binpow(cs[ix].f,j));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> ip(MAXN+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i*i<=MAXN;i++){
        if(ip[i]){
            p.pb(i);
            for(int j=i*i;j<=MAXN;j+=i)
                ip[j]=false;
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
            ct[a[j]]++;
        }
        sort(a,a+n);
        int lt=0;
        for(int j=0;j<n;j++){
            mx=0;
            cp=0;
            int ls=a[j];
            for(ll d:p){
                int ct=0;
                if(d*d>ls)
                    break;
                while(ls%d==0){
                    ct++;
                    ls/=d;
                }
                if(ct){
                    cs[cp]=mp(d,ct);
                    cp++;
                }
            }
            if(ls!=1){
                cs[cp]=mp(ls,1);
                cp++;
            }
            rec(0,1);
            fo[a[j]]=mx+1;
            lt=max(lt,fo[a[j]]);
        }
        for(int j=0;j<n;j++){
            ct[a[j]]--;
            fo[a[j]]=0;
        }
        cout<<n-lt<<"\n";
    }
    return 0;
}

