#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
using namespace std::chrono;

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
const int MAXN = 1e6+1;
//store test cases here
/*


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
        cin>>n;
        bool cp=false;
        for(int j=2;j*j<=n;j++){
            if(n%j==0){
                cp=true;
                break;
            }   
        }
        if(n==2||n==17){
            cout<<"Mike"<<"\n";
        }else if(n==16||n==34||n==289) {
            cout<<"Tom"<<"\n";
        }else if(cp){
            cout<<"Mike"<<"\n";
        }else{
            cout<<"Tom"<<"\n";
        }
    }
    /*
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    */
    return 0;
}

