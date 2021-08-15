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
    for(int j=0;j<t;j++){
        ll a,b,c,d,f,g,h,i;
        ll as=0;
        cin>>a>>b>>c>>d>>f>>g>>h>>i;
        if((a+c+2*INF)%2==0&&(a+c)/2==b){
            as++;
        }
        if((a+g+2*INF)%2==0&&(a+g)/2==d){
            as++;
        }
        if((g+i+2*INF)%2==0&&(g+i)/2==h){
            as++;
        }
        if((c+i+2*INF)%2==0&&(c+i)/2==f){
            as++;
        }
        map<ll,ll> mt;
        if((i+a+2*INF)%2==0){
            mt[(i+a)/2]++;
        }
        if((h+b+2*INF)%2==0){
            mt[(h+b)/2]++;
        }
        if((g+c+2*INF)%2==0){
            mt[(g+c)/2]++;
        }
        if((f+d+2*INF)%2==0){
            mt[(f+d)/2]++;
        }
        ll ts=0;
        for(auto it=mt.begin();it!=mt.end();it++){
            ts=max(ts,it->s);
        }
        cout<<"Case #"<<(j+1)<<": "<<(as+ts)<<'\n';
    }
    return 0;
}

