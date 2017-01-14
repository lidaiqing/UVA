#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
bitset<400001000> bs;
vector<long long> primes;

void sieve(long long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
}
bool isPrime(long long N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}
long long primeFactors(long long N)
{
    vector<long long> factors;
    long long PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0) factors.push_back(PF);
        while (N % PF == 0) {N /= PF;}
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    if (factors.size() >= 2) return factors[factors.size()-1];
    else return -1;
    
}
int main()
{
    sieve(10000000);
   // memset(memo,-1,sizeof(memo));
    while (1) {
        long long N;
        cin>>N;
        if (N < 0) N *= -1;
        if (N == 0) break;
        else {
            if ( (N < _sieve_size && bs[N]) || (isPrime(N))) cout<<"-1"<<endl;
            else cout<<primeFactors(N)<<endl;
        }
    }
}
