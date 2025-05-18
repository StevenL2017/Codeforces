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

// r[i] -> centered at i in t with max length + 1
// if query for [left, right] in original s -> r[left + right + 1]
vector<int> manacher(string s) {
    string t = "#";
    for (auto c: s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i]++;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    auto rad = manacher(s);

    vi f1(n), f2(n);
    for (int i = n - 1; i >= 0; i--) {
        f1[i] = i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i + 1;
        f2[i] = i + 2 < n && s[i] == s[i + 2] ? f2[i + 2] : i + 2;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int len = r - l + 1;
        ll ans = rad[l + r + 1] <= len ? len : 0;
        if (f1[l] <= r) {
            int mx = len - 1 - (len - 1) % 2;
            ans += 1ll * (2 + mx) * (mx / 2) / 2;
        }
        if (f2[l] <= r || f2[l + 1] <= r) {
            int mx = len - 1 - len % 2;
            ans += 1ll * (3 + mx) * (mx - 1) / 2 / 2;
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}