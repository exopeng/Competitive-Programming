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
long long hsh[MAXN];
long long hsh1[MAXN];
long long pw[MAXN]; // Stores the powers of P modulo M
const long long P = 9973; // Change M and P if you want to
const long long M = 1e9 + 9;
void calc_hashes(string s,bool o) {
    hsh[0] = 1;
    hsh1[0] = 1;
    pw[0]=1;
    for(int i=1;i<s.size();i++){
        pw[i]=(pw[i-1]*P) % M;
    }
    for (int i = 0; i < s.size(); i++){
        if(!o){
            hsh[i + 1] = ((hsh[i] * P) % M + s[i]) % M;
        }else{
            hsh1[i + 1] = ((hsh1[i] * P) % M + s[i]) % M;
        }
    }
}

long long get_hash(int a, int b,bool o) { // Endpoints of the substring
    long long ab=(hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % M + M) % M;
    if(o){
        ab=(hsh1[b + 1] - (hsh1[a] * pw[b - a + 1]) % M + M) % M;
    }
    return ab;
}
int ans=0;
int sht=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string a,b;
    cin>>n>>a>>b;
    calc_hashes(a,false);
    calc_hashes(b,true);
    cout<<get_hash(0,2,false)<<" "<<(get_hash(0,0,true)+get_hash(1,2,true)*pw[2+1-3+1]) % M<<"\n";
    /*
    for(int i=0;i<n;i++){
        int lo=0;
        int hi=n;
        while(lo!=hi){
            int mid=(lo+hi+1)/2;
            ll val=0;
            if(i+mid-1>n-1){
                val=get_hash(i,i+mid-1,true)+get_hash(0,i+mid-1-(n-1)-1,true);
            }else{
                val=get_hash(i,i+mid-1,true);
            }
            //check neg
            if(get_hash(0,mid-1,false)==val){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        if(lo>ans){
            ans=lo;
            sht=i;
        }
    }
    cout<<sht<<" "<<ans<<"\n";
    */
    return 0;
}

