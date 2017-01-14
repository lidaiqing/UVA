#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-16

struct point {
    double x, y;
    point () {}
    point(double _x, double _y) : x(_x), y(_y) {}
};
point A, B, C, D;
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
bool check(point p, int a)
{
    if (fabs(dist(A,p) - a) > EPS) 
        if (dist(A, p) > a) return false;
    if (fabs(dist(B,p) - a) > EPS)
        if (dist(B, p) > a) return false;
    if (fabs(dist(C,p) - a) > EPS)
        if (dist(C, p) > a) return false;
    if (fabs(dist(D,p) - a) > EPS)
        if (dist(D, p) > a) return false;
    return true;
}


int main()
{
    while (1)
    {
        int N, a;
        cin >> N >> a;
        if (N == 0 && a == 0) break;
        A.x = 0, A.y = 0;
        B.x = a, B.y = 0;
        C.x = a, C.y = a;
        D.x = 0, D.y = a;
        int M = 0;
        for (int i = 0; i < N; i++)
        {
            double x, y;
            cin >> x >> y;
            point temp(x,y);
            if (check(temp, a)) M++;
        }
        double ans = (double) M * a * a / N;
        cout.setf(ios::fixed);
        cout << setprecision(5);
        cout << ans << endl;
    }
}


