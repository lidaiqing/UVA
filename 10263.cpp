#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec (double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}
point translate (point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}
vec scale (vec v, double s) {
    return vec(v.x * s, v.y *s);
}
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
double distToLine (point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}
double distToLineSegment (point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}
int main()
{
    double mx, my;
    while (cin >> mx) {
        cin >> my;
        point M(mx, my);
        int N;
        cin >> N;
        double mi = 10000000;
        point ans(0.0,0.0);
        double ax, ay, bx, by;
        cin >> ax >> ay;
        for (int i = 0; i < N; i++)
        {
            double bx, by;
            cin >> bx >> by;
            point a(ax, ay);
            point b(bx, by);
            point temp(0.0, 0.0);
            double d = distToLineSegment(M, a, b, temp);
            if (d < mi) {
                mi = d;
                ans = temp;
            }
            ax = bx;
            ay = by;
        }
        cout.setf(ios::fixed);
        cout << setprecision(4);
        cout << ans.x << endl;
        cout << ans.y << endl;
    }
}
            
