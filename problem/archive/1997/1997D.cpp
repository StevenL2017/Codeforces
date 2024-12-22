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
    int n;
    cin >> n;
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        e[p - 1].push_back(i + 1);
    }

    function<bool(int, ll)> dfs = [&] (int u, ll x) -> bool {
        if (ssz(e[u]) == 0) {
            return x <= a[u];
        }
        if (x > 1e15) {
            return false;
        }
        if (u > 0) {
            x += max(0ll, x - a[u]);
        }
        for (auto v: e[u]) {
            if (!dfs(v, x)) {
                return false;
            }
        }
        return true;
    };

    ll left = a[0], right = 1e15;
    ll ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (dfs(0, mid - a[0])) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}