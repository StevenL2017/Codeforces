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
    int n, p; cin >> n >> p;
    vi a(n); in(a);

    sorta(a);
    int mn = a.front(), mx = a.back();
    vi cnt(mx + 1, 0);
    for (auto& x: a) cnt[x]++;
    repa(i, mn + 1, mx + 1) {
        cnt[i] += cnt[i - 1];
    }

    vi ans;
    repa(x, mn, mx) {
        bool ok = true;
        repa(y, x, x + n) {
            int cur;
            if (y > mx) {
                cur = cnt[mx] - (y - x);
            } else {
                cur = cnt[y] - (y - x);
            }
            if (cur < 0 || cur % p == 0) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(x);
    }

    cout << ssz(ans) << endl;
    if (!ans.empty()) out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}