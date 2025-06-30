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

const int N = 100 + 3;
int f[N][N][N];
array<int, 3> pre[N][N][N];

vector<int> get_fail(string s) {
    int n = s.size();
    vector<int> fail(n, -1);
    for (int i = 1; i < n; i++) {
        auto j = fail[i - 1];
        while (j != -1 && s[j + 1] != s[i]) {
            j = fail[j];
        }
        if (s[j + 1] == s[i]) {
            fail[i] = j + 1;
        }
    }
    return fail;
}

void solve() {
    string s, t, v;
    cin >> s >> t >> v;

    int n = ssz(s), m = ssz(t), c = ssz(v);
    auto fail = get_fail(v);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < c && k <= i && k <= j; k++) {
                if (i < n) {
                    if (f[i + 1][j][k] < f[i][j][k]) {
                        f[i + 1][j][k] = f[i][j][k];
                        pre[i + 1][j][k] = {i, j, k};
                    }
                }
                if (j < m) {
                    if (f[i][j + 1][k] < f[i][j][k]) {
                        f[i][j + 1][k] = f[i][j][k];
                        pre[i][j + 1][k] = {i, j, k};
                    }
                }
                if (i < n && j < m && s[i] == t[j]) {
                    int nk = k - 1;
                    while (nk != -1 && v[nk + 1] != s[i]) {
                        nk = fail[nk];
                    }
                    if (v[nk + 1] == s[i]) {
                        nk++;
                    }
                    if (f[i + 1][j + 1][nk + 1] < f[i][j][k] + 1) {
                        f[i + 1][j + 1][nk + 1] = f[i][j][k] + 1;
                        pre[i + 1][j + 1][nk + 1] = {i, j, k};
                    }
                }
            }
        }
    }

    int mx = 0, mx_k = -1;
    for (int k = 0; k < c; k++) {
        if (mx < f[n][m][k]) {
            mx = f[n][m][k];
            mx_k = k;
        }
    }

    if (mx_k == -1) {
        cout << 0 << endl;
        return;
    }

    string ans;
    for (int i = n, j = m, k = mx_k; f[i][j][k]; ) {
        auto p = pre[i][j][k];
        if (p[0] == i - 1 && p[1] == j - 1) {
            ans += s[i - 1];
        }
        i = p[0], j = p[1], k = p[2];
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}