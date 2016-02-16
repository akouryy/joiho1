#include <bits/stdc++.h>
using namespace std;

#define times(n, i) uptil(0, n, i)
#define upto(f, t, i)    for(int i = f, i##_end = (t); i <= i##_end; i++)
#define uptil(f, t, i)   for(int i = f, i##_end = (t); i <  i##_end; i++)
#define downto(f, t, i)  for(int i = f, i##_end = (t); i >= i##_end; i--)
#define downtil(f, t, i) for(int i = f, i##_end = (t); i >  i##_end; i--)

#define int long long
#define IN(a) a; cin >> a;
#define ln <<"\n"

typedef vector<int> VI;

signed main() {
    int IN(N);
    vector<int> A(N); times(N, i) cin >> A[i];

    vector<VI> joi(N, VI(N, INT_MIN)), ioi(N, VI(N, INT_MIN));
    times(N, i) {
        joi[1][i] = A[i];
        ioi[1][i] = 0;
    }

    uptil(2, N, d) times(N, i) {
        int next = (i + 1) % N,
             end = (i + d - 1) % N;
        joi[d][i] = max(ioi[d-1][i] + A[end], ioi[d-1][next] + A[i]);
        ioi[d][i] = A[end] > A[i] ? joi[d-1][i] : joi[d-1][next];
    }

    //uptil(1, N, d) { times(N, i) cout << joi[d][i] << "," << ioi[d][i] << "\t"; cout ln; }
    //times(N, i) cout << A[(i+N-1) % N] + ioi[N-1][i] << "\t"; cout ln;

    int ans = -1;
    times(N, i) ans = max(ans, A[i] + ioi[N-1][(i + 1) % N]);
    cout << ans ln;

    return 0;
}
