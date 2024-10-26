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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                a[i][j] = 1;
            }
        }
    }

    vector<vi> f1(n, vi(m));
    f1[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) f1[i][j] |= f1[i - 1][j] & a[i][j];
            if (j > 0) f1[i][j] |= f1[i][j - 1] & a[i][j];
        }
    }

    if (!f1[n - 1][m - 1]) {
        cout << 0 << endl;
        return;
    }

    vector<vi> f2(n, vi(m));
    f2[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i < n - 1) f2[i][j] |= f2[i + 1][j] & a[i][j];
            if (j < m - 1) f2[i][j] |= f2[i][j + 1] & a[i][j];
        }
    }

    for (int p = 1; p <= n + m - 3; p++) {
        int cnt = 0;
        for (int i = max(0, p - m + 1); i <= min(n - 1, p); i++) {
            int j = p - i;
            cnt += f1[i][j] & f2[i][j];
        }
        if (cnt == 1) {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}