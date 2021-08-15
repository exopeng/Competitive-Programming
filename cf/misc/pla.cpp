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
const int MAXN = 7e6;
//store test cases here
/*


*/
int n,k,q;
string s;
int t[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<MAXN;i++){
        t[i]=1;
    }   
    cin>>k>>s>>q;
    reverse(s.begin(),s.end());
    for(int i=pow(2,k)-2;i>=0;i--){
        if(s[i]=='?'){
            t[i]=t[i*2+1]+t[i*2+2];
        }else if(s[i]=='1'){
            t[i]=t[i*2+1];
        }else{
            t[i]=t[i*2+2];
        }
    }
    for(int i=0;i<q;i++){
        int p;
        char c;
        cin>>p>>c;
        int curr=pow(2,k)-p-1;
        s[curr]=c;
        while(true){
            if(s[curr]=='?'){
                t[curr]=t[curr*2+1]+t[curr*2+2];
            }else if(s[curr]=='1'){
                t[curr]=t[curr*2+1];
            }else{
                t[curr]=t[curr*2+2];
            }
            if(curr==0){
                break;
            }
            curr=(curr-1)/2;
        }
        cout<<t[0]<<"\n";
    }
    return 0;
}

