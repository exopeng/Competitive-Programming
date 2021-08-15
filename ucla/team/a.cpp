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
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s,m,t;
        cin>>s;
        for(int f=0;f<s.size();f++){
            int j=f;
            while(j+1<s.size()&&s[j+1]==s[j]){
                j++;
            }
            m+=s[f];
            f=j;
        }
        t+=m[0];
        for(int f=1;f<m.size()-1;f++){
            if(m[f]=='a'||m[f]=='e'||
                m[f]=='o'||m[f]=='i'||m[f]=='u'){
            }else{
                t+=m[f];
            }
        }
        if(m.size()!=1){
            t+=m[m.size()-1];
        }
        cout<<t;
        if(i==n-1){
            cout<<"\n";
        }else{
            cout<<" ";
        }
    }
    return 0;
}

