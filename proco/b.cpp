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
int n;
set<pair<pii,pii>> act;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string s;
    int as=0;
    bool al=true;
    for(int i=0;i<2*n*n-2*n;i++){
        pii p1,p2;
        bool g=false;
        cin>>p1.f>>p1.s>>p2.f>>p2.s;
        if(p1.f==p2.f){
            if(p1.s>p2.s){
                swap(p1,p2);
            }
            //up1
            pii t1=mp(p1.f-1,p1.s);
            //down 1
            pii t2=mp(p1.f+1,p1.s);
            //up2
            pii t3=mp(p2.f-1,p2.s);
            //down 2
            pii t4=mp(p2.f+1,p2.s);
            //upper square
            if(act.find(mp(t1,p1))!=act.end()&& 
                act.find(mp(t1,t3))!=act.end() 
                &&act.find(mp(t3,p2))!=act.end()){
                g=true;
                if(al){
                    as++;
                }
            }
            //lower square
            if(act.find(mp(p1,t2))!=act.end()&& 
                act.find(mp(t2,t4))!=act.end() 
                &&act.find(mp(p2,t4))!=act.end()){
                g=true;
                if(al){
                    as++;
                }
            }
        }else{
            if(p1.f>p2.f){
                swap(p1,p2);
            }
            //left 1
            pii t1=mp(p1.f,p1.s-1);
            //right 1
            pii t2=mp(p1.f,p1.s+1);
            //left 2
            pii t3=mp(p2.f,p2.s-1);
            //right 2
            pii t4=mp(p2.f,p2.s+1);
            //left square
            if(act.find(mp(t1,p1))!=act.end()&& 
                act.find(mp(t1,t3))!=act.end() 
                &&act.find(mp(t3,p2))!=act.end()){
                g=true;
                if(al){
                    as++;
                }
            }
            //right square
            if(act.find(mp(p1,t2))!=act.end()&& 
                act.find(mp(t2,t4))!=act.end() 
                &&act.find(mp(p2,t4))!=act.end()){
                g=true;
                if(al){
                    as++;
                }
            }
        }
        act.is(mp(p1,p2));
        if(al){
            s+="A";
        }else{
            s+="B";
        }
        if(!g){
            al=!al;
        }
    }
    cout<<s<<"\n";
    cout<<as<<" "<<pow(n-1,2)-as<<"\n";
    return 0;
}

