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

vector<int> z_func(string& s) {
    int n = s.size(), L = -1, R = -1;
    vector<int> z(n);
    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            z[i] = min(z[i - L], R - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

int check(string& s, string& t, string& rs, string& rt) {
    string c1 = t + '#' + s;
    auto z1 = z_func(c1);
    string c2 = rt + '#' + rs;
    auto z2 = z_func(c2);
    int ns = ssz(s), nt = ssz(t);
    vi pre(nt + 1, ns), suf(nt + 1, ns);
    for (int i = 0; i < ns; i++) {
        pre[z1[i + nt + 1]] = min(pre[z1[i + nt + 1]], i);
        suf[z2[i + nt + 1]] = min(suf[z2[i + nt + 1]], i);
    }
    for (int i = nt - 1; i >= 0; i--) {
        pre[i] = min(pre[i], pre[i + 1]);
        suf[i] = min(suf[i], suf[i + 1]);
    }
    for (int i = 0; i <= nt; i++) {
        if (pre[i] + nt <= ns - suf[nt - i]) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    vector<string> a(m); in(a);

    int ans = 0;
    string rs = s;
    reverse(rs.begin(), rs.end());
    for (auto t : a) {
        if (ssz(t) == 1) continue;
        string rt = t;
        reverse(rt.begin(), rt.end());
        ans += check(s, t, rs, rt);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}