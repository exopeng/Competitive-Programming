#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int t[4*MAXN];
int arr[MAXN];
void build(int curr,int l,int r){
	if(l==r){
		t[curr]=arr[l];
	}else{
		int mid=(r+l)/2;
		build(curr*2,l,mid);
		build(curr*2+1,mid+1,r);
		t[curr]=t[curr*2]+t[curr*2+1];
	}
}
int sum(int curr,int tl,int tr,int l,int r){
	if(l>r){
		return 0;
	}
	if(l==tl&&r==tr){
		return t[curr];
	}
	int mid=(tl+tr)/2;
	return sum(curr*2,tl,mid,l,min(r,mid))+sum(curr*2+1,mid+1,tr,max(l,mid+1),r);
}
void update(int curr,int tl,int tr,int pos,int val){
	if(tl==tr){
		t[curr]=val;
	}else{
		int mid=(tl+tr)/2;
		if(pos<=mid){
			update(curr*2,tl,mid,pos,val);
		}else{
			update(curr*2+1,mid+1,tr,pos,val);
		}
		t[curr]=t[curr*2]+t[curr*2+1];
	}
}

//lazy segtree range update point query
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=arr[tl];
    }else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=0;
    }
}

void update(int v,int tl,int tr,int l,int r,int add){
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]+=add;
    }else{
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(r, tm),add);
        update(v*2+1,tm+1,tr,max(l, tm+1),r,add);
    }
}
ll get(int v,int tl,int tr,int pos){
    if(tl==tr)
        return t[v];
    int tm=(tl+tr)/2;
    if(pos<=tm)
        return t[v]+get(v*2,tl,tm,pos);
    else
        return t[v]+get(v*2+1,tm+1,tr,pos);
}
//range update range query min/max
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

struct Bit {
    vector<long long> bit;  
    int n;
    Bit(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, long long delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
//sparse table, k is 25
int st[MAXN][K + 1];
int log[MAXN+1];
for(int i=0;i<N;i++)
    st[i][0]=array[i];
for(int j=1;j<=K;j++)
    for(int i=0;i+(1<<j)<=N;i++)
        st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
log[1]=0;
for(int i=2;i<=MAXN;i++)
    log[i]=log[i/2]+1;
int j=log[R-L+1];
int minimum=min(st[L][j],st[R-(1<<j)+1][j]);


