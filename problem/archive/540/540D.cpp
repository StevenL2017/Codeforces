#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

long double f[105][105][105];

void solve() {
    int r, s, p;
    cin >> r >> s >> p;

    f[r][s][p] = 1;
    for (int x = r; x >= 0; x--) {
        for (int y = s; y >= 0; y--) {
            for (int z = p; z >= 0; z--) {
                if (!x && !y || !x && !z || !y && !z) continue;
                int c_rs = x * y, c_rp = x * z, c_sp = y * z;
                int tot = c_rs + c_rp + c_sp;
                if (x) f[x - 1][y][z] += f[x][y][z] * c_rp / tot;
                if (y) f[x][y - 1][z] += f[x][y][z] * c_rs / tot;
                if (z) f[x][y][z - 1] += f[x][y][z] * c_sp / tot;
            }
        }
    }

    vector<long double> ans(3);
    for (int i = 1; i <= r; i++) ans[0] += f[i][0][0];
    for (int j = 1; j <= s; j++) ans[1] += f[0][j][0];
    for (int k = 1; k <= p; k++) ans[2] += f[0][0][k];

    cout.precision(10);
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}