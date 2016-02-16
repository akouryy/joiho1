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

signed main() {
    int IN(N);
    int IN(M);

    vector<int> DI(N, 0);
    times(M, _) {
        int IN(D);
        int IN(P);
        DI[P - 1] = D;
    }
    vector<int> DR(N - M);
    times(N - M, i) {
        cin >> DR[i];
    }

    int l = 0, r = 1000000001LL;
    while(r - l > 1) {
        int m = (l + r) / 2;
        vector<int> high(N * 3 / 2);
        times(N, i) {
            if(DI[i] >= m) high[i] = 0;
            else if(DI[i]) high[i] = INT_MAX;
            else           high[i] = 1;
        }
        int i = 0, j = N;
        while(j - i > 1) {
            high[j] = high[i] + high[i + 1] + high[i + 2] - max({high[i], high[i + 1], high[i + 2]});
            i+=3;
            j++;
        }
        /*
        cout << m << "\t: ";
        times(N * 3 / 2, k) cout << high[k] << " ";
        cout ln;
        */
        int h = 0;
        for(int d : DR) h += d >= m;
        if(high[i] <= h) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l ln;

    return 0;
}
