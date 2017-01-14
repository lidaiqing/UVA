#include <bits/stdc++.h>

using namespace std;
long long _sieve_size;
vector<long long> primes;
bitset<10000010> bs;
vector<long long> range_primes;
void sieve(long long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}
void range_sieve(long long L, long long U)
{
    int SIZE = U - L + 1;
    bool isPrime[SIZE];
    memset(isPrime,false,sizeof(isPrime));
    if (L == 1) isPrime[0] = false;
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] > U) continue;
        int start = (int)ceil((double)L / primes[i]);
        if (start == 1) start++;
        for (long long j = start; j * primes[i] <= U; j++)
            isPrime[j*primes[i] - L] = false;
    }
    range_primes.clear();
    for (int i = 0; i < SIZE; i++)
        if (isPrime[i]) range_primes.push_back(L + i);
}

long long num_divisor(long long N)
{
    long long PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= N) {
        long long power = 0;
        while (N % PF == 0) { N /= PF; power++;}
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2;
    return ans;
}

int main()
{
    int T;
    cin>>T;
    sieve(1000000);
    while (T--)
    {
        long long L, U;
        cin>>L>>U;
        long long P, mx = -1;
        for (long long i = L; i <= U; i++)
        {
            long long temp = num_divisor(i);
           // cout<<i<<" "<<temp<<endl;
            if (temp > mx) {
                mx = temp;
                P = i;
            }
        }
        cout<<"Between "<<L<<" and "<<U<<", "<<P<<" has a maximum of "<<mx<<" divisors."<<endl;
    }
}
        

