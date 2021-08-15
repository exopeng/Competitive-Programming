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
ll hsh[MAXN][2][2];
ll pw[MAXN][2]; // Stores the powers of P modulo M
const ll P=9973; // Change M and P if you want to
const ll M=1e9+9;
const ll M1=1e9+7;
void calc_hashes(string s,string s1){
    hsh[0][0][0]=hsh[0][1][0]=hsh[0][0][0]=hsh[0][1][1]=1;
    pw[0][0]=pw[0][1]=1;
    for(int i=1;i<s.size();i++){
        pw[i][0]=(pw[i-1][0]*P)%M;
        pw[i][1]=(pw[i-1][1]*P)%M1;
    }
    for(int i=0;i<s.size();i++){
        hsh[i+1][0][0]=((hsh[i][0][0]*P)%M+s[i])%M;
        hsh[i+1][0][1]=((hsh[i][0][1]*P)%M1+s[i])%M1;
        hsh[i+1][1][0]=((hsh[i][1][0]*P)%M+s1[i])%M;
        hsh[i+1][1][1]=((hsh[i][1][1]*P)%M1+s1[i])%M1;
    }
}
ll get_hash(int a,int b, int s, int fs){ // Endpoints of the substring
    ll ab=(hsh[b+1][s][fs]-(hsh[a][s][fs]*pw[b-a+1][fs])%M+M)%M;
    if(fs==1){
        ab=(hsh[b+1][s][fs]-(hsh[a][s][fs]*pw[b-a+1][fs])%M1+M1)%M1;
    }
    return ab;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a;
        cin>>a;
        string mx;
        int ix=0;
        int n=a.size();
        while(ix<n-1-ix&&a[ix]==a[n-1-ix]){
            ix++;
        }
        int st=0;
        int ex=0;
        mx=a.substr(0,ix);
        string rev=mx;
        reverse(rev.begin(),rev.end());
        a=a.substr(ix,n-2*ix);
        n=a.size();
        string bt=a;
        reverse(bt.begin(),bt.end());
        calc_hashes(a,bt);
        for(int j=0;j<n;j++){
            /*
            string cs=a.substr(0,(j+1)/2);
            string ct=a.substr((j+1)/2,j-(j+1)/2+1);
            reverse(ct.begin(),ct.end());
            if(cs.substr(0,min(cs.size(),ct.size()))
                ==ct.substr(0,min(cs.size(),ct.size()))){
                tp=a.substr(0,j+1);
            }
            */
            int ad=0;
            if((j+1)%2==1){
                ad=1;
            }
            if(get_hash(0,(j+1)/2-1,0,0)==
                get_hash(n-1-j,n-1-j+(j+1)/2-1,1,0)&&
                get_hash(0,(j+1)/2-1,0,1)==
                get_hash(n-1-j,n-1-j+(j+1)/2-1,1,1)){
                st=0;
                ex=j;
            }
        }
        for(int j=n-1;j>-1;j--){
            /*
            string cs=a.substr(j,(n-j)/2);
            string ct=a.substr(j+(n-j)/2);
            reverse(ct.begin(),ct.end());
            if(cs.substr(0,min(cs.size(),ct.size()))
                ==ct.substr(0,min(cs.size(),ct.size()))){
                if(tp.size()<n-j){
                    tp=a.substr(j);
                }
            }
            */
            int ad=0;
            if((n-j)%2==1){
                ad=1;
            }
            if(get_hash(j,j+(n-j)/2-1,0,0)==
             get_hash(0,(n-j)/2-1,1,0)&&
             get_hash(j,j+(n-j)/2-1,0,1)==
             get_hash(0,(n-j)/2-1,1,1)){
                if(n-j>ex-st+1){
                    st=j;
                    ex=n-1;
                }
            }
        }
        mx=mx+a.substr(st,ex-st+1)+rev;
        cout<<mx<<'\n';
    }
    return 0;
}

