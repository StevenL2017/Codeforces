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
    int n, m; cin >> n >> m;
    vi a(n), b(n), c(m);
    in(a); in(b); in(c);

    vector<vi> p(n + 1);
    for (int i = 0; i < m; i++) {
        p[c[i]].push_back(i);
    }

    vi ans(m, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (p[b[i]].empty()) {
                cout << "NO\n";
                return;
            }
            int idx = p[b[i]].back();
            p[b[i]].pop_back();
            ans[idx] = i + 1;
        }
    }

    if (ans[m - 1] == 0) {
        for (int i = 0; i < n; i++) {
            if (b[i] == c[m - 1]) {
                ans[m - 1] = i + 1;
                break;
            }
        }
        if (ans[m - 1] == 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) {
            ans[i] = ans[m - 1];
        }
    }

    cout << "YES\n";
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}