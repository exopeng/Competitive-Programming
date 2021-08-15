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
int b[MAXN];
int as[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int k,n,m;
        cin>>k>>n>>m;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        int l=0;
        int r=0;
        bool bg=true;
        for(int j=0;j<n+m;j++){
            if(l<n&&a[l]==0){
                as[j]=0;
                l++;
                k++;
            }else if(r<m&&b[r]==0){
                as[j]=0;
                r++;
                k++;
            }else{
                if(l<n&&r<m){
                    if(min(a[l],b[r])<=k){
                        as[j]=min(a[l],b[r]);
                        if(a[l]<b[r]){
                            l++;
                        }else{
                            r++;
                        }
                    }else{
                        bg=false;
                        break;
                    }
                }else if(l<n){
                    if(a[l]<=k){
                        as[j]=a[l];
                        l++;
                    }else{
                        bg=false;
                        break;
                    }
                }else{
                    if(b[r]<=k){
                        as[j]=b[r];
                        r++;
                    }else{
                        bg=false;
                        break;
                    }
                }
            }
        }
        if(bg){
            for(int j=0;j<n+m;j++){
                cout<<as[j]<<" ";
            }
            cout<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}

