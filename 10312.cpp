#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long sup_cat[30];
    long long cat[30];
    cat[0] = 1;
    sup_cat[0] = 1;
    sup_cat[1] = 1;
    sup_cat[2] = 1;
    for (int i = 1; i <= 26; i++)
    {
        cat[i] = 2*i*(2*i-1)*cat[i-1]/i/(i+1);
        if (i >= 3) sup_cat[i] = (3*(2*i-3)*sup_cat[i-1]-(i-3)*sup_cat[i-2])/i;
    }
    int temp;
    while (cin>>temp)
    {
        cout<<sup_cat[temp] - cat[temp-1]<<endl;
    }
}
