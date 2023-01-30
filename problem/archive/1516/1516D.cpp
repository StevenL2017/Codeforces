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

const int N = 1e5 + 1;

int mn_prime[N + 1], a[N], nxt[N], f[N][20];

void eratosthenes_mn(int n) {
    mn_prime[0] = mn_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = i;
            nxt[i] = n;
            if (i > 10000) continue;
            for (int j = i * i; j <= n; j += i) {
                mn_prime[j] = min(mn_prime[j], i);
            }
        }
    }
}

set<int> get_prime_factors(int x) {
    set<int> ans;
    while (x > 1) {
        auto y = mn_prime[x];
        x /= y;
        ans.insert(y);
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    rep(i, n) cin >> a[i + 1];

    eratosthenes_mn(N);

    f[n + 1][0] = n + 1;
    repd(i, n, 0) {
        f[i][0] = f[i + 1][0];
        for (auto& p: get_prime_factors(a[i])) {
            f[i][0] = min(f[i][0], nxt[p]);
            nxt[p] = i;
        }
    }

    repa(j, 1, 20) {
        repa(i, 1, n + 2) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;

        int ans = 0;
        repd(j, 19, -1) {
            if (f[l][j] <= r) {
                ans += 1 << j;
                l = f[l][j];
            }
        }
        
        cout << ans + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}