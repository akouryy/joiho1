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
#define all(v) v.begin(), v.end()

signed main() {
    int IN(N);
    int IN(K);
    VVI c(10);
    times(N, _) {
        int IN(C);
        int IN(G); --G;
        c[G].push_back(C);
    }

    VVI dp(2, VI(K+1));
    times(10, g) {
        sort(all(c[g]), greater<int>());
        times(size(c[g]) - 1, i) c[g][i+1] += c[g][i];
        times(size(c[g]), i) {
            upto(i+1, K, j) {
                //if(g==1) cout<<"("<<i<<","<<j<<"): "<<dp[1][j]<<"<-"<<dp[0][j-i-1]<<"+"<<c[g][i]+i*(i+1)<<"\n";
                MAX_A(dp[1][j], dp[0][j-i-1] + c[g][i] + i * (i+1));
            }
        }
        dp[0] = dp[1];
        //times(K+1, i) cout << dp[0][i] << " "; cout ln;
    }

    cout << *max_element(all(dp[0])) ln;

    return 0;
}
