// vim: set ts=4 sw=4 et nu cin:
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
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVI> VVVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;
typedef map<int, int> MI;

#define MAX_A(a, b) a = max(a, b)
#define MIN_A(a, b) a = min(a, b)
#define size(v) ((signed)v.size())
#define all(v) v.begin(), v.end()

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
while(true) {
    int IN(N);
    int IN(M);
    int IN(H);
    int IN(K);
    if(!N) break;
    
    VI S(N); times(N, i) cin >> S[i];
    VPI BA;
    times(M, i) {
        int IN(A); --A;
        int IN(B);
        BA.push_back({B, A});
    }
    sort(all(BA));

    VI x(N); times(N, i) x[i] = i;
    VPI i;
    for(auto& ba : BA) {
        int a = ba.second;
        swap(x[a], x[a+1]);
        i.push_back({x[a], x[a+1]});
    }

    VI y(N);
    times(N, i) y[x[i]] = i;

    int base = 0;
    times(K, i) base += S[y[i]];

    int ans = base;
    for(auto& p : i) {
        int s, t; tie(s, t) = p;
        int u = min(s, t), v = max(s, t);
        if(u < K && K <= v) {
            ans = min(ans, base - S[y[u]] + S[y[v]]);
            //cout << u << "," << v << "=" << base << "-" << S[y[u]] << "+" << S[y[v]] ln;
        }
    }

    cout << ans ln;
}
    return 0;
}
