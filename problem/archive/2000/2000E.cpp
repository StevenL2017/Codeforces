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
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vi a(w);
    in(a);

    vector<ll> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx = max(0, min(k - 1, i) - max(0, i - (n - k)) + 1);
            int dy = max(0, min(k - 1, j) - max(0, j - (m - k)) + 1);
            s.push_back(dx * 1ll * dy);
        }
    }
    sort(begin(s), end(s), greater<ll>());
    sort(begin(a), end(a), greater<int>());

    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ans += s[i] * a[i];
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