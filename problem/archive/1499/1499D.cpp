#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

const int MAXN = 2e7 + 3;

int mn_prime[MAXN]; // min prime factor
int cnt_prime[MAXN];

void eratosthenes_mn(int n) {
    mn_prime[0] = mn_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = i;
            for (int j = i + i; j <= n; j += i) {
                mn_prime[j] = min(mn_prime[j], i);
            }
        }
    }
}

void count_different_prime_factors(int n) {
    for (int i = 2; i < n; i++) {
        int j = i / mn_prime[i];
        cnt_prime[i] = cnt_prime[j] + (mn_prime[j] != mn_prime[i]);
    }
}

void pre_calc() {
    eratosthenes_mn(MAXN);
    count_different_prime_factors(MAXN);
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
        int k1 = x / i + d;
        if (k1 % c == 0) ans += 1 << cnt_prime[k1 / c];
        if (i * i == x) continue;
        int k2 = i + d;
        if (k2 % c == 0) ans += 1 << cnt_prime[k2 / c];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}