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
    vi m(n), c(k); in(m); in(c);

    vi cnt(k + 1, 0);
    rep(i, n) cnt[m[i]]++;

    int ans = 0, p = 0;
    repd(i, k, 0) {
        if (cnt[i]) p += cnt[i];
        ans = max(ans, (p + c[i - 1] - 1) / c[i - 1]);
    }

    vector<vi> a(ans);
    sortd(m);
    rep(i, n) a[i % ans].push_back(m[i]);

    cout << ans << endl;
    for (auto& x: a) {
        cout << ssz(x) << " ";
        out(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}