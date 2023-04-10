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

const int MAXN = 1e5 + 3;

int mn_prime[MAXN]; // min prime factor

void eratosthenes_mn(int n) {
    mn_prime[0] = mn_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = i;
            if (i > 10000) continue;
            for (int j = i * i; j <= n; j += i) {
                mn_prime[j] = min(mn_prime[j], i);
            }
        }
    }
}

map<int, int> get_prime_factors(int x) {
    map<int, int> ans;
    while (x > 1) {
        auto y = mn_prime[x];
        x /= y;
        ans[y]++;
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    int mx = *max_element(a.begin(), a.end());
    eratosthenes_mn(mx);

    ll ans = 0;
    map<ll, int> cnt;
    for (auto& x: a) {
        ll pos = 1, neg = 1;
        auto cur = get_prime_factors(x);
        for (auto& [key, val]: cur) {
            pos *= pow(key, val % k);
            neg *= pow(key, (k - val % k) % k);
        }
        ans += cnt[neg];
        cnt[pos]++;
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