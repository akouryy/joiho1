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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;

#define MAX_A(a, b) a = max(a, b)
#define size(v) ((signed)v.size())

signed main() {
    string IN(S);

    VC sc = {'B'};
    VI sl = {0};
    for(char c : S) {
        if(c == sc.back()) {
            sl.back()++;
        } else {
            sc.push_back(c);
            sl.push_back(1);
        }
    }

    int ans = 0;
    times(size(sc) - 2, i) {
        if(sc[i] == 'J' && sc[i+1] == 'O' && sc[i+2] == 'I' && sl[i] >= sl[i+1] && sl[i+1] <= sl[i+2])
            MAX_A(ans, sl[i+1]);
    }

    cout << ans ln;

    return 0;
}
