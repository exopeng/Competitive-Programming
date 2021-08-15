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
int n,a,b,c,d;
vector<pii> xs;
vector<pii> ys;
map<pair<pii,int> ,int> di;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(){
    queue<pair<pii,int> > q;
    for(int i=0;i<4;i++){
        int newx=a+dx[i];
        int newy=b+dy[i];
        if(i<2){
            //going backwards
            auto it = lb(ys.begin(),ys.end(),mp(newy,newx));
            if(i==1){
                it=prev(it);
            }
            if(it!=ys.end()&&it->f==newy){
                pii temp = *it;
                swap(temp.f,temp.s);
                if(temp.f==c&&temp.s==d){
                    di[mp(temp,-1)]=0;
                }else{
                    temp.f-=dx[i];
                    q.push(mp(temp, 1));
                    di[mp(temp,1)]=1;
                } 
            }
        }else{
            auto it = lb(xs.begin(),xs.end(),mp(newx,newy));
            if(i==3){
                it=prev(it);
            }
            if(it!=xs.end()&&it->f==newx){
                pii temp = *it;
                if(temp.f==c&&temp.s==d){
                    di[mp(temp,-1)]=0;
                }else{
                    temp.s-=dy[i];
                    q.push(mp(temp, 2));
                    di[mp(temp,2)]=1;
                }
            }
        }
    }
    while(!q.empty()){
        pair<pii,int> temp=q.front();
        q.pop();
        if(temp.s==1){ 
            auto it = lb(xs.begin(),xs.end(),temp.f);
            if(it!=xs.end()&&it->f==temp.f.f){
                pii temp1 = *it;
                if(temp1.f==c&&temp1.s==d){
                    di[mp(temp1,-1)]=min(di[mp(temp1,-1)],di[temp]);
                } else{
                    temp1.s-=1;
                    if(di.find(mp(temp1,2))==di.end() || di[mp(temp1,2)]>di[temp]+1){
                        q.push(mp(temp1, 2));
                        di[mp(temp1,2)]=di[temp]+1;
                    }
                }
            }
            it = prev(it);
            if(it!=xs.end()&&it->s==temp.f.f){
                pii temp1 = *it;
                if(temp1.f==c&&temp1.s==d){
                    di[mp(temp1,-1)]=min(di[mp(temp1,-1)],di[temp]);
                } else{
                    temp1.s-=-1;
                    if(di.find(mp(temp1,2))==di.end() || di[mp(temp1,2)]>di[temp]+1){
                        q.push(mp(temp1, 2));
                        di[mp(temp1,2)]=di[temp]+1;
                    }
                }   
            }
            //check backwards
            //based on orientations, NSEW
            pii temp2=temp.f;
            it = lb(ys.begin(),ys.end(),temp2);

        } else{
            pii temp2=temp.f;
            swap(temp2.f,temp2.s);
            auto it = lb(ys.begin(),ys.end(),temp2);
            if(it!=ys.end()&&it->f==temp2.f){
                pii temp1=*it;
                swap(temp1.f,temp1.s);
                if(temp1.f==c&&temp1.s==d){
                    di[mp(temp1,-1)]=min(di[mp(temp1,-1)],di[temp]);
                } else {
                    temp1.f-=1;
                    if(di.find(mp(temp1,1))==di.end() || di[mp(temp1,1)]>di[temp]+1){
                        q.push(mp(temp1, 1));
                        di[mp(temp1,1)]=di[temp]+1;
                    }
                }
            }
            it = prev(it);
            if(it!=ys.end()&&it->f==temp2.f){
                pii temp1=*it;
                swap(temp1.f,temp1.s);
                if(temp1.f==c&&temp1.s==d){
                    di[mp(temp1,-1)]=min(di[mp(temp1,-1)],di[temp]);
                } else{
                    temp1.f-=-1;
                    if(di.find(mp(temp1,1))==di.end() || di[mp(temp1,1)]>di[temp]+1){
                        q.push(mp(temp1, 1));
                        di[mp(temp1,1)]=di[temp]+1;
                    }
                }
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("crash.in","r",stdin);
    freopen("crash.out","w",stdout);
    cin>>n>>a>>b>>c>>d;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        xs.pb(mp(x,y));
        ys.pb(mp(y,x));
    }
    xs.pb(mp(a,b));
    ys.pb(mp(b,a));
    xs.pb(mp(c,d));
    ys.pb(mp(d,c));
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    di[mp(mp(c,d),-1)]=INF;
    bfs();
    if(di[mp(mp(c,d),-1)]==INF){
        cout<<-1<<"\n";
    } else{
        cout<<di[mp(mp(c,d),-1)]<<"\n";
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
