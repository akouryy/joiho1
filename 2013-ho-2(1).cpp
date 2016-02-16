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

typedef vector<int> VI;
typedef vector<VI> VVI;

#define MAX_A(a, b) a = max(a, b)

signed main() {
    int IN(M);
    int IN(N);
    string IN(S);
    string IN(T);

    vector<VVI> dp(M+1, VVI(N+1, {INT_MIN, 0}));

    times(M+1, i) dp[i][0][1] = 0;
    times(N+1, j) dp[0][j][1] = 0;

    times(M+1, i) times(N+1, j) {
        bool so = S[i] == 'O', to = T[j] == 'O';
        if(i < M) MAX_A(dp[i+1][j][so], dp[i][j][!so] + 1);
        if(j < N) MAX_A(dp[i][j+1][to], dp[i][j][!to] + 1);
    }

    // times(M+1, i) { times(N+1, j) cout << dp[i][j][0] << "\t"; cout ln; } cout ln;
    // times(M+1, i) { times(N+1, j) cout << dp[i][j][1] << "\t"; cout ln; } cout ln;

    int ans = 0;
    times(M+1, i) times(N+1, j) MAX_A(ans, dp[i][j][0]);

    cout << ans ln;

    return 0;
}
