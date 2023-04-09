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
    int n, q; cin >> n >> q;
    string s; cin >> s;
 
    vi pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i];
        if (s[i] == '+') {
            if (i & 1) pre[i + 1]--;
            else pre[i + 1]++;
        } else {
            if (i & 1) pre[i + 1]++;
            else pre[i + 1]--;
        }
    }

    auto get_sum = [&] (int l, int r) -> int {
        if (l > r) return 0;
        if (l & 1) return pre[r] - pre[l - 1];
        else return pre[l - 1] - pre[r];
    };

    auto check = [&] (int l, int r, int m) -> int {
        if ((m - l + 1) & 1) return get_sum(l, m - 1) + get_sum(m + 1, r);
        else return get_sum(l, m - 1) - get_sum(m + 1, r);
    };
 
    while (q--) {
        int l, r; cin >> l >> r;

        if (get_sum(l, r) == 0) {
            cout << 0 << endl;
        } else {
            bool even = false;
            if ((r - l + 1) % 2 == 0) {
                even = true;
                l++;
            }
            int left = l, right = r, ans = l;
            while (left < right) {
                auto mid = (left + right) / 2;
                auto tot_left = check(l, r, left);
                auto tot_right = check(l, r, right);
                auto tot_mid = check(l, r, mid);
                if (tot_left == 0) {
                    ans = left;
                    break;
                }
                if (tot_right == 0) {
                    ans = right;
                    break;
                }
                if (tot_mid == 0) {
                    ans = mid;
                    break;
                }
                if ((tot_left > 0 ? 1 : -1) == (tot_mid > 0 ? 1 : -1)) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            if (!even) {
                cout << 1 << endl;
                cout << ans << endl;
            } else {
                cout << 2 << endl;
                cout << l - 1 << " " << ans << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}