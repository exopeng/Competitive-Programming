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
int a[MAXN];
int leq[MAXN][2];
int geq[MAXN][2];
int mn[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
            mn[j]=-1;
        }
        vector<pii> tp;
        vector<pii> tp1;
        vector<pii> tp2;
        vector<pii> tp3;
        for(int j=0;j<n;j++){
            while(!tp.empty()&&tp[tp.size()-1].f>a[j]){
                tp.pop_back();
            }
            if(tp.empty()){
                leq[j][0]=-1;
            }else{
                leq[j][0]=tp[tp.size()-1].s;
            }
            tp.pb(mp(a[j],j));
            while(!tp2.empty()&&tp2[tp2.size()-1].f<a[j]){
                tp2.pop_back();
            }
            if(tp2.empty()){
                geq[j][0]=-1;
            }else{
                geq[j][0]=tp2[tp2.size()-1].s;
            }
            tp2.pb(mp(a[j],j));
        }
        for(int j=n-1;j>-1;j--){
            while(!tp1.empty()&&tp1[tp1.size()-1].f<a[j]){
                tp1.pop_back();
            }
            if(tp1.empty()){
                geq[j][1]=-1;
            }else{
                geq[j][1]=tp1[tp1.size()-1].s;
            }
            tp1.pb(mp(a[j],j));
             while(!tp3.empty()&&tp3[tp3.size()-1].f>a[j]){
                tp3.pop_back();
            }
            if(tp3.empty()){
                leq[j][1]=-1;
            }else{
                leq[j][1]=tp3[tp3.size()-1].s;
            }
            tp3.pb(mp(a[j],j));
        }
        ll as=0;
        int mx=-1;
        for(int j=0;j<n;j++){
            if(leq[j][0]>=0&&geq[j][1]>=0){
                mn[geq[j][1]]=max(mn[geq[j][1]],leq[j][0]);
            }
            if(leq[j][1]>=0&&geq[j][0]>=0){
                mn[leq[j][1]]=max(mn[leq[j][1]],geq[j][0]);
            }
        }
        int tf=-1;
        for(int j=0;j<n;j++){
            tf=max(tf,mn[j]);
            if(tf>=0){
                as+=tf+1;
            }
            //cout<<tf<<" ";
        }
        //cout<<'\n';
        cout<<(n*(n-1))/2-as+n<<'\n';
    }
    return 0;
}

