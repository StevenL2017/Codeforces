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
    in(a);
    in(b);

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    vector<ll> pre_a(n + 1), pre_b(m + 1);
    for (int i = 0; i < n; i++) {
        pre_a[i + 1] = pre_a[i] + a[n - 1 - i] - a[i];
    }
    for (int i = 0; i < m; i++) {
        pre_b[i + 1] = pre_b[i] + b[m - 1 - i] - b[i];
    }

    vector<ll> ans;
    for (int x = 1; 2 * x - m <= n; x++) {
        ll l = max(0, 2 * x - m), r = min(x, n - x);
        if (l > r) {
            break;
        }
        while (r - l > 3) {
            ll m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
            ll s1 = pre_a[m1] + pre_b[x - m1];
            ll s2 = pre_a[m2] + pre_b[x - m2];
            if (s1 > s2) r = m2;
            else l = m1;
        }
        ll cur = 0;
        for (int i = l; i <= r; i++) {
            ll s = pre_a[i] + pre_b[x - i];
            cur = max(cur, s);
        }
        ans.push_back(cur);
    }

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}