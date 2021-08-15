#include <bits/stdc++.h>
using namespace std; 

const double EPS = 1E-9;
double x;
struct pt
{ 
    long long x; 
    long long y; 
    int index;
};

struct seg  {
    pt p,q;
    int index;
};
bool operator< (pt p1, pt p2) { return p1.x==p2.x ? p1.y<p2.y : p1.x<p2.x; }
int sign(long long x) { if (x==0) return 0; else return x<0 ? -1 : +1; }
int operator* (pt p1, pt p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
pt operator- (pt p1, pt p2) { pt p = {p1.x-p2.x, p1.y-p2.y}; return p; }
bool isect(seg &s1, seg &s2)
{
  pt &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
  return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}
double eval(seg s) {
  if (s.p.x == s.q.x) return s.p.y;
  return s.p.y + (s.q.y-s.p.y) * (x-s.p.x) / (s.q.x-s.p.x);
}
bool operator< (seg s1, seg s2) { return s1.index != s2.index && eval(s1)<eval(s2); }
bool operator== (seg s1, seg s2) { return s1.index == s2.index; }

int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    x1 = 0;
    y1 = 0;
    x2 = 2;
    y2 = 0;
    x3 = 1;
    y3 = 1;
    x4 = 1;
    y4 = -1;
    Point p1 = {x1, y1}, q1 = {x2, y2}; 
    Point p2 = {x3, y3}, q2 = {x4, y4}; 
    if (isect(p1,q1,p2,q2)) {
        cout << "intersect";
    } else {
        cout << "no intersect";
    }
    return 0;
}