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
    int n, v;
    cin >> n >> v;
    vector<pair<int, int>> a, b;
    for (int i = 1; i <= n; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            a.emplace_back(x, i);
        } else {
            b.emplace_back(x, i);
        }
    }

    sort(begin(a), end(a), greater<pair<int, int>>());
    sort(begin(b), end(b), greater<pair<int, int>>());

    int m1 = ssz(a), m2 = ssz(b);
    for (int i = 1; i < m1; i++) {
        a[i].first += a[i - 1].first;
    }
    for (int i = 1; i < m2; i++) {
        b[i].first += b[i - 1].first;
    }

    int ans = m1 ? a[min(m1, v) - 1].first : 0, j = 0;
    for (int i = 0; i < min(m2, v / 2); i++) {
        int cur = b[i].first;
        int ii = min(m1, v - (i + 1) * 2) - 1;
        if (ii >= 0 && ii < m1) cur += a[ii].first;
        if (cur > ans) {
            ans = cur;
            j = i + 1;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < min(m1, v - j * 2); i++) {
        cout << a[i].second << " ";
    }
    for (int i = 0; i < j; i++) {
        cout << b[i].second << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}