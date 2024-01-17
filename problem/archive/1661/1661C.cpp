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

ll calc(vi& a, int mx) {
    ll even = 0, odd = 0;
    for (auto x: a) {
        auto d = mx - x;
        even += d / 2;
        odd += d & 1;
    }

    ll ans = odd * 2 - 1;
    even = max(0ll, even - odd + 1);
    ans += even / 3 * 4;
    ans += (even % 3 == 1 ? 1 : (even % 3 == 2 ? 3 : 0));
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    int mx = *max_element(a.begin(), a.end());
    auto ans = calc(a, mx);
    ans = min(ans, calc(a, mx + 1));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}