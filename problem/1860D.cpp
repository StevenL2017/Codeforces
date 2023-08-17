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

const int N = 105;
const int M = 1250;

int f[N][N][M];

void solve() {
    string s; cin >> s;

    int n = ssz(s);
    vi pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (int)(s[i] == '1');
    }

    int one = pre[n], zero = n - one;
    int tot = 0;
    if (one % 2 == 0) {
        tot = one / 2 * zero;
    } else {
        tot = zero / 2 * one;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= tot; k++) {
                f[i][j][k] = INT_MAX;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (i + 1 == j) {
                if (s[i] == '0' && s[j] == '1') {
                    f[i][j][1] = 0;
                    f[i][j][0] = 1;
                }
                else if (s[i] == '1' && s[j] == '0') {
                    f[i][j][1] = 1;
                    f[i][j][0] = 0;
                }
                else {
                    f[i][j][0] = 0;
                }
                continue;
            }
            for (int k = 0; k <= tot; k++) {
                if (f[i + 1][j][k] == INT_MAX) continue;
                if (s[i] == '0') {
                    auto one = pre[j + 1] - pre[i + 1];
                    for (int z = 0; z <= one; z++) {
                        f[i][j][k + one - z] = min(f[i][j][k + one - z], f[i + 1][j][k] + min(z, 1));
                    }
                } else {
                    auto zero = j - (i + 1) + 1 - (pre[j + 1] - pre[i + 1]);
                    for (int z = 0; z <= zero; z++) {
                        f[i][j][k + z] = min(f[i][j][k + z], f[i + 1][j][k] + min(z, 1));
                    }
                }
            }
            for (int k = 0; k <= tot; k++) {
                if (f[i][j - 1][k] == INT_MAX) continue;
                if (s[j] == '0') {
                    auto one = pre[j] - pre[i];
                    for (int z = 0; z <= one; z++) {
                        f[i][j][k + z] = min(f[i][j][k + z], f[i][j - 1][k] + min(z, 1));
                    }
                } else {
                    auto zero = j - 1 - i + 1 - (pre[j] - pre[i]);
                    for (int z = 0; z <= zero; z++) {
                        f[i][j][k + zero - z] = min(f[i][j][k + zero - z], f[i][j - 1][k] + min(z, 1));
                    }
                }
            }
        }
    }

    cout << f[0][n - 1][tot] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}