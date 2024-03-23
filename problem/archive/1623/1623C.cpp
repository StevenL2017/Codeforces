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
    int n; cin >> n;
    vector<ll> a(n); in(a);

    auto check = [&] (ll x) -> bool {
        vector<ll> b = a;
        for (int i = n - 1; i >= 2; i--) {
            if (b[i] - 3 >= x) {
                ll d = min(a[i], (b[i] - x)) / 3;
                b[i - 2] += d * 2;
                b[i - 1] += d;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] < x) return false;
        }
        return true;
    };

    ll left = *min_element(a.begin(), a.end());
    ll right = 2e18;
    ll ans = left;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
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