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
    int n; cin >> n;
    vi a(n); in(a);

    vi pre_mx(n + 1, INT_MIN), suf_mx(n + 1, INT_MIN);
    rep(i, n) {
        pre_mx[i + 1] = max(pre_mx[i], a[i]);
    }
    repd(i, n - 1, -1) {
        suf_mx[i] = max(suf_mx[i + 1], a[i]);
    }

    int mx = *max_element(a.begin(), a.end());
    vi idx;
    rep(i, n) {
        if (a[i] == mx) {
            idx.push_back(i);
        }
    }

    int mid = mx, l = idx[ssz(idx) / 2], r = l + 1;
    while (l > 0 && r < n) {
        if (pre_mx[l] == mid && suf_mx[r] == mid) {
            cout << "YES\n";
            cout << l << " " << r - l << " " << n - r << endl;
            return;
        }
        int left = l == 1 ? INT_MIN : min(pre_mx[l - 1], a[l - 1]);
        int right = r == n - 1 ? INT_MIN : min(suf_mx[r + 1], a[r]);
        if (left > right) {
            mid = min(mid, a[l - 1]);
            l--;
        } else {
            mid = min(mid, a[r]);
            r++;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}