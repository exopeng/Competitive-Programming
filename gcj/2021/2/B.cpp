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
ll s[MAXN][2];
int qs[101];
ll as[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>qs[i];
    }
    for(ll i=3;i<MAXN;i++){
        if(s[i][0]){
            if(i*(i-1)<MAXN){
                s[i*(i-1)][0]=s[i][0]+i*(i-1);
                s[i*(i-1)][1]=s[i][1]+1;
            }
        }else{
            s[i][0]=i;
            s[i][1]=1;
            if(i*(i-1)<MAXN){
                s[i*(i-1)][0]=s[i][0]+i*(i-1);
                s[i*(i-1)][1]=s[i][1]+1;
            }
        }
        for(int j=0;j<t;j++){
            if(s[i][0]>=qs[j]){
                int ix=i;
                if(s[i][0]==qs[j]){
                    as[j]=max(as[j],s[i][1]);
                    continue;
                }
                while(pow(1+4*ix,0.5)==(int)pow(1+4*ix,0.5)&&(1+(int)pow(1+4*ix,0.5))%2==0){
                    ix=(1+pow(1+4*ix,0.5))/2; 
                    if(s[i][0]-s[ix][0]+ix==qs[j]){
                        as[j]=max(as[j],s[i][1]-s[ix][1]+1);
                        break;
                    }   
                    if(s[i][0]-s[ix][0]+ix>=qs[j]){
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<"Case #"<<(i+1)<<": "<<as[i]<<"\n";
    }
    return 0;
}

