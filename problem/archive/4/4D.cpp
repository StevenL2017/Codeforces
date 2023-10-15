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
    int n, w, h;
    cin >> n >> w >> h;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i].first * 1ll * a[i].second < a[j].first * 1ll * a[j].second; });

    vi f(n, 0), pre(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[idx[i]].first <= w || a[idx[i]].second <= h) continue;
        f[idx[i]] = 1;
        for (int j = 0; j < i; j++) {
            if (a[idx[j]].first <= w || a[idx[j]].second <= h) continue;
            if (a[idx[j]].first >= a[idx[i]].first || a[idx[j]].second >= a[idx[i]].second) continue;
            if (f[idx[j]] + 1 > f[idx[i]]) {
                f[idx[i]] = f[idx[j]] + 1;
                pre[idx[i]] = idx[j];
            }
        }
    }

    int ansi = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] > mx) {
            mx = f[i];
            ansi = i;
        }
    }

    vi ans;
    while (ansi != -1) {
        ans.push_back(ansi + 1);
        ansi = pre[ansi];
    }
    reverse(ans.begin(), ans.end());

    cout << mx << endl;
    if (mx) out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}