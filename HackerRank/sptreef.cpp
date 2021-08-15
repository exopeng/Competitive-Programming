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
int n,m;
int parent[MAXN];
int size[MAXN];
vector<pair<pii,pii> > edge;
bool cmp(pair<pii,pii>& a, pair<pii,pii>& b) {
	if((double)a.s.f/a.s.s == (double)b.s.f/b.s.s){
        if((double)a.s.f/a.s.s <= 1){
            return a.s.f<b.s.f;
        } else{
            return a.s.f>b.s.f;
        }
	}
	return (double)a.s.f/a.s.s > (double)b.s.f/b.s.s;
}
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
//uses path compression, so every node in the set points to the root node(parent)
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
//merges the smaller of the two sets to the larger
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	make_set(i);
    }
    for(int i=0;i<m;i++){
    	int a,b,c,d;
    	cin>>a>>b>>c>>d;
    	edge.pb(mp(mp(a,b),mp(c,d)));
    }
    sort(edge.begin(),edge.end(),cmp);
    int a=0;
    int b=0;
    for(int i=0;i<edge.size();i++){
    	cout<<edge[i].f.f<<" "<<edge[i].f.s<<" "<<edge[i].s.f<<" "<<edge[i].s.s<<"\n";
  		//take whatever is most beneficial to the current state
    	if(find_set(edge[i].f.f)!=find_set(edge[i].f.s)){
    		union_set(edge[i].f.f,edge[i].f.s);
    		a+=edge[i].s.f;
    		b+=edge[i].s.s;
    	}
    }
    //cout<<a<<" "<<b<<"\n";
    cout<<a/gcd(a,b)<<"/"<<b/gcd(a,b)<<"\n";
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

