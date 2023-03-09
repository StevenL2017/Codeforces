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
    int n, m; cin >> n >> m;
    vi x(m), y(m);
    rep(i, m) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    vector<ll> bit(n, 1), hash(n, 0);
    repa(i, 1, n) {
        bit[i] = bit[i - 1] * 987654321ll;
    }
    rep(i, m) {
        int u = x[i], v = y[i];
        hash[u] ^= bit[v];
        hash[v] ^= bit[u];
    }

    ll ans = 0;
    rep(i, m) {
        int u = x[i], v = y[i];
        if ((hash[u] ^ bit[v]) == (hash[v] ^ bit[u]))
            ans++;
    }
    
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int u, int v) { return hash[u] < hash[v]; });
    for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n && (hash[idx[i]] == hash[idx[j]]); j++);
        ans += (j - i) * 1ll * (j - i - 1) / 2;
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