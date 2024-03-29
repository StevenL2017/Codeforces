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
    vi a(n); in(a);

    auto check = [&] (int x) -> bool {
        int cnt = k;
        vi b = a;
        rep(i, n) {
            if (b[i] * 2 < x) {
                b[i] = 1e9;
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        int mx = *max_element(b.begin(), b.end());
        if (cnt == 1 && mx >= x || cnt > 1) {
            return true;
        }
        if (cnt == 1 && mx < x) {
            return false;
        }
        int cur = 0;
        rep(i, n - 1) {
            cur = max(cur, min(b[i], b[i + 1]));
        }
        return cur >= x;
    };

    int left = 1, right = 1e9, ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
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