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
    vector<ll> pt;
    vector<bool> ip(1e6+1,true);
    ip[0]=ip[1]=false;
    for(int i=2;i*i<=1e6;i++){
        if(ip[i]){
            pt.pb(i);
            for(int j=i*i;j<=1e6;j+=i)
                ip[j]=false;
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
        map<int,int> mx;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            for(int f=0;f<pt.size();f++){
                if(pt[f]*pt[f]>a){
                    break;
                }
                int ct=0;
                while(a%pt[f]==0){
                    ct++;
                    a/=pt[f];
                }
                if(ct&&(mx.find(pt[f])==mx.end()||ct>mx[pt[f]])){
                    mx[pt[f]]=ct;
                }
            }
            if(a!=1){
                if(mx.find(a)==mx.end()){
                    mx[a]=1;
                }
            }
        }
        ll ans=0;
        for(auto it=mx.begin();it!=mx.end();it++){
            ans+=it->s;
            //cout<<it->f<<" ";
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}

