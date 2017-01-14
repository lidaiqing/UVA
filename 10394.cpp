#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
bitset<20000010> bs;
vector<int> primes;
bool is_prime[1000005];
void sieve(long long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
    {
        if (bs[i]) {
                for (long long j = i * i; j <= _sieve_size; j += i)
                     bs[j] = 0;
        primes.push_back((int)i);
        }
    }
}

bool isPrime(long long N)
{
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}
vector<pair<int,int> > twin;
int main()
{
    sieve(20000000);
    for (int i = 2; i < 20000000 - 2; i++)
        if (bs[i] && bs[i+2]) {
            twin.push_back(make_pair(i,i+2));
        }
    int S;
    while (cin>>S) {
        cout<<"("<<twin[S-1].first<<", "<<twin[S-1].second<<")"<<endl;
    }
}
    

