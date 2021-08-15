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
const int MAXN = 2e7;
//store test cases here
/*


*/
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int mp;
    cout<<"? 1 "<<n<<"\n";
    cout.flush();
    cin>>mp;
    int rp;
    bool r=true;
    if(mp!=1){
        cout<<"? 1 "<<mp<<"\n";
        cout.flush();
        cin>>rp;
        if(rp==mp){
            r=false;
        }
    }
    if(r){
        //handle mp==n
        int lo=mp+1;
        int hi=n;
        while(lo!=hi){
            int mid=(lo+hi)/2;
            cout<<"? "<<mp<<" "<<mid<<"\n";
            cout.flush();
            cin>>rp;
            if(rp==mp){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        cout<<"! "<<lo<<"\n";
    }else{
        int lo=1;
        int hi=mp-1;
        while(lo!=hi){
            int mid=(lo+hi+1)/2;
            cout<<"? "<<mid<<" "<<mp<<"\n";
            cout.flush();
            cin>>rp;
            if(rp==mp){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<"! "<<lo<<"\n";
    }
    cout.flush();
    return 0;
}

