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
    int m, n;
    cin >> m >> n;
    vector<vi> b(m, vi(n));
    for (int i = 0; i < m; i++) {
        in(b[i]);
    }
    
    vi row(m, 1), col(n, 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] == 0) {
                row[i] = col[j] = 0;
            }
        }
    }

    vector<vi> a(m, vi(n, 1));
    for (int i = 0; i < m; i++) {
        if (row[i]) continue;
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int j = 0; j < n; j++) {
        if (col[j]) continue;
        for (int i = 0; i < m; i++) {
            a[i][j] = 0;
        }
    }

    vi r(m, 0), c(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                r[i] = c[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] && r[i] == 0 && c[j] == 0) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        out(a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}