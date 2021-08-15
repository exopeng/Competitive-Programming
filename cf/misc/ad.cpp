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
const int MAXN = 3e6;
//store test cases here
/*


*/
bool tp[MAXN];
bool usd[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        vector<int> ls;
        int n;cin>>n;
        for(int j=0;j<n;j++){
            int a;cin>>a;
            a=abs(a);
            if(tp[a]==false&&a!=0){
                tp[a]=true;
                ls.pb(a);
            }
        }
        if(ls.size()<n){
            cout<<"YES"<<'\n';
        }else{
            bool g=false;
            for(int j=0;j<pow(3,n);j++){
                string tl;
                int lt=j;
                while(lt){
                    tl+=to_string(lt%3);
                    lt/=3;
                }
                ll sm=0;
                for(int f=0;f<tl.size();f++){
                    if(tl[f]=='1'){
                        sm+=ls[f];
                        usd[ls[f]]=true;
                    }else if(tl[f]=='2'){
                        sm+=-1*ls[f];
                        usd[ls[f]]=true;
                    }                
                }
                if(tp[abs(sm)]==true&&usd[abs(sm)]==false){
                    g=true;
                }
                for(int f=0;f<tl.size();f++){
                    usd[ls[f]]=false;
                }
            }
            if(g){
                cout<<"YES"<<'\n';
            }else{
                cout<<"NO"<<'\n';
            }
        }
        for(int f=0;f<ls.size();f++){
            tp[ls[f]]=false;
        }
    }
    return 0;
}

