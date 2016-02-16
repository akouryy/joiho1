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

typedef vector<int> VI;
typedef vector<VI> VVI;

#define MAX_A(a, b) a = max(a, b)

signed main() {
    int IN(N);
    string IN(S);

    int ic = 0;
    for(char c : S) ic += c == 'I';

    int before = 0, both = 0, after = ic, ans = 0;

    for(char c : S) {
        switch(c) {
        case 'J':
            before++;
            break;
        case 'O':
            if(!!before + !!after + both >= 2) {
                ans++;
                if(before) before--; else both--;
                if(after)  after--;  else both--;
            }
            break;
        case 'I':
            if(after) {
                if(both < ans) both++;
                else before++;
                after--;
            } else {
                both--; before++;
            }
            break;
        }
        cout << c << ": " << before << " " << both << " " << after ln;
    }

    cout << ans ln;

    return 0;
}
