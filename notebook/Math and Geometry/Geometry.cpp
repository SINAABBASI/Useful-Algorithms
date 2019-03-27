/*
	P = (a+b+c) / 2
	S = sqrt (P*(P-a)*(P-b)*(P-c))
	R = (a*b*c) / (4 * S)
	r = (S) / (P)
*/

struct Point {
	ldouble x, y;
	Point() {}
	Point(ldouble x, ldouble y) : x(x), y(y) {}
	Point(const Point &p) : x(p.x), y(p.y) {}
	Point operator + (const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (double c) const {
		return Point(x*c, y*c);
	}
	Point operator / (double c) const {
		return Point(x/c, y/c);
	}
	bool operator < (const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

ldouble dot(Point A, Point B) {
	return A.x*B.x + A.y*B.y;
}

ldouble dist2(Point A, Point B) {
	return dot(A - B, A - B);
}

ldouble dist(Point A, Point B) {
	return sqrt(dot(A-B, A-B));
}

ldouble cross(Point A, Point B) { // if plus(+) CW else CCW
	return A.x*B.y - A.y*B.x;
}

ldouble cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

ostream &operator << (ostream &os, const Point &p) {
	os << "(" << p.x << "," << p.y << ")";
}

Point rotateCCW90(Point A) {
	return Point(-A.y, A.x);
}

Point rotateCW90(Point A) {
	return Point(A.y, -A.x);
}

Point rotateCCW(Point A, ldouble teta) {
	return Point(A.x*cos(teta) - A.y*sin(teta), A.x*sin(teta) + A.y*cos(teta));
}

Point rotateCW(Point A, ldouble teta) {
	return Point(A.x*cos(teta) + A.y*sin(teta), -A.x*sin(teta) + A.y*cos(teta));
}

Point rotate(Point A, ldouble teta) {
	return rotateCCW(A, teta);
}

bool isCCW(Point A, Point B, Point C) {
	return (cross(B - A, C - A) > 0);
}

ldouble tra_area(Point A, Point B, Point C) {
	return abs(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y))/2;
}

ldouble tra_area(ldouble a, ldouble b, ldouble c) {
	ldouble p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

ldouble angle(Point A, Point O, Point B) {
	return acos(dot(A - O, B - O) / sqrt(dot(A - O, A - O) * dot(B - O, B - O)));
}

// find a point from 'a' through 'b' with distance d
Point pointAlongLine(Point A, Point B, ldouble d) {
	return A + ( ( (B - A) / sqrt(dot(B - A, B - A))) * d);
}

// project point c onto line throgh a and b
Point projectPointLine(Point A, Point B, Point C) {
	return A + (B - A) * dot(C - A, B - A) / dot (B - A, B - A);
}

// project point c onto Segment throgh a and b
Point projectPointSegment(Point A, Point B, Point C) {
	ldouble R = dot(B - A, B - A);
	if(fabs(R) < eps) return A;
	R = dot(C - A, B - A) / R;
	if(R < 0) return A;
	if(R > 1) return B;
	return A + (B - A) * R;
}

// compute distance from c to segment between a and b
ldouble distPointSegment(Point A, Point B, Point C) {
	return sqrt(dist2(C, projectPointSegment(A, B, C)));
}

// return minimum distance from point P to line AB
ldouble distPointLine(Point P, Point A, Point B, Point &C) {
	ldouble scale = (ldouble) (dot(P - A, B - A)) / (dot(B - A, B - A));
	C.x = A.x + scale * (B.x - A.x);
	C.y = A.y + scale * (B.y - A.y);
	// C = A + (B-A) * scale; // or
	return dist(P, C);
}

// return minimum distance from point P to line segment AB
ldouble _distPointSegment(Point P, Point A, Point B, Point &C) {
	if(dot(B - A, P - A) < eps) {
		C.x = A.x;
		C.y = A.y;
		return dist(P, A);
	}
	if(dot(A - B, P - B) < eps) {
		C.x = B.x;
		C.y = B.y;
		return dist(P, B);
	}
	return distPointLine(P, A, B, C);
}

// comput distance between point (x, y, z) ans plan ax+by+cz=d
ldouble distPointPlane(ldouble x, ldouble y, ldouble z, ldouble a, ldouble b, ldouble c, ldouble d) {
	return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

bool isPointOnSegment(Point P, Point A, Point B) {
	if(fabs(cross(P - B, A - B)) < eps) {
		if(P.x < min(A.x, B.x) || P.x > max(A.x, B.x)) return false;
		if(P.y < min(A.y, B.y) || P.y > max(A.y, B.y)) return false;
		return true;
	}
	return false;
}

// determine if lines from a to b and c to d are parallel or collinear
bool linesParallel(Point A, Point B, Point C, Point D) {
	return (fabs(cross(B - A, C - D)) < eps);
}

bool linesCollinear(Point A, Point B, Point C, Point D) {
	return ( linesParallel(A, B, C, D) && fabs(cross(A - B, A - C)) < eps && fabs(cross(C - D, C - A)) < eps );
}

bool linesIntersectUnique(Point A, Point B, Point C, Point D) {
	return !(linesCollinear(A, B, C, D) || linesParallel(A, B, C, D));
}

// determine if line segment from a to b intersect with line segment from c to d
bool segmentsIntersect(Point A, Point B, Point C, Point D) {
	if(linesCollinear(A, B, C, D)) {
		if(dist2(A, C) < eps || dist2(A, D) < eps || dist2(B, C) < eps || dist2(B, D) < eps) return true;
		if(dot(C - A, C - B) > 0 && dot(D - A, D - B) > 0 && dot(C - B, D - B) > 0) return false;
		return true;
	}
	if(cross(D - A, B - A) * cross(C - A, B - A) > 0) return false;
	if(cross(A - C, D - C) * cross(B - C, D - C) > 0) return false;
	return true;
}

bool linesSame(Point A, Point B, Point C, Point D) {
	if(fabs(cross(A - C, C - D)) < eps && fabs(cross(B - C, C - D)) < eps) return true;
	return false;
}

// compute intersection of line passing through a and b with line
// passing through c and d, assuming that unique intersection exists;
// for segment intersection, check segment intersection first
Point computeLinesIntersection(Point A, Point B, Point C, Point D) {
	B = B - A;
	D = C - D;
	C = C - A;
	return A + (B*(cross(C, D) / cross(B, D)));
}

Point computeCircleCenter(Point A, Point B, Point C) {
	B = (A + B)/2;
	C = (A + C)/2;
	return computeLinesIntersection(B, B + rotateCW90(A - B), C, C + rotateCW90(A - C));
}

bool inPolygon(Point pt, const vector<Point> &P) {
	if (P.size() < 3) return false; // check size < 3
	double sum = 0;
	for (int i = 0; i < P.size()-1; i++) {
		if (isCCW(pt, P[i], P[i+1])) sum += angle(P[i], pt, P[i+1]);
		else sum -= angle(P[i], pt, P[i+1]);
	}
	return fabs(fabs(sum) - 2*PI) < eps;
}

bool onPolygon(Point pt, const vector<Point> &P) { // size >= 3
	for(int i = 0, j = P.size()-1; i < P.size(); j = i++) {
		if(isPointOnSegment(pt, P[i], P[j])) return false;
	}
	return true;
}

bool isConvex(const vector<Point> &P) {
	int sz = (int) P.size();
	if (sz <= 2) return false; // maybe true!!!
	if(sz == 3) return (tra_area(P[0], P[1], P[2]) > eps);
	bool isLeft = isCCW(P[0], P[1], P[2]);
	for(int i = 0; i < sz; i++) if(isCCW(P[i], P[(i+1)%sz], P[(i+2)%sz]) != isLeft) return false;
	return true;
}

bool isSimple(const vector<Point> &P) {
	for(int i=0; i<P.size(); i++) {
		for(int k=i+1; k<P.size(); k++) {
			int j = (i+1)%P.size();
			int l = (k+1)%P.size();
			if(i == l || j == k) continue;
			if(segmentsIntersect(P[i], P[j], P[k], P[l])) return false;
		}
	}
	return true;
}

int PointCircle(Point A, Point C, ldouble R) {
	ldouble tmp = dist2(A, C) - R*R;
	if(fabs(tmp) < eps) return 0;
	else if(tmp < 0) return 1;
	else return -1;
}

vector <Point> circleLineIntersect(Point A, Point B, Point C, ldouble R) {
	vector <Point> ans;
	Point PT = projectPointLine(A, B, C);
	ldouble N = dist2(PT, C);
	N = R*R - N;
	int k = SIGN(N);
	if(k == 0) ans.push_back(PT);
	else if(k == 1) {
		ans.push_back( PT + (B - A) * (sqrt(N) / dist(A, B)) );
		ans.push_back( PT + (A - B) * (sqrt(N) / dist(A, B)) );
	}
	return ans;
}

vector <Point> _circleLineIntersect(Point A, Point B, Point C, ldouble R) {
	vector <Point> ans;
	B = B - A;
	A = A - C;
	ldouble a = dot(B, B);
	ldouble b = dot(A, B);
	ldouble c = dot(A, A) - R*R;
	ldouble d = b*b - a*c;
	if(d < -eps) return ans;
	ans.push_back(C + A + B * (-b+sqrt(d+eps))/a);
	if(d > eps) ans.push_back(C + A + B * (-b-sqrt(d))/a);
	return ans;
}

vector <Point> circleCircleIntersect(Point A, Point B, ldouble r, ldouble R) {
	vector <Point> ans;
	ldouble d = dist(A, B);
	if(d > r+R || d + min(R, r) < max(R, r)) return ans;
	ldouble x = (d*d-R*R+r*r) / (2*d);
	ldouble y = sqrt(r*r - x*x);
	Point PT = (B - A) / d;
	ans.push_back( A + PT * x + rotateCW90(PT) * y );
	if(y > 0) ans.push_back( A + PT * x - rotateCW90(PT) * y );
	return ans;
}

ldouble signedArea(const vector <Point> &P) {
	ldouble area = 0;
	for(int i=0; i<P.size(); i++) {
		int j = (i+1) % P.size();
		area += cross(P[i], P[j]);
	}
	return area / 2.0;
}

ldouble area(const vector <Point> &P) {
	return fabs(signedArea(P));
}

Point centroid(const vector <Point> &P) {
	Point C(0, 0);
	double scale = 6.0 * signedArea(P);
	for(int i=0; i<P.size(); i++) {
		int j = (i+1) % P.size();
		C = C + (P[i] + P[j]) * cross(P[i], P[j]);
	}
	return C / scale;
}

Point mass_center(const vector <Point> &P) {
	Point C = Point(0, 0);
	for(int i=0; i<P.size(); i++) C = C + P[i];
	return C/P.size();
}

vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k-1);
	return H;
}