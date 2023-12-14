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
    int n, m, d;
    cin >> n >> m >> d;
    vi a(n * m);
    in(a);

    int mod = a.front() % d;
    for (int i = 0; i < n * m; i++) {
        if (a[i] % d != mod) {
            cout << -1 << endl;
            return;
        }
    }

    sort(a.begin(), a.end());
    auto calc = [&] (int x) -> int {
        int ans = 0;
        for (auto y: a) {
            ans += abs(x - y) / d;
        }
        return ans;
    };

    int ans = calc(a[n * m / 2]);
    if (n * m % 2 == 0) {
        ans = min(ans, calc(a[n * m / 2 - 1]));
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