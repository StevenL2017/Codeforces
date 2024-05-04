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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        int x = a[i], cnt = 0;
        while (x) {
            mp[x].emplace_back(cnt);
            x >>= 1;
            cnt++;
        }
    }

    int ans = 2e9;
    for (auto [x, v] : mp) {
        if (ssz(v) < k) continue;
        sort(v.begin(), v.end());
        ans = min(ans, accumulate(v.begin(), v.begin() + k, 0));
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