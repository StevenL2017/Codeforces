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

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    in(a);

    auto calc = [&] () -> vector<vi> {
        vector<vi> f(n, vi(2, INF));
        for (int i = 0; i < n; i++) {
            if (i == 0 || f[i - 1][0] == INF && f[i - 1][1] == INF) {
                if (a[0][i] == '*') {
                    f[i][0] = (int)(a[1][i] == '*');
                    f[i][1] = 1;
                }
                if (a[1][i] == '*') {
                    f[i][0] = 1;
                    f[i][1] = (int)(a[0][i] == '*');
                }
            } else {
                if (f[i - 1][0] < INF) {
                    f[i][0] = min(f[i][0], f[i - 1][0] + 1 + (int)(a[1][i] == '*'));
                    f[i][1] = min(f[i][1], f[i - 1][0] + 2);
                }
                if (f[i - 1][1] < INF) {
                    f[i][0] = min(f[i][0], f[i - 1][1] + 2);
                    f[i][1] = min(f[i][1], f[i - 1][1] + 1 + (int)(a[0][i] == '*'));
                }
            }
        }
        return f;
    };

    auto pre = calc();
    for (int j = 0; j < 2; j++) {
        reverse(begin(a[j]), end(a[j]));
    }
    auto suf = calc();

    int ans = min(suf[n - 1][0], suf[n - 1][1]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            auto x = pre[i][j] < INF ? pre[i][j] : 0;
            if (i < n - 1) {
                bool ok = true;
                for (int k = 0; k < 2; k++) {
                    if (suf[n - 2 - i][k] < INF) {
                        ans = min(ans, x + suf[n - 2 - i][k] + 1 + (int)(j != k));
                        ok = false;
                    }
                }
                if (ok) {
                    ans = min(ans, x);
                }
            } else {
                ans = min(ans, x);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}