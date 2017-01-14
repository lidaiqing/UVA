#include <bits/stdc++.h>

using namespace std;
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
};
point rotate(point p, point o, double theta)
{
    double x = cos(theta) * (p.x-o.x) - sin(theta) * (p.y-o.y) + o.x;
    double y = sin(theta) * (p.x-o.x) + cos(theta) * (p.y-o.y) + o.y;
    return point(x,y);
}
bool can(point p, double L, double C, double r)
{
    if (p.x + r > L || p.y + r > C) return false;
    return true;
}
    
int main()
{
    double L, C, R1, R2;
    while (1)
    {
        cin >> L >> C >> R1 >> R2;
        if (L == 0 && C == 0 && R1 == 0 && R2 == 0) break;
        if (L < C) swap(L,C);
        if (R1 < R2) swap(R1,R2);
        double d1 = sqrt((R1+R2)*(R1+R2) - (R1-R2)*(R1-R2));
        double d2 = sqrt(2) * (R1+R2) / 2;
        point p2(R1+d2,R1+d2);
        point p1(R1,R1);
        double pi = acos(-1);
        bool ok = false;
        for (double theta = -pi / 4; theta <= 0; theta += (0.1*pi/180))
        {
            p2 = rotate(p2, p1, theta);
            if (can(p2,L,C,R2) && p2.x >= 0 && p2.y >= 0) {
                cout << "S" << endl;
                cout << p2.x << " " << p2.y << endl;
                ok = true;
                break;
            }
        }
        if (!ok) cout << "N" << endl;
        

    }
}
