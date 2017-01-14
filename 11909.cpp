#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-12

int main()
{
    double l, w, h, theta;
    while (cin >> l)
    {
        cin >> w >> h >> theta;
        cout.setf(ios::fixed);
        cout << setprecision(3);
        double pi = acos(-1);
        theta = pi * theta / 180;
        if (fabs(theta) < EPS) {
            double v = l * w * h;
            cout << v << " mL" << endl;
        }
        else if (theta < atan(h / l) || (fabs(theta - atan(h/l)) < EPS)){
            double d = l * sin(theta) / sin(pi / 2 - theta);
            double v = l * w * h - l * d * w / 2;
            cout << v << " mL" << endl;
        }
        else {
            double d = h / sin(theta) * sin((pi / 2 - theta));
            double v = h * d * w / 2;
            cout << v << " mL" << endl;
            }
    }
}
