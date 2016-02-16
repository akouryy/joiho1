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
    int IN(C);

    vector<VPI> road(N);
    int dsum = 0;

    times(M, _) {
        int IN(A); A--;
        int IN(B); B--;
        int IN(D);
        road[A].push_back({B, D});
        road[B].push_back({A, D});
        dsum += D;
    }

    vector<int> dist(N, -1);
    priority_queue<PI> pq;
    pq.push({0, 0});

    int ans = LLONG_MAX;

    while(!pq.empty()) {
        int c, s; tie(c, s) = pq.top(); pq.pop(); c = -c;
        if(!~dist[s]) {
            dist[s] = c;
            for(PI& p : road[s]) {
                int cc, ss; tie(ss, cc) = p;
                if(~dist[ss]) {
                    //cout << "dsum -= " << cc ln;
                    dsum -= cc;
                } else {
                    //cout << "pq " << c+cc << "," << ss ln;
                    pq.push({-(c + cc), ss});
                }
            }
            //cout << c << " " << s << " " << C << "*" << c << "+" << dsum ln;
            ans = min(ans, C * c + dsum);
        }
    }

    cout << ans ln;

    return 0;
}
