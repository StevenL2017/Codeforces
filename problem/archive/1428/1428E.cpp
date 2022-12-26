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
    vector<ll> a(n); in(a);

    auto calc = [&] (ll l, ll p) -> ll {
        auto x = l / p;
        auto extra = l - x * p;
        return (p - extra) * x * x + extra * (x + 1) * (x + 1);
    };

    ll ans = 0;
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    rep(i, n) {
        ans += a[i] * a[i];
        pq.push({calc(a[i], 1) - calc(a[i], 2), {a[i], 2}});
    }
    rep(i, k - n) {
        ans -= pq.top().first;
        auto x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        pq.push({calc(x, y) - calc(x, y + 1), {x, y + 1}});
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}