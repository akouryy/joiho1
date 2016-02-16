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
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef pair<char, int> PCI;
typedef vector<PCI> VPCI;
typedef tuple<int, int, int> TI;
typedef vector<TI> VTI;

#define MAX_A(a, b) a = max(a, b)
#define size(v) ((signed)v.size())

signed main() {
    int IN(N);
    int IN(M);
    int IN(K);
    VTI all_road(M);
    VVPI road(N);
    times(M, i) {
        int IN(A); --A;
        int IN(B); --B;
        int IN(L);
        all_road[i] = TI(A, B, L);
        road[A].push_back({L, B});
        road[B].push_back({L, A});
    }
    
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    times(K, _) {
        int IN(S); --S;
        pq.push({0, S});
    }

    VI cost(N, -1);
    while(!pq.empty()) {
        int c, t; tie(c, t) = pq.top(); pq.pop();
        if(cost[t] == -1) {
            cost[t] = c;
            for(PI& p : road[t]) {
                int d, s; tie(d, s) = p;
                if(cost[s] == -1) {
                    pq.push({c + d, s});
                }
            }
        }
    }

    //times(N, i) cout << cost[i] << " "; cout ln;

    int ans = 0;

    times(M, i) {
        int a, b, l; tie(a, b, l) = all_road[i];
        MAX_A(ans, max({cost[a], cost[b], (cost[a] + cost[b] + l + 1) / 2}));
    }
    
    cout << ans ln;

    return 0;
}
