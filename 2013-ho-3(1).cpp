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
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;

signed main() {
    int IN(M);
    int IN(N);
    int IN(K);
    VPI P(K);
    VVPI xy(M), yx(N);
    xy[0].push_back({0, 0});
    times(K, i) {
        int IN(X); X--;
        int IN(Y); Y--;
        P[i] = {X, Y};
        xy[X].push_back({Y, i*2+1});
        yx[Y].push_back({X, i*2+2});
    }
    xy[M-1].push_back({N-1, K*2+1});
    yx[N-1].push_back({M-1, K*2+1});

    // times(M, i) { cout << "{"; for(PI& p : xy[i]) cout << p.first << " " << p.second << ","; cout << "} "; } cout ln;
    // times(N, j) { cout << "{"; for(PI& p : yx[j]) cout << p.first << " " << p.second << ","; cout << "} "; } cout ln;

    VVPI path(K * 2 + 2);
    times(K, i) {
        path[i*2+1].push_back({1, i*2+2});
        path[i*2+2].push_back({1, i*2+1});
    }
    // times(K * 2 + 2, i) { cout << "{"; for(PI& p : path[i]) cout << p.first << " " << p.second << ","; cout << "} "; } cout ln;
    for(VPI& y : xy) {
        sort(y.begin(), y.end());
        times((signed)y.size() - 1, i) {
            path[y[i  ].second].push_back({y[i+1].first - y[i].first, y[i+1].second});
            path[y[i+1].second].push_back({y[i+1].first - y[i].first, y[i  ].second});
        }
    }
    for(VPI& x : yx) {
        sort(x.begin(), x.end());
        times((signed)x.size() - 1, i) {
            path[x[i  ].second].push_back({x[i+1].first - x[i].first, x[i+1].second});
            path[x[i+1].second].push_back({x[i+1].first - x[i].first, x[i  ].second});
        }
    }

    // times(K * 2 + 2, i) { cout << "{"; for(PI& p : path[i]) cout << p.first << " " << p.second << ","; cout << "} "; } cout ln;

    VI cost(K * 2 + 2, LLONG_MAX);
    priority_queue<PI, VPI, greater<PI>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        int c, i; tie(c, i) = pq.top(); pq.pop();
        if(cost[i] > c) {
            // cout << i << "(" << !!i * P[(i-1)/2].first << "," << !!i * P[(i-1)/2].second << "): " << c ln;
            cost[i] = c;
            for(PI& p : path[i]) {
                int l, j; tie(l, j) = p;
                if(cost[j] > c + l) {
                    pq.push({c + l, j});
                }
            }
        }
    }

    cout << (cost[K * 2 + 1] != LLONG_MAX ? cost[K * 2 + 1] : -1) ln;

    return 0;
}

