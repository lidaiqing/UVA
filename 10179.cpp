#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
vector<long long> primes;
bitset<10000010> bs;

void sieve(long long upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
    {
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

long long EulerPhi(long long N) {
    long long PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (PF * PF <= N) {
        if (N % PF == 0) ans -= ans / PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}

int main()
{
    sieve(100000);
    while (1)
    {
        long long N;
        cin>>N;
        if (N == 0) break;
        long long ans = EulerPhi(N);
        cout<<ans<<endl;
    }
}
