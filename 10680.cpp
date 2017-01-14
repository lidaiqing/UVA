#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long lcm(long long a, long long b) {return a * (b / gcd(a,b));}

long long _sieve_size;
bitset<10000100> bs;
vector<long long> primes;
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
    swap(primes[1] ,primes[2]);
}
int main()
{
    sieve(1000000);
    while (1)
    {
        int N;
        cin>>N;
        if (N == 0) break;
        long long cnt2 = 0, cnt5 = 0;
        for (int i = 2; i <= N; i *= 2) cnt2++;
        for (int i = 5; i <= N; i *= 5) cnt5++;
        int res = 1;
        for (int i = 0; i < cnt2 - cnt5; i++) res = (res * 2) % 10;
        for (int i = 2; i < primes.size(); i++) {
            if (primes[i] > N) break;
            for (long long j = primes[i]; j <= N; j *= primes[i])
                res = (res * primes[i]) % 10;
        }
        cout<<res<<endl;
    }
}


