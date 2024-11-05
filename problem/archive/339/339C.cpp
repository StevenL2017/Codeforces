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

void solve() {
    string s;
    int m;
    cin >> s >> m;

    vector<vector<vi>> f(m + 1, vector<vi>(11, vi(10, -1)));
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int x = 0; x < 10; x++) {
                if (f[i][j][x] == -1) continue;
                for (int y = 0; y < 10; y++) {
                    if (s[y] == '0' || x == y || y + 1 <= j) continue;
                    f[i + 1][y + 1 - j][y] = x;
                }
            }
        }
    }

    for (int j = 0; j <= 10; j++) {
        for (int x = 0; x < 10; x++) {
            if (f[m][j][x] == -1) continue;
            vi ans(m);
            for (int i = m; i > 0; i--) {
                ans[i - 1] = x + 1;
                int y = f[i][j][x];
                j = x + 1 - j;
                x = y;
            }
            cout << "YES" << endl;
            out(ans);
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}