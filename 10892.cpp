#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a,int b) { return (a * (b / gcd(a,b))); }

int main()
{
    int N;
    while (1) {
        cin>>N;
        if (N == 0) break;
        vector <int> div;
        for (int i = 1; i <= sqrt(N); i++)
        {
            if (N % i == 0) {
                int d = N / i;
                div.push_back(i);
                if (d != i) div.push_back(d);
            }
        }
        //cout<<div.size()<<endl;
        int cnt = 0;
        for (int i = 0; i < div.size(); i++)
            for (int j = i; j < div.size(); j++)
                if (lcm(div[i],div[j]) == N) cnt++;

        cout<<N<<" "<<cnt<<endl;
    }
}
