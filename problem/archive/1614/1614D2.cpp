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

const int MAXN = 2e7 + 3;

int is_prime[MAXN + 1]; // if it is prime
vector<int> primes;

void eratosthenes(int n) {
    for (int i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);
    
    int mx = *max_element(a.begin(), a.end());
    eratosthenes(mx);

    vi cnt(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    for (auto p : primes) {
        for (int x = mx / p; x > 0; x--) {
            cnt[x] += cnt[x * p];
        }
    }

    ll ans = 0;
    vector<ll> f(mx + 1, 0);
    for (int x = 1; x <= mx; x++) {
        ans = max(ans, f[x] + cnt[x] * 1ll * x);
        for (auto p : primes) {
            if (x * p > mx) break;
            f[x * p] = max(f[x * p], f[x] + (cnt[x] - cnt[x * p]) * 1ll * x);
        }
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