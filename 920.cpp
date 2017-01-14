#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
struct point_i {
    int x, y;
    point_i() {x = y = 0;}
    point_i (int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point_i other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
    } 
};

double dist (point_i p1, point_i p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int N;
        cin >> N;
        vector<point_i> points;
        for (int i = 0; i < N; i++)
        {
            point_i temp;
            cin >> temp.x >> temp.y;
            points.push_back(temp);
        }
        sort(points.begin(), points.end());
        double ans = 0;
        ans += dist(points[N-1], points[N-2]);
        int last = N - 2;
        for (int i = N - 3; i >= 0; i--)
        {
            if (points[i].y > points[last].y)
            {
                //cout << points[i].x << points[i].y << " asdsa" << endl;
                double temp = dist(points[i], points[i+1]);
                ans += temp * (1.0 - (double)(points[last].y-points[i+1].y) / (points[i].y-points[i+1].y));
                last = i;
            }
        }
        
        cout.setf(ios::fixed);
        cout << setprecision(2);
        cout << ans <<endl;
    }
}
