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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> seg(n);
    rep(i, n) {
        cin >> seg[i].first;
    }
    rep(i, n) {
        cin >> seg[i].second;
    }

    int tot = 0;
    rep(i, n) {
        tot += seg[i].second - seg[i].first + 1;
    }
    if (tot < k) {
        cout << -1 << endl;
        return;
    }

    int ans = INT_MAX;
    multiset<int> s;
    tot = 0;
    for (int i = 0; i < n; i++) {
        auto cur = seg[i].second - seg[i].first + 1;
        s.insert(cur);
        tot += cur;
        while (tot >= k) {
            auto diff = tot - k;
            auto last = seg[i].second - diff;
            ans = min(ans, last + ssz(s) * 2);
            if (!s.empty()) {
                auto mn = *s.begin();
                s.erase(s.find(mn));
                tot -= mn;
            }
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