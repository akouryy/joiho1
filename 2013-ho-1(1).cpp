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

signed main() {
    int IN(N);
    vector<int> D(N); times(N, i) cin >> D[i];
    vector<int> light = {0, 0};
    int b = -1, l = 0;

    for(int x : D) {
        if(b == x) {
            light.push_back(l);
            l = 1;
        } else {
            b = x;
            l++;
        }
    }
    light.push_back(l);
    
    int ans = 0;

    times(light.size() - 2, i) {
        ans = max(ans, light[i] + light[i+1] + light[i+2]);
    }

    cout << ans ln;

    return 0;
}
