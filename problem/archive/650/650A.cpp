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
    map<int, int> cnt_x, cnt_y;
    map<pair<int, int>, int> cnt_xy;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cnt_x[x]++;
        cnt_y[y]++;
        cnt_xy[make_pair(x, y)]++;
    }

    ll ans = 0;
    for (auto [_, v]: cnt_x) {
        ans += v * 1ll * (v - 1) / 2;
    }
    for (auto [_, v]: cnt_y) {
        ans += v * 1ll * (v - 1) / 2;
    }
    for (auto [_, v]: cnt_xy) {
        ans -= v * 1ll * (v - 1) / 2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}