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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--; b--;
    vector<pair<ll, ll>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }

    auto dist = [&] (int i, int j) {
        return abs(c[i].first - c[j].first) + abs(c[i].second - c[j].second);
    };

    ll da = 2e18, db = 2e18;
    ll ab = (a < k && b < k) ? 0 : dist(a, b);
    for (int i = 0; i < k; i++) {
        da = min(da, dist(a, i));
        db = min(db, dist(b, i));
    }

    cout << min(ab, da + db) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}