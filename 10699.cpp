#include <bits/stdc++.h>

using namespace std;
int const MAX = 1000005;
int numPF[MAX];
void sieve()
{
    for (long long i = 2; i < MAX; i++)
    {
        if (numPF[i] == 0) {
            for (long long j = i; j < MAX; j += i)
                numPF[j]++;
        }
    }
}
int main()
{
    memset(numPF,0,sizeof(numPF));
    sieve();
    while (1)
    {
        int n;
        cin>>n;
        if (n == 0) break;
        cout<<n<<" : "<<numPF[n]<<endl;
    }
}
