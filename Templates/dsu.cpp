#include <bits/stdc++.h>
using namespace std; 


int p[MAXN];
int sz[MAXN];
void make_set(int v){
    p[v]=v;
    sz[v]=1;
}
int find_set(int v){
    if(v==p[v])
        return v;
    return p[v]=find_set(p[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b])
            swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
}


int n,q;
int main() {
    cin>>n>>q;
    for(int i=0;i<n;i++){
        make_set(i);
    }
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        if(a==0){
            int b,c;
            cin>>b>>c;
            union_sets(b,c);
        }else{
            int b,c;
            cin>>b>>c;
            if(find_set(b)==find_set(c)){
                cout<<1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }
    }
}

