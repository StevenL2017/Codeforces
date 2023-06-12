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
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].first);
    }

    if (mx >= x) {
        cout << 1 << endl;
        return;
    }

    sort(a.begin(), a.end(), [&] (const pair<int, int> x, const pair<int, int> y) { return x.second - x.first < y.second - y.first; });
    
    if (a[0].second - a[0].first >= 0) {
        cout << -1 << endl;
        return;
    }

    int ans = x;
    for (int i = 0; i < n; i++) {
        int d = a[i].first - a[i].second;
        if (d > 0) {
            ans = min(ans, min((x + d - 1) / d, (x - mx + d - 1) / d + 1));
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