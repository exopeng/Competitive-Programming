#include <bits/stdc++.h>
#define pdd pair<double, double> 
using namespace std;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D) 
{ 
    // Line AB represented as a1x + b1y = c1 
    double a1 = B.second - A.second; 
    double b1 = A.first - B.first; 
    double c1 = a1*(A.first) + b1*(A.second); 
  
    // Line CD represented as a2x + b2y = c2 
    double a2 = D.second - C.second; 
    double b2 = C.first - D.first; 
    double c2 = a2*(C.first)+ b2*(C.second); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
    { 
        // The lines are parallel. This is simplified 
        // by returning a pair of FLT_MAX 
        return make_pair(FLT_MAX, FLT_MAX); 
    } 
    else
    { 
        double x = (b2*c1 - b1*c2)/determinant; 
        double y = (a1*c2 - a2*c1)/determinant; 
        return make_pair(x, y); 
    } 
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("xray.in","r",stdin);
    int t;
    cin >> t;
    clock_t tStart = clock();
    while (t--) {
    	long long ans = 0;
    	vector< pair<double,double> > p;
    	unordered_set< pair<double,double>, pair_hash > fin;
    	int x;
    	cin >> x;
    	for (int i = 0; i < x; i++) {
    		int f,s;
    		cin >> f >> s;
    		p.push_back(make_pair(f,s));
    		fin.insert(make_pair(f,s));
    	}
    	sort(p.begin(), p.end());
    	//slope of 1 && slope of -1
    	vector < pair<int,int> > pos;
    	vector < pair<int,int> > neg;
    	int maxp = 0;
    	int maxn = 0;
    	//take the ones with the max slopes and max neg slopes
    	for (int i = 0; i < x; i++) {
    		int counterp = 1;
    		int countern = 1;
    		int currx = p[i].first;
    		int curry = p[i].second;
    		for (int j = i + 1; j < x; j++) {
    			if ((double)(curry - p[j].second) / (double)(currx - p[j].first) == 1) {
    				counterp++;
    			} else if ((double)(curry - p[j].second) / (double)(currx - p[j].first) == -1) {
    				countern++;
    			}
    		}
    		if (counterp > maxp) {
    			pos.clear();
    			maxp = counterp;
    			pos.push_back(make_pair(currx,curry));
    		} else if (counterp == maxp) {
    			pos.push_back(make_pair(currx,curry));
    		}
    		if (countern > maxn) {
    			neg.clear();
    			maxn = countern;
    			neg.push_back(make_pair(currx,curry));
    		} else if (countern == maxn) {
    			neg.push_back(make_pair(currx,curry));
    		}
    	}
    	//cout << maxp << " " << maxn << "\n";
    	//asume they share one point
    	ans = maxp + maxn - 1;
    	bool found = false;
    	//compare the top ones
    	for (int i = 0; i < pos.size(); i++) {
    		for (int j = 0; j < neg.size(); j++) {
    			pdd A = make_pair(pos[i].first, pos[i].second); 
			    pdd B = make_pair(pos[i].first + 1, pos[i].second + 1); 
			    pdd C = make_pair(neg[j].first, neg[j].second); 
			    pdd D = make_pair(neg[j].first + 1, neg[j].second - 1); 
			    pdd intersection = lineLineIntersection(A, B, C, D); 
			    //cout << intersection.first << " " << intersection.second << "\n";
			    pair <double, double> point = make_pair(intersection.first, intersection.second);
			    if (fin.find(point) == fin.end()) {
			    	//no sharing of points
			    	//cout << "here" << "\n";
			    	ans++;
			    	found = true;
			    	break;
			    } 
			}
			if (found) {
				break;
			}
    	}
    	cout << ans << "\n";
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

