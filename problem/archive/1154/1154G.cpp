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

    ll ans = LLONG_MAX;
    int fi = 0, se = 0;
    auto mx = *max_element(a.begin(), a.end());
    vi vis(mx + 1, 0), idx(mx + 1, 0);
    rep(i, n) {
        if (vis[a[i]] && a[i] < ans) {
            ans = a[i];
            fi = idx[a[i]];
            se = i + 1;
        }
        vis[a[i]] = 1;
        idx[a[i]] = i + 1;
    }

    for (int g = 1; g <= mx; g++) {
        int x = 0, y = 0, cur_fi = 0, cur_se = 0;
        for (int j = g; j <= mx; j += g) {
            if (vis[j] && x) {
                y = j;
                cur_se = idx[j];
                break;
            }
            else if (vis[j]) {
                x = j;
                cur_fi = idx[j];
            }
        }
        if (x && y) {
            auto cur_ans = (x * 1ll * y) / g;
            if (cur_ans < ans) {
                ans = cur_ans;
                fi = min(cur_fi, cur_se);
                se = max(cur_fi, cur_se);
            }
        }
    }

    cout << fi << " " << se << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}