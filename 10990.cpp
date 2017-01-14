#include <bits/stdc++.h>

using namespace std;
const int MAX = 2000005;
int phi[MAX];
long long sum_phi[MAX];
long long dep_phi[MAX];
int isPrime[MAX];
int main()
{
    for (int i = 2; i < MAX; i++)
        phi[i] = i;
    
    memset(isPrime,1,sizeof(isPrime));
    for (long long i = 2; i < MAX; i++)
    {
        if (isPrime[i]) {
            for (long long j = i; j < MAX; j += i)
            {
                isPrime[j] = 0;
                phi[j] -= phi[j] / i;
            }
        }
    }
    sum_phi[2] = 1;
    dep_phi[2] = 1;
    for (int i = 3; i < MAX; i++)
        dep_phi[i] = 1 + dep_phi[phi[i]];
    for (int i = 3; i < MAX; i++)
        sum_phi[i] = dep_phi[i] + sum_phi[i-1];
    int T;
    cin>>T;
    while (T--)
    {
        int m,n;
        cin>>m>>n;
        cout<<sum_phi[n] - sum_phi[m] + dep_phi[m]<<endl;
    }
}
