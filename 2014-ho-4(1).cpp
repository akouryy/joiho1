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

signed main() {
    int IN(N);
    int IN(M);
    int IN(X);
    vector<int> H(N); times(N, i) cin >> H[i];
    vector<VPI> path(N);

    times(M, _) {
        int IN(A); A--;
        int IN(B); B--;
        int IN(T);
        if(H[A] >= T) path[A].push_back({T, B});
        if(H[B] >= T) path[B].push_back({T, A});
    }

    priority_queue<TI, vector<TI>, greater<TI>> pq; /* cost, tree, high */
    pq.push(TI(0, 0, X));
    vector<int> cost(N, -1), high(N);
    while(!pq.empty()) {
        int c, t, h; tie(c, t, h) = pq.top(); pq.pop();
        if(cost[t] == -1) {
            cost[t] = c;
            high[t] = h;
            //cout << "{" << c << ", " << t << ", " << h << "}" ln;
            for(PI& p : path[t]) {
                int cn = c + p.first, tn = p.second, hn = h - p.first;
                if(hn < 0) { cn += -hn; hn = 0; }
                else if(hn > H[tn]) { cn += hn - H[tn]; hn = H[tn]; }

                if(cost[tn] == -1) pq.push(TI(cn, tn, hn));
            }
        }
    }

    if(cost[N-1] == -1)
        cout << -1 ln;
    else
        cout << cost[N-1] + H[N-1] - high[N-1] ln;

    return 0;
}
