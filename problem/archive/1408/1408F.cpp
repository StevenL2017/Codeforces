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

    int idx = 0;
    rep(i, 25) {
        if ((1 << i) > n) {
            idx = i - 1;
            break;
        }
    }

    vector<pair<int, int>> ans;
    function<void(int, int)> dfs = [&] (int l, int r) {
        if (l == r) {
            return;
        }

        auto mid = (l + r) / 2;
        dfs(l, mid);
        dfs(mid + 1, r);

        int m = r - mid;
        for (int i = 0; i < m; i++) {
            ans.emplace_back(l + i, mid + 1 + i);
        }
    };
    dfs(1, 1 << idx);
    if (1 << idx < n) dfs(n - (1 << idx) + 1, n);

    cout << ssz(ans) << endl;
    for (auto& [f, s]: ans) {
        cout << f << " " << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}