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
    int IN(N);

    VVVI dp(2, VVI(2, VI(N*2+2, INT_MAX))); dp[0][0][N+1] = 0;

    times(N-1, _) {
        int IN(T);
        times(N*2+1, i) {
            dp[1][0][i+1] = min(dp[0][0][i  ], dp[0][1][i  ] + T);
            dp[1][1][i  ] = min(dp[0][1][i+1], dp[0][0][i+1] + T);
        }
        //times(2, d) { times(N*2+2, i) cout << (dp[1][d][i] == INT_MAX ? -1 : dp[1][d][i]) << " "; cout ln;} cout ln;
        dp[0] = dp[1];
        times(2, d) fill(all(dp[1][d]), (int)INT_MAX);
    }

    cout << min(dp[0][0][N], dp[0][1][N]) ln;

    return 0;
}
