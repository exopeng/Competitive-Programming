#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <utility>
#include <cstring>
#include <stack>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pii;
int len[50010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[50010];
vector<pii> adj2[50010];
int main()
{
    int N, M;
    freopen("colored.in","r",stdin);
    freopen("colored.out","w",stdout);
    cin >> N >> M;
    int a[M];
    int b[M];
    int c[M];
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }
    for(int i = 0; i < M; i++) {
        if(c[i] == 1) {
            adj[a[i]].push_back(pii(b[i], 0));
            adj[a[i]+N].push_back(pii(b[i]+N, 2));
            adj[b[i]].push_back(pii(a[i], 0));
            adj[b[i]+N].push_back(pii(a[i]+N, 2));
        } else {
            adj[a[i]].push_back(pii(b[i]+N, 1));
            adj[a[i]+N].push_back(pii(b[i], 1));
            adj[b[i]].push_back(pii(a[i]+N, 1));
            adj[b[i]+N].push_back(pii(a[i], 1));
        }
    }

    int v, s, curN, curD;
    v= N*2;
    s= 0;
    for(int i = 0; i < v; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, s));
    len[s] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(len[curN] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN] + adj[curN][i].second < len[adj[curN][i].first])
            {
                len[adj[curN][i].first] = len[curN] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
            }
    }
    /*for(int i = 0; i < v; i ++)
    {
        if(len[i] != 2000000000) cout << len[i] << "\n";
        else cout << -1 << "\n";
    }*/
    int ans = min((len[v-1]+1)/2, (len[v-N-1]+1)/2);


    for(int i = 0; i < M; i++) {
        if(c[i] == 1) {
            adj2[a[i]].push_back(pii(b[i], 2));
            adj2[a[i]+N].push_back(pii(b[i]+N, 0));
            adj2[b[i]].push_back(pii(a[i], 2));
            adj2[b[i]+N].push_back(pii(a[i]+N, 0));
        } else {
            adj2[a[i]].push_back(pii(b[i]+N, 1));
            adj2[a[i]+N].push_back(pii(b[i], 1));
            adj2[b[i]].push_back(pii(a[i]+N, 1));
            adj2[b[i]+N].push_back(pii(a[i], 1));
        }
    }
    for(int i = 0; i < v; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, s));
    len[s] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(len[curN] < curD) continue;
        for(int i = 0; i < adj2[curN].size(); i ++)
            if(len[curN] + adj2[curN][i].second < len[adj2[curN][i].first])
            {
                len[adj2[curN][i].first] = len[curN] + adj2[curN][i].second;
                nextInLine.push(pii(len[adj2[curN][i].first], adj2[curN][i].first));
            }
    }
    int ans2 = min((len[v-1]+1)/2, (len[v-N-1]+1)/2);


    cout << min(ans, ans2) << endl;
}