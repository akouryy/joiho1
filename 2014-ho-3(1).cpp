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

typedef pair<int, int> PI;
typedef vector<PI> VPI;

signed main() {
    int IN(N);
    vector<int> A(N); times(N, i) cin >> A[i];

    /* [0, i) */
    vector<int> ai(2 * N + 1, 0);
    times(2 * N, i) ai[i+1] = ai[i] + A[i % N];
    // times(2*N+1, i) cout << ai[i] << " "; cout ln;

    int l = 0, r = ai[N] - 1;
    while(l + 1 < r) {
        int m = (l + r) / 2;
        // cout << "[" << m << "]" ln;
        bool ok = false;
        int j = 1, k = 1;
        times(N, i) {
            // cout << "(" << i << ")" ln;
            if(i == j) j++;
            for(; (ai[j + N] - ai[i]) % ai[N] < m; j++, j %= N) if(j == i) goto pyon; else if(j == k) k++, k %= N;
            for(; (ai[k + N] - ai[j]) % ai[N] < m; k++, k %= N) if(k == i) goto pyon;
            ok = ok || (ai[i + N] - ai[k]) % ai[N] >= m;
            /*
            cout << i << " " << j << " " << k << " / "
                 << (ai[j + N] - ai[i]) % ai[N] << " "
                 << (ai[k + N] - ai[j]) % ai[N] << " "
                 << (ai[i + N] - ai[k]) % ai[N] << " "
                 ln;
            */
        }
        if(ok) {
            l = m;
        } else {
            pyon: r = m;
        }
    }

    cout << l ln;

    return 0;
}
