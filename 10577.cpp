#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-20
#define INF 1000000000
struct point {
    double x, y;
    point() {x = 0, y = 0;}
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist (point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}

struct line {
    double a, b, c;
};
vec toVec (point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) {return v.x * v.x + v.y * v.y;}
double angle(point a, point o, point b) {
    vec oa = toVec(o,a), ob = toVec(o,b);
    return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x-p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}
vec scale (vec v, double s) {
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point & p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
    else p.y = -(l2.a*p.x+l2.c);
return true;
}
vector<point> points;
bool test(point o)
{
    point a = points[0];
    point b = points[1];
    point c = points[2];
    if (fabs(dist(a,o) - dist(b,o)) > EPS) return false;
    if (fabs(dist(a,o) - dist(c,o)) > EPS) return false;
    if (fabs(dist(b,o) - dist(c,o)) > EPS) return false;
    return true;
}
point rotate(point x1, point o, double theta)
{
    double pi = 2 * acos(0);
    double rad = pi*theta/180;
    double x2 = cos(rad)*(x1.x-o.x)-sin(rad)*(o.y-x1.y)+o.x;
    double y2 = -sin(rad)*(x1.x-o.x)+cos(rad)*(o.y-x1.y)+o.y;
    return point(x2,y2);
}

void find(point &o, double R)
{
    
    point a = points[0];
    point b = points[1];
    point c = points[2];
    /*double AM = dist(a,b) / 2;
    double OM = sqrt(R * R - AM * AM);
    point M = translate(a, scale(toVec(a,b),0.5));
    point aa = rotate(a, M, 90);
    double ratio = OM / dist(M,aa);
    o = translate(M, scale(toVec(M,aa), ratio));
    if (test(o)) return;
    else
        o = translate(M, scale(toVec(aa,M), ratio));*/
    //find circumcenter formula 
    double A,B,C,D,E,F,G;
    A = b.x - a.x;
    B = b.y - a.y;
    C = c.x - a.x;
    D = c.y - a.y;
    E = A * (a.x + b.x) + B * (a.y + b.y);
    F = C * (a.x + c.x) + D * (a.y + c.y);
    G = 2.0 * (A * (c.y - b.y) - B * (c.x - b.x));
    o.x = (D * E - B * F) / G;
    o.y = (A * F - C * E) / G;
}

    

    
int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        int n;
        cin >> n;
        if (n == 0) break;
        points.clear();
        for (int i = 0; i < 3; i++)
        {
            double x, y;
            cin >> x >> y;
            points.push_back(point(x,y));
        }
        double pi = 2 * acos(0);
        double theta = 2*pi/n;
        double a = dist(points[0],points[1]);
        double b = dist(points[1],points[2]);
        double c = dist(points[2],points[0]);
        double s = (a + b + c) / 2;
        double A = sqrt(s*(s-a)*(s-b)*(s-c));
        double R = a * b * c / (4 * A);
        point o;
        find(o,R);
       // cout << o.x << " " << o.y << endl;
        //cout << theta << endl;
        point next, prev;
        prev = points[0];
        double xmin = INF, xmax = -INF, ymin = INF, ymax = -INF; 
        for (int i = 0; i <= n; i++)
        {
            double vx, vy, tx, ty;
            vx = prev.x - o.x, vy = prev.y - o.y;
            next.x = o.x + vx*cos(theta) - vy*sin(theta);
            next.y = o.y + vx*sin(theta) + vy*cos(theta);
            xmin = min(xmin,next.x);
            xmax = max(xmax,next.x);
            ymin = min(ymin,next.y);
            ymax = max(ymax,next.y);
            prev = next;
        }
        double area = (ymax-ymin) * (xmax-xmin);
        cout << "Polygon " << cnt << ": ";
        cout.setf(ios::fixed);
        cout << setprecision(3);
        cout << area << endl;
    }
}
        




