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
    int n, m; cin >> n >> m;
    vi a(n); in(a);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
    int pre = 0, cnt = 0;
    for (auto& i: idx) {
        if (pre + a[i] <= m) {
            pre += a[i];
            cnt++;
        }
    }

    if (cnt == n) {
        cout << 1 << endl;
        return;
    }

    rep(i, cnt) {
        if (idx[i] == cnt) {
            cout << n - cnt << endl;
            return;
        }
    }

    if (a[cnt] > m) {
        cout << n - cnt + 1 << endl;
        return;
    }

    m -= a[cnt];
    int pre1 = 0, cnt1 = 0;
    for (auto& i: idx) {
        if (i == cnt) continue;
        if (pre1 + a[i] <= m) {
            pre1 += a[i];
            cnt1++;
        }
    }

    if (cnt1 + 1 == cnt) cout << n - cnt << endl;
    cout << n - cnt + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}