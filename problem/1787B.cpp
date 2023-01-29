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

    map<int, int> cnt;
    int x = 2, y = n;
    while (x * x <= y) {
        while (y % x == 0) {
            cnt[x]++;
            y /= x;
        }
        x++;
    }
    if (y > 1) cnt[y]++;

    ll ans = 0;
    int mn = INT_MAX;
    for (auto& [k, v]: cnt) {
        if (cnt[k] > 0) {
            mn = min(mn, cnt[k]);
        }
    }
    while (mn < INT_MAX) {
        ll cur = 1;
        int nxt = INT_MAX;
        for (auto& [k, v]: cnt) {
            if (cnt[k] >= mn) {
                cur *= 1ll * k;
                cnt[k] -= mn;
            }
            if (cnt[k] > 0) {
                nxt = min(nxt, cnt[k]);
            }
        }
        ans += cur * 1ll * mn;
        mn = nxt;
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