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

typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define IS_EMB(i, j) (0 <= i && i < M - 1 && 0 <= j && j < N - 1 && \
                 F[i  ][j] == E[0][0] && F[i  ][j+1] == E[0][1] && \
                 F[i+1][j] == E[1][0] && F[i+1][j+1] == E[1][1])

#define CNT_EMB(i, j) IS_EMB(i-1, j-1) + IS_EMB(i-1, j) + IS_EMB(i, j-1) + IS_EMB(i, j)

signed main() {
    int IN(M);
    int IN(N);
    vector<string> F(M); times(M, i) cin >> F[i];
    vector<string> E(2); times(2, i) cin >> E[i];
    int def = 0, chg = 0;
    times(M, i) times(N, j) {
        def += IS_EMB(i, j);
        int b = CNT_EMB(i, j);
        char f = F[i][j];
        for(char c : "JOI") {
            F[i][j] = c;
            //if(chg < CNT_EMB(i, j) - b) cout << "F[" << i << "][" << j << "]: " << c ln;
            chg = max(chg, CNT_EMB(i, j) - b);
        }
        F[i][j] = f;
    }

    //cout << def << " " << chg << " ";

    cout << def + chg ln;

    return 0;
}
