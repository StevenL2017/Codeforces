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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    string s, t;
    cin >> s >> t;

    int n = ssz(s), m = ssz(t);
    vector<vi> nxt(n + 1, vi(26, INT_MAX));
    repd(i, n - 1, -1) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    auto check = [&] (const string& a, const string& b) -> bool {
        int na = ssz(a), nb = ssz(b);
        vector<vi> f(na + 1, vi(nb + 1, INT_MAX));
        f[0][0] = 0;
        rep(i, na + 1) {
            rep(j, nb + 1) {
                if (f[i][j] > n) {
                    continue;
                }
                auto cur = f[i][j];
                if (i < na && nxt[cur][a[i] - 'a'] < INT_MAX) {
                    f[i + 1][j] = min(f[i + 1][j], nxt[cur][a[i] - 'a'] + 1);
                }
                if (j < nb && nxt[cur][b[j] - 'a'] < INT_MAX) {
                    f[i][j + 1] = min(f[i][j + 1], nxt[cur][b[j] - 'a'] + 1);
                }
            }
        }
        return f[na][nb] < INT_MAX;
    };

    rep(i, m) {
        if (check(t.substr(0, i), t.substr(i, m))) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}