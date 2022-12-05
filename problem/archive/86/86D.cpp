#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

struct Q {
    int l, r, idx;
};

void solve() {
    int n, t; cin >> n >> t;
    vi a(n); in(a);
    vector<Q> q(t);
    for (int i = 0; i < t; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }

    int s = sqrt(n);
    auto cmp = [&] (const Q& x, const Q& y) -> bool {
        if (x.l / s != y.l / s) return x.l < y.l;
        return x.r < y.r;
    };
    sort(q.begin(), q.end(), cmp);

    vector<ll> ans(t);
    vi cnt(1e6 + 1, 0);
    ll tot = 0;
    int l = 0, r = -1;
    for (int i = 0; i < t; i++) {
        while (l < q[i].l) {
            cnt[a[l]]--;
            tot -= 1ll * a[l] * (2 * cnt[a[l]] + 1);
            l++;
        }
        while (l > q[i].l) {
            l--;
            tot += 1ll * a[l] * (2 * cnt[a[l]] + 1);
            cnt[a[l]]++;
        }
        while (r < q[i].r) {
            r++;
            tot += 1ll * a[r] * (2 * cnt[a[r]] + 1);
            cnt[a[r]]++;
        }
        while (r > q[i].r) {
            cnt[a[r]]--;
            tot -= 1ll * a[r] * (2 * cnt[a[r]] + 1);
            r--;
        }
        ans[q[i].idx] = tot;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}