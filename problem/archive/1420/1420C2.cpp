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
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    ll ans = 0;
    set<int> peak, valley;

    auto update = [&] (int i) {
        if ((i == 0 || a[i] > a[i - 1]) && (i == n - 1 || a[i] > a[i + 1])) {
            ans += a[i];
            peak.insert(i);
        }
        if (i > 0 && i + 1 < n && a[i] < a[i - 1] && a[i] < a[i + 1]) {
            ans -= a[i];
            valley.insert(i);
        }
    };

    auto remove = [&] (int i) {
        if (peak.count(i)) {
            ans -= a[i];
            peak.erase(peak.find(i));
        }
        if (valley.count(i)) {
            ans += a[i];
            valley.erase(valley.find(i));
        }
    };

    rep(i, n) update(i);

    cout << ans << endl;

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        set<int> cand;
        if (l > 0) cand.insert(l - 1);
        cand.insert(l);
        if (l < n - 1) cand.insert(l + 1);
        if (r > 0) cand.insert(r - 1);
        cand.insert(r);
        if (r < n - 1) cand.insert(r + 1);

        for (auto& i: cand) remove(i);
        swap(a[l], a[r]);
        for (auto& i: cand) update(i);
        
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