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
    int IN(M);

    VVI left(N+1, VI(N+2, 0)), right(N+1, VI(N+2, 0));

    times(M, i) {
        int IN(A); A--;
        int IN(B); B--;
        int IN(X);
        left[A][B]++;
        left[A+X+1][B]--;
        right[A][B+1]++;
        right[A+X+1][B+X+2]--;
    }

    //times(N+1, i) { times(N+2, j) cout << "(" << left[i][j] << " " << -right[i][j] << ")\t"; cout ln; } cout ln;

    times(N+1, i) times(N+1, j) {
        left[i][j+1]  += left[i][j];
        right[i][j+1] += right[i][j];
    }
    
    //times(N+1, i) { times(N+2, j) cout << "(" << left[i][j] << " " << -right[i][j] << ")\t"; cout ln; } cout ln;
    
    times(N, i) times(N+1, j) {
        left[i+1][j]    += left[i][j];
        right[i+1][j+1] += right[i][j];
    }

    //times(N+1, i) { times(N+2, j) cout << "(" << left[i][j] << " " << -right[i][j] << ")\t"; cout ln; } cout ln;
    
    int ans = 0;
   
    times(N+1, i) times(N+2, j) ans += left[i][j] - right[i][j] > 0;

    cout << ans ln;

    return 0;
}

