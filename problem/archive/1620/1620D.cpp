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
    vi a(n);
    in(a);

    auto check_val = [&] (int v, int c1, int c2, int c3) -> bool {
        for (int i = 0; i <= c1; i++) {
            for (int j = 0; j <= c2; j++) {
                if (i + 2 * j > v) continue;
                auto r = v - i - 2 * j;
                if (r % 3) continue;
                if (r / 3 <= c3) return true;
            }
        }
        return false;
    };

    auto check = [&] (int c1, int c2, int c3) -> bool {
        for (auto v: a) {
            if (!check_val(v, c1, c2, c3)) {
                return false;
            }
        }
        return true;
    };

    int mx = *max_element(a.begin(), a.end());
    int ans = mx / 3 + 10;
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            int c3 = (mx - c1 - 2 * c2 + 2) / 3;
            if (check(c1, c2, c3)) {
                ans = min(ans, c1 + c2 + c3);
            }
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