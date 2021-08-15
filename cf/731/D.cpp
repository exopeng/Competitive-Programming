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
int x[MAXN];
int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>x[j];
            a[j]=0;
            if(j){
                string at,ap;
                int t1=x[j-1];
                int t2=x[j];
                while(t1!=0){
                    if(t1%2){
                        at+="1";
                    }else{
                        at+="0";
                    }
                    t1/=2;
                }
                while(t2!=0){
                    if(t2%2){
                        ap+="1";
                    }else{
                        ap+="0";
                    }
                    t2/=2;
                }
                //reverse(at.begin(),at.end()),reverse(ap.begin(),ap.end());
                for(int f=0;f<at.size();f++){
                    if(at[f]=='1'&&(f>=ap.size()||ap[f]=='0')){
                        a[j]+=pow(2,f);
                    }
                }
                x[j]+=a[j];
            }
        }
        /*
        for(int j=0;j<n;j++){
            cout<<x[j]<<" ";
        }
        cout<<'\n';
        */
        for(int j=0;j<n;j++){
            cout<<a[j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

