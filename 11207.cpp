#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        int N;
        cin >> N;
        if (N == 0) break;
        double mx = -1, mxi;
        for (int i = 0; i < N; i++)
        {
            double w, h;
            cin >> w >> h;
            if (w < h) swap(w,h);
            double temp = -1;
            if (w / 4 <= h) {
                temp = max(temp,w / 4);
            }
            if (h * 4 <= w) {
                temp = max(temp, h);
            }
            temp = max(temp, h / 2);
            if (temp > mx) {
                mx = temp;
                mxi = i + 1;
            }
        }
        cout << mxi << endl;
    }
}


