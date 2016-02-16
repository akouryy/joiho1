// vim: set ts=4 sw=4 et nu cin:
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
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVI> VVVI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;
typedef map<int, int> MI;

#define MAX_A(a, b) a = max(a, b)
#define MIN_A(a, b) a = min(a, b)
#define size(v) ((signed)v.size())
#define all(v) v.begin(), v.end()

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
while(true) {
    int IN(H);
    int IN(W);
    int IN(N);
    if(!H) break;

    VVI D(H+1, VI(W+1, 0));
    times(H, i) times(W, j) cin >> D[i+1][j+1];

    VVI dp(H+1, VI(W+1, 0));
    dp[1][1] = N - 1;
    times(H, i) times(W, j) {
        if(i || j) dp[i+1][j+1] = (dp[i][j+1] + !D[i][j+1]) / 2 + (dp[i+1][j] + D[i+1][j]) / 2;
    }

    //times(H, i) { times(W, j) cout << dp[i+1][j+1] << " "; cout ln; }

    int x = 1, y = 1;
    while(x <= W && y <= H) {
        if(dp[y][x] % 2 != D[y][x]) {
            x++;
        } else {
            y++;
        }
    }

    cout << y << " " << x ln;
}
    return 0;
}
