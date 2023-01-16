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

const int MAXN = 1.5e7 + 1;

int mn_prime[MAXN + 1]; // min prime factor

void eratosthenes_mn(int n) {
    mn_prime[0] = mn_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = i; // mn_prime[i] = 1; // if consider 1 as min prime
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
        auto y = mn_prime[x]; // auto y = nxt_prime[x];
        x /= y;
        ans.insert(y);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    int g = 0, mx = 0;
    rep(i, n) {
        g = gcd(g, a[i]);
        mx = max(mx, a[i]);
    }

    vi cnt(mx + 1, 0);
    rep(i, n) {
        auto s = get_prime_factors(a[i] / g);
        for (auto& x: s) cnt[x]++;
    }

    int ans = n;
    repa(i, 1, mx + 1) {
        ans = min(ans, n - cnt[i]);
    }

    cout << (ans < n ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_mn(MAXN);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}