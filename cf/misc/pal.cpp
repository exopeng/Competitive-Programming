#include <bits/stdc++.h>
using namespace std;
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
const long long MOD = 998244353;
const int MAXN = 2e6;
//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        string s;
        cin>>n>>s;
        int ct0=0;
        int ct1=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='0'&&s[n-1-i]=='0'){
                ct0++;
            }else if(s[i]=='0'&&s[n-1-i]=='1'||
                s[i]=='1'&&s[n-1-i]=='0'){
                ct1++;
            }
        }
        //handle odd lengths separately
        int as=0;
        bool rev=false;
        int sg=1;
        while(ct0+ct1>0){
            if(ct1==0){
                if(n%2&&s[n/2]=='0'){
                    s[n/2]='1';
                }else{
                    ct0--,ct1++;
                }  
                as+=sg;
            }else {
                if(rev){
                    if(ct1!=0){
                        ct1--;
                    }else{
                        ct0--,ct1++;
                    }
                    rev=false;
                }else{
                    rev=true;
                    as-=sg;
                }
                as+=sg;
            }
            sg*=-1;
        }
        if(as<0){
            cout<<"ALICE";
        }else if(as==0){
            cout<<"DRAW";
        }else{
            cout<<"BOB";
        }
        cout<<"\n";
    }    
    return 0;
}

