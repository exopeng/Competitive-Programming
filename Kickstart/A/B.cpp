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
int g[1001][1001];
int ls[1001][1001][4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int r,c;
        ll ans=0;
        cin>>r>>c;
        for(int j=0;j<r;j++){
            for(int f=0;f<c;f++){
                cin>>g[j][f];
                ls[j][f][0]=ls[j][f][1]=ls[j][f][2]=ls[j][f][3]=0;
            }
        }
        //0123->NESW
        for(int j=0;j<r;j++){
            //W
            ls[j][0][3]=g[j][0];
            for(int f=1;f<c;f++){
                ls[j][f][3]=g[j][f]*ls[j][f-1][3]+g[j][f];
            }
            //E
            ls[j][c-1][1]=g[j][c-1];
            for(int f=c-2;f>-1;f--){
                ls[j][f][1]=g[j][f]*ls[j][f+1][1]+g[j][f];
            }
        }
        for(int j=0;j<c;j++){
            //N
            ls[0][j][0]=g[0][j];
            for(int f=1;f<r;f++){
                ls[f][j][0]=ls[f-1][j][0]*g[f][j]+g[f][j];
            }
            //S
            ls[r-1][j][2]=g[r-1][j];
            for(int f=r-2;f>-1;f--){
                ls[f][j][2]=ls[f+1][j][2]*g[f][j]+g[f][j];
            }
        }
        for(int j=0;j<r;j++){
            for(int f=0;f<c;f++){
                for(int e=0;e<4;e++){
                    //cout<<j<<" "<<f<<" "<<ls[j][f][e]<<"\n";
                    if(ls[j][f][e]>=4){
                        if(ls[j][f][e]/2<=ls[j][f][(e+1)%4]){
                            ans+=max(ls[j][f][e]/2-1,0);
                        }else{
                            ans+=max(ls[j][f][(e+1)%4]-1,0);
                        }
                        if(ls[j][f][e]/2<=ls[j][f][(e+3)%4]){
                            ans+=max(0,ls[j][f][e]/2-1);
                        }else{
                            ans+=max(ls[j][f][(e+3)%4]-1,0);
                        }
                    }
                    
                }
            }
        }
    	cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 */

