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
#define s second
#define pii pair<int,int>
#define is insert
const long long INF = 1000000000;
const long long MOD = 1000000007;
const int MAXN = 2e5;

//store test cases here
/*


*/ 
int n,me,q;
int m[501][5001];
int dest[5001];
long long ct[5001];
long long ans[5001];
set<int> taken;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("dancingrobots.in","r",stdin);
    freopen("dancingrobots.out","w",stdout);
    cin>>n>>me>>q;
    for(int i=0;i<me;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
            m[i][j]--;
        }
    }

    for(int i=0;i<n;i++){
        int curr=i;
        int it=0;
        for(int j=0;j<me;j++){
            curr=m[it][curr];
            it++;
            if(curr==n-1){
                ct[i]++;
            }
        }
        dest[i]=curr;
        //cout<<dest[i]<<" "<<ct[i]<<"\n";
    }

    
    for(int i=0;i<n;i++){
        if(taken.find(i)==taken.end()){
            vector<long long> sum;
            vector<int> path;
            set<int> found;
            int j=i;
            //has to be a one to one matching,else empty spots
            /*
            while(found.find(j)==found.end()){
                found.is(j);
               //cout<<j<<"\n";
                j=dest[j];
            }
            */
            bool on=true;
            while(found.find(j)==found.end()){
                found.is(j);
                if(on){
                    sum.pb(ct[j]);
                    on=false;
                }else{
                    sum.pb(ct[j]+sum[sum.size()-1]);
                }
                taken.is(j);
                path.pb(j);
                j=dest[j];
            }
            for(int e=0;e<path.size();e++){
                ans[path[e]]=sum[sum.size()-1]*(q/sum.size());
                if(q%sum.size()!=0){
                    if(e!=0){
                        if(q%(sum.size())+e-1>path.size()-1){
                            ans[path[e]]+=sum[(q%(sum.size())+e-1) 
                            % (path.size())]+sum[path.size()-1]-sum[e-1];
                        }else{
                            ans[path[e]]+=sum[q%(sum.size())+e-1]-sum[e-1];
                        }
                    }else{
                        ans[path[e]]+=sum[q%(sum.size())-1];
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
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
