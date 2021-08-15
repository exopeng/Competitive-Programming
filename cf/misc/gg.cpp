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
    int a,b,k;
    cin>>a>>b>>k;
    deque<int> f,f1;
    if(k!=0){
        f.pb(1),f.pb(0),f1.pb(0),f1.pb(1);
        k--;
        b--;
        a--;
    }
    while(k>0){
        if(a==0){
            f.pop_back(),f.pb(1),f.pb(0);
            f1.pb(1);
            b--;
        }else{
            f.pb(0),f1.push_front(0);
            a--;
        }
        k--;
    }  
    while(a>0){
        f.pb(0);
        f1.pb(0);
        a--;
    }
    while(b>0){
        f.push_front(1);
        f1.push_front(1);
        b--;
    }
    if(a<0||b<0||f1.front()==0||f1.front()==0){
        cout<<"No"<<'\n';
    }else{
        cout<<"Yes"<<'\n';
        while(f.size()>0){
            cout<<f.front();
            f.pop_front();
        }
        cout<<'\n';
        while(f1.size()>0){
            cout<<f1.front();
            f1.pop_front();
        }
        cout<<'\n';
    }
    return 0;
}

