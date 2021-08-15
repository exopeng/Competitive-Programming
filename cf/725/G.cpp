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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll x,y,a,b;
        
        cin>>x>>y>>a>>b;
        if(a<b){
            swap(a,b);
        }
        ll lo=0;
        ll hi=INF;
        while(lo!=hi){
            ll z=(lo+hi+1)/2;
            if(a==b){
                if(x/z>=a&&y/z>=a){
                    lo=z;
                }else{
                    hi=z-1;
                }
            }else{
                //watch out in inequalities when dividing negative number!!!
                ll f,f1;
                //right
                f=floorl((double)(x-z*b)/(a-b));
                //left
                f1=ceill(((double)(y-z*a))/(b-a));
                //cout<<f<<" "<<f1<<" : "<<0<<" "<<z<<"\n";
                /*
                if(max(f1,0ll)<=min(f,z)){
                    lo=z;
                }else{
                    hi=z-1;
                }
                */
                if(f1>z||f<0||f<f1){
                    hi=z-1;
                }else{
                    lo=z;
                }
                
            }
        }
        cout<<lo<<"\n";
    }
    return 0;
}

