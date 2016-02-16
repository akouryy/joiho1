// vim: set ts=4 sw=4 et:
#include <bits/stdc++.h>
using namespace std;

#define times(n, i)  uptil(0, n, i)
#define rtimes(n, i) downto((n)-1, 0, i)
#define upto(f, t, i)    for(int i = f, i##_end = (t); i <= i##_end; i++)
#define uptil(f, t, i)   for(int i = f, i##_end = (t); i <  i##_end; i++)
#define downto(f, t, i)  for(int i = f, i##_end = (t); i >= i##_end; i--)
#define downtil(f, t, i) for(int i = f, i##_end = (t); i >  i##_end; i--)

#define int long long
#define IN(a) a; cin >> a;
#define ln << endl

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;

#define MAX_A(a, b) a = max(a, b)
#define MIN_A(a, b) a = min(a, b)
#define size(v) ((signed)v.size())
#define all(v) v.begin(), v.end()

signed main() {
while(true) {
    int IN(N);
    int IN(M);
    if(!N) break;

    VVI x(N), d(N);
    times(N, i) {
        int IN(K);
        x[i].resize(K);
        d[i].resize(K);
        times(K, k) {
            int IN(X); --X;
            int IN(D);
            x[i][k] = X;
            d[i][k] = D;
        }
    }

    VVVI dp(3, VVI(M+1, VI(10, LLONG_MAX/3)));
    times(10, k) {
        dp[1][0][k] = 0;
        if(M) dp[0][1][k] = 0;
    }

    times(N-1, i) {
        times(M+1, j) {
            times(size(x[i]), k) times(size(x[i+1]), l) {
                MIN_A(dp[0][j][l], dp[1][j  ][k] + abs(x[i  ][k] - x[i+1][l]) * (d[i  ][k] + d[i+1][l]));
            }
            if(i && j) times(size(x[i-1]), k) times(size(x[i+1]), l) {
                MIN_A(dp[0][j][l], dp[2][j-1][k] + abs(x[i-1][k] - x[i+1][l]) * (d[i-1][k] + d[i+1][l]));
            }
        }
        //times(M+1, j) { cout << "{"; times(size(x[i+1]), k) cout << (k ? " " : "") << dp[0][j][k]; cout << "} "; } cout ln;
        dp[2] = dp[1];
        dp[1] = dp[0];
        times(M+1, j) fill(all(dp[0][j]), LLONG_MAX/3);
    }

    int ans = LLONG_MAX;
    times(M+1, j) times(10, k) MIN_A(ans, dp[1][j][k]);
    times(M  , j) times(10, k) MIN_A(ans, dp[2][j][k]);

    cout << ans ln;
}
    return 0;
}
