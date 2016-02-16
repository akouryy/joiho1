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
#define all(v) v.begin(), v.end()

signed main() {
    int IN(N);
    int IN(T);
    int IN(S);
    VI A(N), B(N); times(N, i) cin >> A[i] >> B[i];

    VVI dp(2, VI(T+1, 0));
    times(N, i) {
        upto(B[i], S, j) {
            MAX_A(dp[1][j], max(!!j * dp[1][j-1], dp[0][j - B[i]] + A[i]));
        }
        upto(S + 1, min(S + B[i] - 1, T), j) {
            MAX_A(dp[1][j], dp[1][j-1]);
        }
        upto(S + B[i], T, j) {
            MAX_A(dp[1][j], max(!!j * dp[1][j-1], dp[0][j - B[i]] + A[i]));
        }
        dp[0] = dp[1];
        times(T+1, j) dp[1][j] = dp[0][j];
        //cout << A[i] << "\t"; times(T+1, j) cout << (j == S ? "|" : "") << dp[0][j] << (j == S ? "| " : " "); cout ln;
    }

    cout << dp[0][T] ln;

    return 0;
}
