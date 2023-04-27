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

const int MAXN = 1e7 + 3;

int mn_prime[MAXN + 1];

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
    int n; cin >> n;
    vi a(n); in(a);

    map<int, int> mp;
    for (auto& x: a) {
        auto cur = get_prime_factors(x);
        for (auto& [k, v]: cur) {
            mp[k] += v;
        }
    }

    int ans = 0, cnt = 0;
    for (auto& [k, v]: mp) {
        ans += v / 2;
        if (v & 1) cnt++;
    }
    ans += cnt / 3;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_mn(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}