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
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    in(a); in(b);

    auto check = [&] (ll x) -> bool {
        vector<ll> c = a;
        vector<vi> q(k);
        for (int i = 0; i < n; i++) {
            ll t = c[i] / b[i] + 1;
            c[i] %= b[i];
            if (t < k) q[t].push_back(i);
        }

        for (int i = 0, j = 0; i < k; i++) {
            while (j < k && q[j].empty()) {
                j++;
            }
            if (j <= i) {
                return false;
            }
            if (j == k) {
                return true;
            }
            auto idx = q[j].back();
            if (c[idx] + x < b[idx]) {
                c[idx] += x;
                continue;
            }
            q[j].pop_back();
            auto nt = j + (c[idx] + x) / b[idx];
            c[idx] = (c[idx] + x) % b[idx];
            if (nt < k) q[nt].push_back(idx);
        }
        return true;
    };

    ll left = 0, right = 1e18, ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << (ans < 1e18 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}