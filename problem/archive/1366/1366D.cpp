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

const int MAXN = 1e7 + 1;
int minp[MAXN];

void eratosthenes() {
    vi primes;
    for (int i = 2; i < MAXN; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto& p: primes) {
            if (i * p >= MAXN) break;
            minp[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi ans1(n, -1), ans2(n, -1);
    rep(i, n) {
        vi primes;
        int y = a[i];
        while (y > 1) {
            primes.push_back(minp[y]);
            y /= minp[y];
        }
        if (primes[0] != primes.back()) {
            ans1[i] = 1;
            rep(j, ssz(primes)) {
                if (primes[j] == primes[0]) ans1[i] *= primes[0];
            }
            ans2[i] = a[i] / ans1[i];
        }
    }
    out(ans1);
    out(ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}