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
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;

#define MAX_A(a, b) a = max(a, b)
#define size(v) ((signed)v.size())

signed main() {
    int IN(A);
    int IN(B);
    VI C(A); times(A, i) cin >> C[i];
    VI D(B); times(B, i) cin >> D[i];

    VVI dp(A, VI(2, 0));
    int ans = 0;
    times(B, b) {
        int m = 0;
        times(A, a) {
            MAX_A(ans, dp[a][b&1] = (C[a] == D[b]) * (m + 1));
            if(b) m = max(m, dp[a][~b&1]);
        }
        //cout << D[b] << ": "; times(A, a) cout << dp[a][b&1] << " "; cout ln;
    }

    cout << ans ln;

    return 0;
}
