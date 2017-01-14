#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b) for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n) forab (i, 0, (n) - 1)
#define For(i, n) forab (i, 1, n)
#define rofba(i, a, b) for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n) rofba (i, 0, (n) - 1)
#define rof(i, n) rofba (i, 1, n)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

ll dp[52][52];

void pre(){
	dp[0][0] = 1;
	for(int i = 1 ; i <= 50 ; i++) {
		dp[i][0] = 1;
		for(int j = 1 ; j <= i ; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
}

int toInt(string s){
    int r = 0;
    istringstream sin(s);
    sin>>r;
    return r;
}

string a , b , ret , tmp ;

int k ;

void split(){
    a.clear() , b.clear() , tmp.clear();
    int i ,len = ret.size() ;
    for( i = 1 ; ret[i] != '+' ; i++ ) a += ret[i];
    for( i++   ; ret[i] != ')' ; i++ ) b += ret[i];
    for( i += 2; i < len ; i++ ) tmp += ret[i];
    k = toInt(tmp);
}
int main(){
    pre();
    int test = II ;
    For(cs,test){
        cin >> ret ;
        split();
        printf("Case %d: ",cs);
       // cout << a << endl << b << endl;
        if( k > 1 ) cout << a << "^" << k ;
        else cout << a ;
        int z = 1 ;
        for(int i = 1 ; i < k ; i++ ){
                cout << "+" << dp[k][i] << "*" ;
                cout << a ;
                if(k - z > 1 ) cout << "^" << k-z ;
                cout << "*" << b ;
                if( z > 1 ) cout << "^" << z ;
                z++;

        }
        cout << "+";
        if( k > 1 ) cout << b << "^" << k ;
        else cout << b ;
        puts("");
    }
}
