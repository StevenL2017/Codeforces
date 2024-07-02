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

    auto calc = [&] (vi& nums, int j) -> pair<vi, vi> {
        vi x0, x1;
        for (auto x: nums) {
            if (x >> j & 1) {
                x1.push_back(x);
            } else {
                x0.push_back(x);
            }
        }
        return make_pair(x0, x1);
    };

    vector<vi> cur_a, cur_b;
    cur_a.push_back(a);
    cur_b.push_back(b);
    int ans = 0;
    for (int j = 30; j >= 0; j--) {
        if (cur_a.empty()) break;
        bool ok = true;
        vector<vi> nxt_a, nxt_b;
        for (int i = 0; i < ssz(cur_a); i++) {
            auto [a0, a1] = calc(cur_a[i], j);
            auto [b0, b1] = calc(cur_b[i], j);
            if (ssz(a0) != ssz(b1) || ssz(a1) != ssz(b0)) {
                ok = false;
                break;
            }
            if (!a0.empty()) nxt_a.push_back(a0);
            if (!a1.empty()) nxt_a.push_back(a1);
            if (!b1.empty()) nxt_b.push_back(b1);
            if (!b0.empty()) nxt_b.push_back(b0);
        }
        if (ok) {
            ans |= 1 << j;
            cur_a = nxt_a;
            cur_b = nxt_b;
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