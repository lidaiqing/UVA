#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double D, L;
        cin >> D >> L;
        double a, b;
        a = sqrt(L * L / 4 - D * D / 4);
        b = D / 2 + (L - D) / 2;
        double area = a * b * acos(0) * 2;
        cout.setf(ios::fixed);
        cout << setprecision(3);
        cout << area <<endl;
    }
}
