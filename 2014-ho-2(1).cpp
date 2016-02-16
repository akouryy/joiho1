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
#define ln <<"\n"

typedef pair<int, int> PI;
typedef vector<PI> VPI;

signed main() {
    int IN(M);
    int IN(N);
    vector<int> P(M);       times(M, i) cin >> P[i];
    vector<int> C(N), E(N); times(N, i) cin >> C[i] >> E[i];

    sort(P.begin(), P.end(), greater<int>());

    vector<int> dp(20001, INT_MAX);
    dp[0] = 0;

    times(N, i) {
	rtimes(20000, j) {
	    dp[j] = min({dp[j], dp[j + 1], j >= C[i] ? dp[j - C[i]] + E[i] : INT_MAX});
	}
    }

    //times(M + 1, i) cout << i << ":\t" << P[i] << "\t" << dp[i] ln;

    int ans = 0, psum = 0;
    times(M + 1, i) {
	ans = max(ans, psum - dp[i]);
	if(i != M) psum += P[i];
    }

    cout << ans ln;

    return 0;
}
