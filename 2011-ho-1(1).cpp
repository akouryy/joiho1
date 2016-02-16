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
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;

#define MAX_A(a, b) a = max(a, b)
#define size(v) ((signed)v.size())
#define all(v) v.begin(), v.end()

signed main() {
    int IN(M);
    int IN(N);
    int IN(K);
    const int J = 0, O = 1, I = 2;
    VI X(128, -1); X['J'] = J; X['O'] = O; X['I'] = I;

    VVVI JOI(3, VVI(M+1, VI(N+1, 0)));
    times(M, i) {
        string IN(S);
        times(N, j) {
            JOI[X[S[j]]][i+1][j+1] = 1;
        }
    }
    times(3, x) {
        times(M+1, i) times(N, j) JOI[x][i][j+1] += JOI[x][i][j];
        times(M, i) times(N+1, j) JOI[x][i+1][j] += JOI[x][i][j];
    }

    times(K, _) {
        int IN(A); int IN(B); int IN(C); int IN(D); A--; B--;
        vector<int> ans(3);
        times(3, x) ans[x] = JOI[x][C][D] - JOI[x][A][D] - JOI[x][C][B] + JOI[x][A][B];
        cout << ans[J] << " " << ans[O] << " " << ans[I] ln;
    }

    return 0;
}
