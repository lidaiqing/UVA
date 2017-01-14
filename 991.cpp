#include <bits/stdc++.h>

using namespace std;


int main()
{
    int cat[15];
    cat[0] = 1;
    for (int i = 1; i <= 10; i++)
        cat[i] = 2*i*(2*i-1) * cat[i-1] / (i+1) / i;
    int temp;
    bool first = true;
    while (cin>>temp) {
        if (first) {
            first = false;
        }
        else cout<<endl;
        cout<<cat[temp]<<endl;
    }
}
