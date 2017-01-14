#include <bits/stdc++.h>

using namespace std;

int main()
{
    double ncow,ncar,nshow;
    while (cin >> ncow)
    {
        cin>>ncar>>nshow;
        double p1, p2;
        p1 = (ncow/(ncow+ncar))*(ncar/(ncow+ncar-nshow-1));
        p2 = (ncar/(ncow+ncar))*((ncar-1)/(ncow+ncar-nshow-1));
        printf("%.5f\n",p1+p2);
    }
}
