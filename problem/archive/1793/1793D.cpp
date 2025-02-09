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
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a);
    in(b);

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int x = a[i] - 1;
        if (p[x].first == 0) {
            p[x].first = i + 1;
        } else {
            p[x].second = i + 1;
        }
        x = b[i] - 1;
        if (p[x].first == 0) {
            p[x].first = i + 1;
        } else {
            p[x].second = i + 1;
        }
    }

    auto [l, r] = p[0];
    ll ans = l * 1ll * (l - 1) / 2 + (r - l) * 1ll * (r - l - 1) / 2 + (n - r + 1) * 1ll * (n - r) / 2 + 1;
    for (int i = 1; i < n; i++) {
        auto [nl, nr] = p[i];
        if (!(l <= nl && nl <= r || l <= nr && nr <= r)) {
            if (nl < l && nr > r) {
                ans += (l - nl) * 1ll * (nr - r);
            } else if (nl < l && nr < l) {
                ans += (l - max(nl, nr)) * 1ll * (n - r + 1);
            } else if (nl > r && nr > r) {
                ans += l * 1ll * (min(nl, nr) - r);
            }
        }
        l = min(l, nl);
        r = max(r, nr);
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