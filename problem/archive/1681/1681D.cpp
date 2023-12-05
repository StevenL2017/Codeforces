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

int get_len(ll x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

set<int> get_d(ll x) {
    set<int> d;
    while (x) {
        d.insert((int)(x % 10));
        x /= 10;
    }
    return d;
}

void solve() {
    ll n, x;
    cin >> n >> x;

    map<ll, int> memo;
    function<int(ll)> dfs = [&] (ll y) -> int {
        if (get_len(y) == n) return 0;
        if (memo.count(y)) return memo[y];
        int ans = 2e9;
        for (auto d: get_d(y)) {
            if (d <= 1) continue;
            ans = min(ans, dfs(y * d) + 1);
        }
        memo[y] = ans;
        return ans;
    };

    int ans = dfs(x);
    cout << (ans < 2e9 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}