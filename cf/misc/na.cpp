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
char tp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        map<char,int> ct;
        for(int j=0;j<n;j++){
            ct[s[j]]++;
        }
        for(int j=n;j>0;j--){
            multiset<int,greater<int>> cs;
            for(auto it=ct.begin();it!=ct.end();it++){
                cs.is(it->s);
            }
            for(int f=n-1;f>=0;f--){
                tp[f]='0';
            }
            bool g=false;
            for(int f=0;f<j;f++){
                if(tp[f]=='0'){
                    int bg=f;
                    int pt=j/gcd(k,j);
                    if(cs.size()==0||*cs.begin()<pt){
                        break;
                    }
                    for(int m=0;m<pt;m++){
                        tp[bg]='1';
                        bg=(bg+k)%j;
                    }
                    auto it=cs.begin();
                    cs.erase(cs.begin());
                    if(*it>pt){
                        cs.is(*it-pt);
                    }
                }
                if(f==j-1){
                    cout<<j<<'\n';
                    g=true;
                    break;
                }
            }
            if(g){
                break;
            }
        }
    }
    return 0;
}

