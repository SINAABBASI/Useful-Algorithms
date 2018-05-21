#include <bits/stdc++.h>
#define MAX 1000111
#define inf 1000000002
using namespace std;


//Problem : We are 2 set point and and check point in setB is in the convex of setA


struct Point
{
	long double x,y;
	Point() {}
	Point(long double x, long double y) : x(x), y(y) {}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
};

bool cmp(Point a,Point b){
	if(a.x == b.x )return a.y < b.y;
	return a.x < b.x;
}

long double ccw(Point o,Point a,Point b){
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

long double dot(Point A, Point B) {
	return A.x*B.x + A.y*B.y;
}

long double angle(Point O,Point A,  Point B) {
	return acos(dot(A - O, B - O) / sqrt(dot(A - O, A - O) * dot(B - O, B - O)));
}

vector <Point> convexHull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end(),cmp);
	for (int i = 0; i < n; i++) {
		while (k >= 2 && ccw(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && ccw(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k-1);
	return H;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int q,ans = 0,n;
	Point a;
	cin>>n;
	vector<Point> p;
	for(int i = 0; i < n ; i++){
		cin>>a.x>>a.y;
		p.push_back(a);
	}
	p = convexHull(p);
	cin>>q;
	while(q--){
		int l = 1,h = p.size() - 1;
		Point cur;
		cin>>cur.x>>cur.y;
		
		//// for point is in chosen angle
		if(angle(p[0],p[h],p[1]) < angle(p[0],cur,p[1]) || 
			ccw(p[0],cur,p[1])*ccw(p[0],p[h],p[1]) < 0 )continue;
		

		///O(log n) for point is convex or not
		while( h - l > 1){
			int mid = (l + h) >> 1;
			if( angle(p[0],p[mid],p[1]) > angle(p[0],cur,p[1])){
				h = mid;
			}
			else l = mid;
		}
		if(ccw(cur,p[l],p[h]) >= 0)ans++;
	}
	cout<<ans;
	return 0;
}	