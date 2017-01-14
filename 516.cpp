#include <bits/stdc++.h>

using namespace std;

const int MAX = 40000;
bool is_prime[MAX];
vector<int> primes;
void sieve()
{
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i < sqrt(MAX); i++)
    {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
            primes.push_back(i);
        }
    }
}

vector<pair<int,int> > primeFactors(int N)
{
    vector<pair<int,int> > factors;
    int PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0) {
            int cnt = 0;
            while (N % PF == 0)
            {
                N /= PF;
                cnt++;
            }
            factors.push_back(make_pair(PF,cnt));
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(make_pair(N,1));
    return factors;
}

int main()
{
    string s;
    while (getline(cin,s)) {
        istringstream ss (s);
        int a,b;
        ss>>a;
        if (a == 0) break;
        ss>>b;
        int num = (int)pow(a,b);
        while (ss>>a>>b) {
            num *= (int) pow(a,b);
        }
        sieve();
        vector<pair<int,int> > ans = primeFactors(num-1);
        for (int i = ans.size()-1; i >= 1; i--)
            cout<<ans[i].first<<" "<<ans[i].second<<" ";
        cout<<ans[0].first<<" "<<ans[0].second<<endl;
    }

}

        
