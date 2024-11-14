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

    vi ans(n);
    function<bool(int, int)> dfs = [&] (int i, int m) -> bool {
        if (i == n) {
            return m == 0;
        }
        for (int x = 3; x <= 6; x += 3) {
            if (dfs(i + 1, (m * 10 + x) % 66)) {
                ans[i] = x;
                return true;
            }
        }
        return false;
    };

    auto ok = dfs(0, 0);
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}