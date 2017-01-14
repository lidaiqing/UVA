#include <bits/stdc++.h>

using namespace std;
long long n;
bool check(int num)
{
    long long rem = n;
    for (int i = 1; i <= num; i++)
    {
        rem -= 1;
        //if (rem == 0) return false;
        if (rem % num != 0) return false;
        else {
            rem -= rem / num;
        }
    }
    if (rem % num == 0) return true;
    else return false;
}
        

int main()
{
    while (1)
    {
        cin>>n;
        if (n < 0) break;
        int ans = -1;
        for (int i = 2; i <= sqrt(n)+1; i++)
        {
            if (check(i)) ans = max(ans,i);
        }
       if (ans != -1) cout<<n<<" coconuts, "<<ans<<" people and 1 monkey"<<endl;
       else cout<<n<<" coconuts, no solution"<<endl;
    }
}

