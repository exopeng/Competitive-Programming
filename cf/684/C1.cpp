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
const long long INF = 1e15;
const long long MOD = 1e9+7;
const int MAXN = 1e2+5;
//store test cases here
/*


*/
int arr[MAXN][MAXN];
vector<string> ts;
int n,m;
void prin(int x1,int y1,int x2,int y2,int x3,int y3){
    arr[x1][y1]^=1;
    arr[x2][y2]^=1;
    arr[x3][y3]^=1;
    ts.pb(to_string(x1+1)+(" ")+to_string(y1+1)+(" ")+to_string(x2+1)+(" ")+
        to_string(y2+1)+(" ")+to_string(x3+1)+(" ")+to_string(y3+1)+"\n");
    /*
    cout<<"NEW"<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
}

void one(int i,int j){
    vector<pii> st;
    if(arr[i][j]==1){
        st.pb(mp(i,j));
    } 
    if(arr[i+1][j]==1){
        st.pb(mp(i+1,j));
    }
    if(arr[i][j+1]==1){
        st.pb(mp(i,j+1));
    }
    if(arr[i+1][j+1]==1){
        st.pb(mp(i+1,j+1));
    }
    prin(st[0].f,st[0].s,st[1].f,st[1].s,st[2].f,st[2].s);
}
void two(int i, int j){
    vector<pii> fs;
    vector<pii> ls;
    if(arr[i][j]==1){
        fs.pb(mp(i,j));
    }else{
        ls.pb(mp(i,j));
    }
    if(arr[i+1][j]==1){
        fs.pb(mp(i+1,j));
    }else{
        ls.pb(mp(i+1,j));
    }
    if(arr[i][j+1]==1){
        fs.pb(mp(i,j+1));
    }else{
        ls.pb(mp(i,j+1));
    }
    if(arr[i+1][j+1]==1){
        fs.pb(mp(i+1,j+1));
    }else{
        ls.pb(mp(i+1,j+1));
    }
    prin(ls[0].f,ls[0].s,ls[1].f,ls[1].s,fs[0].f,fs[0].s);
    one(i,j);
}
void three(int i, int j){
    vector<pii> fs;
    vector<pii> ls;
    if(arr[i][j]==1){
        fs.pb(mp(i,j));
    }else{
        ls.pb(mp(i,j));
    }
    if(arr[i+1][j]==1){
        fs.pb(mp(i+1,j));
    }else{
        ls.pb(mp(i+1,j));
    }
    if(arr[i][j+1]==1){
        fs.pb(mp(i,j+1));
    }else{
        ls.pb(mp(i,j+1));
    }
    if(arr[i+1][j+1]==1){
        fs.pb(mp(i+1,j+1));
    }else{
        ls.pb(mp(i+1,j+1));
    }
    prin(ls[0].f,ls[0].s,ls[1].f,ls[1].s,fs[0].f,fs[0].s);
    two(i,j);
}
void handle(int i, int j){
    int ct=arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
    if(4-ct==1){
        one(i,j);
    }else if(4-ct==2){
        two(i,j);
    }else if(4-ct==3){
        three(i,j);
    }else if(4-ct==0){
        prin(i,j,i+1,j+1,i,j+1);
        three(i,j);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++){
        cin>>n>>m;
        ts.clear();
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            for(int e=0;e<m;e++){
                arr[j][e]=s[e]-'0';
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                if(i==n-2&&j>=m-2){
                    continue;
                }
                if(arr[i][j]==1){
                    if(j==m-1){
                        prin(i,j,i+1,j,i+1,j-1);
                    }else{
                        prin(i,j,i+1,j,i+1,j+1);
                    }
                }
            }
        }
        for(int i=0;i<m-2;i++){
            if(arr[n-1][i]==1&&arr[n-2][i]==1){
                prin(n-1,i,n-1,i+1,n-2,i);
            }else if(arr[n-2][i]==1){
                prin(n-1,i+1,n-2,i+1,n-2,i);
            }else if(arr[n-1][i]==1){
                prin(n-1,i,n-1,i+1,n-2,i+1);
            }
        }
        handle(n-2,m-2);
        cout<<ts.size()<<"\n";
        for(int j=0;j<ts.size();j++){
            cout<<ts[j];
        }
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
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

