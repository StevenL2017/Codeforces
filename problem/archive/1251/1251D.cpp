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
    int n; cin >> n;
    ll s; cin >> s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    auto check = [&] (int x) -> bool {
        ll tot = 0;
        int cnt = 0;
        vi middle;
        for (auto [l, r] : a) {
            if (r < x) {
                tot += l;
            } else if (l < x && x <= r) {
                middle.push_back(l);
            } else {
                tot += l;
                cnt++;
            }
        }
        int need = max(0, (n + 1) / 2 - cnt);
        if (need > ssz(middle)) return false;
        sort(middle.begin(), middle.end());
        for (auto l : middle) {
            if (need < ssz(middle)) {
                tot += l;
                need++;
            } else {
                tot += x;
            }
        }
        return tot <= s;
    };

    int left = 1, right = 1e9, ans = left;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
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