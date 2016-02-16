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
    int IN(L);
    int last_a = 0, now = 0, ans = 0;
    bool up = true;

    times(N, i) {
        int IN(A);
        if(up == (last_a < A)) {
            now += L - A;
        } else {
            up = !up;
            now = 2 * L - last_a - A;
        }
        last_a = A;
        ans = max(ans, now);
        //cout << ans << " " << now << " " << up ln;
    }
    
    cout << ans ln;

    return 0;
}
