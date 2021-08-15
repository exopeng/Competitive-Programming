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
const long long MOD = 1e9+7;
const int MAXN = 1e7+2;
//store test cases here
/*


*/
string ss[3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        string s1,s2,s3;
        cin>>n>>ss[0]>>ss[1]>>ss[2];
        map<int,pii> sp;
        for(int f=0;f<3;f++){
             for(int j=0;j<2*n;j++){
                if(ss[f][j]=='0'){
                    sp[f].f++;
                }else{
                    sp[f].s++;
                }
            }
        }
        map<int,vector<int>> tp;
        tp[0].pb(0),tp[1].pb(1),tp[0].clear(),tp[1].clear();
        for(int j=0;j<3;j++){
            if(sp[j].f>=sp[j].s){
                tp[0].pb(j);
            }else{
                tp[1].pb(j);
            }
        }
        //ix is what you will add between the other #'s'
        int ix=0;
        if(tp[0].size()>tp[1].size()){
            ix=1;
        }   
        //how many 0's after each 1(index)
        map<int,int> tx;
        string ff=ss[tp[!ix][0]];
        int lx=-1;
        for(int j=0;j<2*n;j++){
            if(ss[tp[!ix][1]][j]-'0'==ix){
                tx[lx]++;
            }else{
                lx++;
            }
        }
        int nd=0;
        if(ix){
            nd=sp[tp[!ix][1]].f-sp[tp[!ix][0]].f;
        }else{
            nd=sp[tp[!ix][1]].s-sp[tp[!ix][0]].s;
        }
        for(int j=0;j<nd;j++){
            ff+=to_string(!ix);
        }
        for(int j=0;j<tx[-1];j++){
            ff=to_string(ix)+ff;
        }
        int hw=-1;
        for(int j=0;j<ff.size();j++){
            cout<<ff[j];
            if(ff[j]-'0'==!ix){
                hw++;
                for(int m=0;m<tx[hw];m++){
                    cout<<ix;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}

