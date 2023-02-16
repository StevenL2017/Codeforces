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
    ll n, l, r;
    cin >> n >> l >> r;

    vector<ll> pre(n + 1, 0);
    repa(i, 1, n + 1) {
        pre[i] = (n - i) * 2;
    }
    repa(i, 1, n + 1) {
        pre[i] += pre[i - 1];
    }

    vi ans;
    int idx = lower_bound(pre.begin(), pre.end(), l) - pre.begin();
    int base = idx, d = (l - pre[idx - 1] + 1) / 2, flag = (l - pre[idx - 1]) % 2;
    if (!flag) {
        ans.push_back(base + d);
        d++;
        r--;
    }
    while (l <= r && base < n) {
        while (base + d <= n) {
            ans.push_back(base);
            r--;
            if (l > r) break;
            ans.push_back(base + d);
            r--;
            if (l > r) break;
            d++;
        }
        base++;
        d = 1;
    }
    if (l <= r) {
        ans.push_back(1);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}