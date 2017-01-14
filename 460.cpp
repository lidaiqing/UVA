#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x11,y11,x12,y12,x21,y21,x22,y22;
    int c;
    cin >> c;
    
    while (c--)
    {
        cin >> x11 >> y11 >> x12 >> y12;
        //if (x11 == 0 && y11 == 0 && x12 == 0 && y12 == 0) break;
        cin >> x21 >> y21 >> x22 >> y22;
            int xl, yl, xu, yu;
            xl = max(x11, x21);
            yl = max(y11, y21);
            xu = min(x12, x22);
            yu = min(y12, y22);
            if (xl < xu && yl < yu) 
                cout << xl << " " << yl << " " << xu << " " << yu << endl;
            else cout << "No Overlap" << endl;
        if (c != 0) cout << endl;
    }
}
