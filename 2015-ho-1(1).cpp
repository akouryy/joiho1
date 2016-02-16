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

signed main() {
    int IN(N);
    int IN(M);
    vector<int> P_imos(N, 0);
    int pb = -1;
    times(M, i) {
        int IN(P); P--;
        if(~pb) {
            P_imos[min(P, pb)]++;
            P_imos[max(P, pb)]--;
        }
        pb = P;
    }

    int sum = 0, ans = 0;
    times(N - 1, i) {
        int IN(A);
        int IN(B);
        int IN(C);
        sum += P_imos[i];
        ans += min(A * sum, B * sum + C);
    }
    cout << ans ln;

    return 0;
}
