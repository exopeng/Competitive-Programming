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
const int MAXN = 2e5+100;
//store test cases here
/*


*/

int as[MAXN];
int wt[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        set<int> tk,ntk;
        vector<int> lt;
        map<int,int> atp;
        int n;
        cin>>n;
        int k=0;
        for(int j=0;j<n;j++){
            cin>>wt[j];
            wt[j]--;
            if(tk.find(wt[j])==tk.end()){
                k++;
                tk.is(wt[j]);
                as[j]=wt[j];
                atp[wt[j]]=j;
            }else{
                lt.pb(j);
            }
        }
        for(int j=0;j<n;j++){
            if(tk.find(j)==tk.end()){
                ntk.is(j);
            }
        }
        
        for(int j=0;j<lt.size();j++){
            auto it=ntk.begin();
            if(*it==lt[j]){
                if(j==lt.size()-1){
                    as[lt[j]]=wt[lt[j]];
                    as[atp[wt[lt[j]]]]=lt[j];
                }else{
                    as[lt[j]]=*(next(it));
                    ntk.erase(as[lt[j]]);
                    atp[as[lt[j]]]=lt[j];
                }
            }else{
                as[lt[j]]=*it;
                ntk.erase(as[lt[j]]);
                atp[as[lt[j]]]=lt[j];
            }
        }   
        cout<<k<<"\n";
        for(int j=0;j<n;j++){
            cout<<(as[j]+1)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

