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

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve() {
    int n;
    cin >> n;

    ll ans = LLONG_MAX;
    function<void(int, int, int, ll)> dfs = [&] (int c, int i, int pre, ll x) {
        if (c == 1) {
            ans = min(ans, x);
            return;
        }
        for (int j = 2; j <= min(c, pre); j++) {
            if (x > 1e18 / primes[i]) {
                break;
            }
            x *= primes[i];
            if (c % j == 0) {
                dfs(c / j, i + 1, j, x);
            }
        }
    };
    dfs(n, 0, n, 1);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}