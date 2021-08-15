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
int b[MAXN];
vector<int> ix[MAXN];
char as[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        map<char,int> ms;
        string s;
        int m;
        cin>>s>>m;
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        for(int j=0;j<s.size();j++){
            ms[s[j]]++;
        }
        set<int> tk;
        //how many unique letters
        int ct=0;
        while(true){
            for(int j=0;j<m;j++){
                if(b[j]==0&&tk.find(j)==tk.end()){
                    tk.is(j);
                    ix[ct].pb(j);
                }
            }
            for(int j=0;j<m;j++){
                if(b[j]){
                    for(int f=0;f<ix[ct].size();f++){
                        b[j]-=abs(j-ix[ct][f]);
                    }
                }
            }
            ct++;
            if(tk.size()==m){
                break;
            }
        }
        auto it=prev(ms.end());
        for(int j=0;j<ct;j++){
            while(it->s<ix[j].size()){
                it=prev(it);
            }
            for(int f=0;f<ix[j].size();f++){
                as[ix[j][f]]=it->f;
            }
            it=prev(it);
        }
        for(int j=0;j<m;j++){
            cout<<as[j];
        }
        cout<<'\n';
        for(int j=0;j<26;j++){
            ix[j].clear();
        }
    }
    return 0;
}

