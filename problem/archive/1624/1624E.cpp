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
    vector<string> a(n);
    in(a);
    string s;
    cin >> s;

    map<string, tuple<int, int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            string ss = a[i].substr(j, 2);
            mp[ss] = {j + 1, j + 2, i + 1};
            if (j < m - 2) {
                string ss = a[i].substr(j, 3);
                mp[ss] = {j + 1, j + 3, i + 1};
            }
        }
    }

    vi f(m + 1), pre(m + 1, -1);
    f[0] = 1;
    for (int i = 2; i <= m; i++) {
        if (mp.count(s.substr(i - 2, 2))) {
            f[i] |= f[i - 2];
            if (f[i - 2]) pre[i] = i - 2;
        }
        if (i > 2 && mp.count(s.substr(i - 3, 3))) {
            f[i] |= f[i - 3];
            if (f[i - 3]) pre[i] = i - 3;
        }
    }

    if (!f[m]) {
        cout << -1 << endl;
        return;
    }

    vector<tuple<int, int, int>> ans;
    int cur = m;
    while (pre[cur] != -1) {
        int p = pre[cur];
        string ss = s.substr(p, cur - p);
        ans.push_back(mp[ss]);
        cur = p;
    }
    reverse(ans.begin(), ans.end());

    cout << ssz(ans) << endl;
    for (auto [l, r, i]: ans) {
        cout << l << " " << r << " " << i << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}