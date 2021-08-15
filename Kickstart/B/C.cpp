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
    	ll z;
        cin>>z;
        ll a1=1;
        ll np=1;
        for(ll j=pow(z,0.5);j>=2;j--){
            bool ps=true;
            for(ll f=2;f*f<=j;f++){
                if(j%f==0){
                    ps=false;
                    break;
                }
            }
            if(ps){
                if(np==1){
                    np=j+1;
                    while(true){
                        bool pt=true;
                        for(ll f=2;f*f<=np;f++){
                            if(np%f==0){
                                pt=false;
                                break;
                            }
                        }
                        if(pt){
                            break;
                        }
                        np++;
                    }
                }
                //save current prime if greater
                if(np*j<=z){
                    a1=j*np;
                    break;
                }
                np=j;
            }
        }
        cout<<"Case #"<<(i+1)<<": "<<a1<<"\n";
    }
    return 0;
}

