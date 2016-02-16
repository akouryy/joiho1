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
typedef tuple<int, int, int> TI;
typedef vector<PI> VPI;

const int MOD = 100000;

signed main() {
    int IN(N);
    int IN(M);
    vector<int> S(N-1); times(N-1, i) cin >> S[i];

    vector<int> imos(N, 0);
    int k = 0;
    times(M, i) {
        int IN(A);
        if(A > 0) {
            imos[k]++;
            k += A;
            imos[k]--;
        } else {
            imos[k]--;
            k += A;
            imos[k]++;
        }
    }
    
    int ans = 0;
    times(N-1, i) imos[i+1] += imos[i] % MOD;
    //times(N-1, i) cout << imos[i] << "*" << S[i] ln;
    times(N-1, i) ans += imos[i] * S[i] % MOD;
    
    cout << ans % MOD ln;

    return 0;
}
