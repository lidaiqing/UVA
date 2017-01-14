#include <bits/stdc++.h>

using namespace std;

#define MAX 18
#define ESP 1e-12
#define INF 10000000
int N;
double dp[1<<MAX];
struct node {
    string name;
    int x, y;
};
double dist(int x1, int y1, int x2, int y2)
{
    return hypot(x1-x2, y1-y2);
}
int main()
{
    int case_num = 0;
    while (1)
    {
        cin >> N;
        if (N == 0) break;
        case_num++;
        for (int i = 0; i < (1 << MAX); i++)
            dp[i] = INF;
        node p[2*N];
        for (int i = 0; i < 2*N; i++)
        {
            cin >> p[i].name >> p[i].x >> p[i].y;
        }
        dp[0] = 0;
        for (int i = 0; i < 2*N; i++)
        {
            if (!(i & (1 << i))) {
                for (int j = i+1; j < 2*N; j++)
                {
                    if (!(j & (1 << j))) {
                        int t = (1 << i) | (1 << j);
                        dp[t] = min(dp[t],dist(p[i].x, p[i].y, p[j].x, p[j].y));
                    }
                }
            }
        }

                
        for (int i = 0; i < (1 << 2*N); i++)
        {
            for (int j = 0; j < 2*N; j++)
            {
                if (!(i & (1 << j))) {
                    for (int k = j+1; k < 2*N; k++)
                    {
                        if (!(i & (1 << k))) {
                            int t = i | (1 << j) | (1 << k);
                            dp[t] = min(dp[t],dp[i] + dist(p[j].x, p[j].y, p[k].x, p[k].y));
                        }
                    }
                }
            }
        }
        cout.setf(ios::fixed);
        cout << "Case " << case_num << ": " << setprecision(2) << dp[(1<<2*N)-1] << endl;
    }
}
                        

