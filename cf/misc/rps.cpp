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
const int MAXN = 5e5;
//store test cases here
/*


*/
int a[3];
int b[3];
int as[3]={0,1,2};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
    int mn=2*INF;
    int mx=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
    vector<pii> tp1,tp2;
    for(int i=0;i<3;i++){
        tp1.pb(mp(a[i],i));
        tp2.pb(mp(b[i],i));
    }
    do{
        do{
            vector<pii> t1=tp1;
            vector<pii> t2=tp2;
            int ix1=0;
            int ix2=0;
            int ct=0;
            while(true){
                while(ix1<3&&t1[ix1].f==0){
                    ix1++;
                }
                while(ix2<3&&t2[ix2].f==0){
                    ix2++;
                }
                if(ix1>2||ix2>2){
                    break;
                }
                int mnt=min(t1[ix1].f,t2[ix2].f);
                t1[ix1].f-=mnt,t2[ix2].f-=mnt;
                if(t2[ix2].s==(t1[ix1].s+1)%3){
                    ct+=mnt;
                }
            }
            mn=min(mn,ct);
        }while(next_permutation(tp2.begin(),tp2.end()));
    }while(next_permutation(tp1.begin(),tp1.end()));
    /*
    for(int i=0;i<3;i++){
        int mtn=min(a[i],b[i]);
        a[i]-=mtn,b[i]-=mtn;
        if(a[i]){
            tp1.pb(mp(a[i],i));
        }
        if(b[i]){
            tp2.pb(mp(b[i],i));
        }
    }
    if(tp1.size()==1&&tp2.size()==1){
        if(tp2[0].s==(tp1[0].s+1)%3){
            mn+=tp1[0].f;
        }
    }else if(tp1.size()==2&&tp2.size()==1){
        if(tp1[0].s==(tp2[0].s+2)%3){
            mn+=tp1[0].f;
        }else{
            mn+=tp1[1].f;
        }
    }else if(tp1.size()==1&&tp2.size()==2){
        if(tp1[0].s==(tp2[0].s+2)%3){
            mn+=tp2[0].f;
        }else{
            mn+=tp2[1].f;
        }
    }
    //check initial state?
    /*
    do{
        int mt=0;
        vector<int> t1,t2;
        vector<pii> tp1,tp2;
        for(int j=0;j<3;j++){
            t1.pb(a[j]);
            t2.pb(b[j]);
        }
        
        for(int j=0;j<3;j++){
            int mnt=min(t1[j],t2[as[j]]);
            t1[j]-=mnt,t2[as[j]]-=mnt;
            if(as[j]==(j+1)%3){
                mt+=mnt;
            }
            if(t1[j]){
                tp1.pb(mp(t1[j],j));
            }
            if(t2[as[j]]){
                tp2.pb(mp(t2[as[j]],as[j]));
            }
        }
        if(tp2.size()==1&&tp1.size()==2){
            int js=(tp2[0].s+2)%3;
            if(tp1[0].s==js){
                mt+=tp1[0].f;
            }else if(tp1[1].s==js){
                mt+=tp1[1].f;
            }
        }else if(tp1.size()==1&&tp2.size()==2){
            int js=(tp1[0].s+1)%3;
            if(tp2[0].s==js){
                mt+=tp2[0].f;
            }else if(tp2[1].s==js){
                mt+=tp2[1].f;
            }
        }else if(tp1.size()==1&&tp2.size()==1){
            if((tp1[0].s+1)%3==tp2[0].s){
                mt+=tp1[0].f;
            }
        }
        mn=min(mn,mt);
    }while(next_permutation(as,as+3));
    */
    cout<<mn<<" "<<mx<<'\n';
    return 0;
}

