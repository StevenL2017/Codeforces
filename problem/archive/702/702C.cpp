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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    in(a); in(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto check = [&] (ll r) -> bool {
        for (int i = 0, j = 0; i < n; i++) {
            while (j < m && b[j] + r < a[i]) {
                j++;
            }
            if (j == m || b[j] - r > a[i]) {
                return false;
            }
        }
        return true;
    };

    int left = 0, right = 2e9;
    int ans = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
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