#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-12

int main()
{
    double a;
    while (cin >> a) {
    double b, c;
    cin >> b >> c;
    double s = (a + b + c) / 2;
    double A = sqrt(s*(s-a)*(s-b)*(s-c));
    double r = A / s;
    double R = a * b * c / (4 * A);
    double pi = acos(-1);
    double area3 = pi * r * r;
    double area2 = A - pi * r * r;
    double area1 = pi * R * R - A;
    cout.setf(ios::fixed);
    cout << setprecision(4);
    cout << area1 << " " << area2 << " " << area3 << endl;
    }
}

