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
const int MAXN = 2e6+100;
//store test cases here
/*


*/
int ks[MAXN];
int pf[MAXN];
double pt[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int tot1=0;
        for(int j=0;j<n;j++){
            ks[j%k]+=s[j]-'0';
            tot1+=s[j]-'0';
            if(j-k>=0){
                pf[j]+=pf[j-k];
            }
            pf[j]+=s[j]-'0';
            pt[j]=(2*pf[j]-(double)(j)/k);
        }
        for(int j=0;j<n;j++){
            if(j-k>=0){
                pt[j]=min(pt[j],pt[j-k]);
            }
        }
        int mn=INF;
        for(int j=0;j<k;j++){
            for(int f=j;f<n;f+=k){
                //can only get numbers to the left
                //epsilon stuffff?
                int cu=ceil(tot1-ks[j]+(double)(f)/k-pf[f]+(pt[f]));
                if (tot1-ks[j]+(double)(f)/k-pf[f]+(pt[f])-
                    (int)(tot1-ks[j]+(double)(f)/k-pf[f]+(pt[f]))<=1e-4){
                    cu=tot1-ks[j]+(double)(f)/k-pf[f]+(pt[f]);
                }
                cu=min(cu,tot1-ks[j]+(f+k)/k-pf[f]);
                mn=min(mn,cu+pf[f+((int)((n-1-f)/k))*k]-pf[f]);
                //cout<<(f+((int)((n-f)/k))*k)<<" "<<f<<" ____";
            }
        }
        cout<<mn<<'\n';
        for(int j=0;j<n;j++){
            //cout<<pf[j]<<" ";
            ks[j]=0;
            pt[j]=0;
            pf[j]=0;
        }
    }
    return 0;
}

