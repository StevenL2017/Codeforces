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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    ll ans = 1e18, tot = 0;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        if (i >= k) tot -= c[i - k];
        ll cur = a[i][0] + 1;
        deque<pair<int, ll>> q;
        q.emplace_back(0, cur);
        for (int j = 1; j < m; j++) {
            cur = q.front().second + a[i][j] + 1;
            while (!q.empty() && q.back().second >= cur) {
                q.pop_back();
            }
            q.emplace_back(j, cur);
            while (!q.empty() && j - q.front().first - 1 >= d) {
                q.pop_front();
            }
        }
        c[i] = cur;
        tot += c[i];
        if (i >= k - 1) ans = min(ans, tot);
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