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
    int n, s;
    cin >> n >> s;
    vi a(n);
    in(a);

    map<int, pair<int, int>> mp;
    auto check = [&] (int x) -> bool {
        ll tot = s, mn = s;
        for (int i = 0; i < x; i++) {
            tot += a[i];
            mn = min(mn, tot);
        }
        if (mn >= 0) {
            mp[x] = {1, x};
            return true;
        }
        for (int i = x; i < n; i++) {
            tot -= a[i - x];
            mn -= a[i - x];
            tot += a[i];
            mn = min(mn, tot);
            if (mn >= 0) {
                mp[x] = {i - x + 2, i + 1};
                return true;
            }
        }
        return false;
    };

    int left = 0, right = n;
    int ans = 0;
    while (left <= right) {
        auto mid = (left + right) >> 1;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    if (ans) cout << mp[ans].first << " " << mp[ans].second << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}