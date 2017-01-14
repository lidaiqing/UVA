#include <bits/stdc++.h>

using namespace std;

int N, t;
bool isPrime[305];
vector<int> primes;
bool comp (int l, int r)
{
    stringstream ssl, ssr;
    ssl << l;
    ssr << r;
    return ssl.str() < ssr.str();
}
void sieve()
{
    for (int i = 0; i  < 305; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < 305; i++)
    {
        if (isPrime[i]) {
            for (int j = i * 2; j < 305; j = j + i)
                isPrime[j] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i < 300; i++)
        if (isPrime[i]) {
            primes.push_back(i);
            primes.push_back(i);
        }
    sort(primes.begin(), primes.end(), comp);
   // for (int i = 0; i < primes.size(); i++)
       // cout << primes[i] << endl;
}
bool dp[150][1005][14];
int path[17];
bool find(int idx, int sum, int cur)
{
    //cout << idx << " " << sum << " " << cur << endl;
    
    if (idx == primes.size()) return false;
    if (sum > N) return false;
    if (cur == t) {
        if (sum == N) return true;
        else return false;
    }
    if (dp[idx][sum][cur] == 0) return false;
    int num = primes[idx];
        path[cur] = num;
        if (find(idx + 1, sum + num, cur + 1))
            return true;
        if (find(idx + 1, sum, cur))
            return true;
    return dp[idx][sum][cur] = 0;
}

int main()
{
    int case_num = 0;
    sieve();
    ios_base::sync_with_stdio(false);
    while (1)
    {
        case_num++;
        cin >> N >> t;
        if (N == 0 && t == 0) break;
        memset(dp,1,sizeof(dp));
        cout << "CASE " << case_num << ":" << endl;
        if (find(0, 0, 0)) {
            cout << path[0];
            for (int i = 1; i < t; i++)
                cout << "+" << path[i];
            cout << endl;
        }
        else cout << "No Solution." << endl;
    }
}

    
