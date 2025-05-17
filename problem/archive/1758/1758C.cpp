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

const int MAXN = 2e5 + 3;

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

multiset<int> get_prime_factors(int x) {
    multiset<int> ans;
    while (x > 1) {
        auto y = mn_prime[x];
        x /= y;
        ans.insert(y);
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;

    if (n % x) {
        cout << -1 << endl;
        return;
    }

    vi ans(n);
    iota(begin(ans), end(ans), 1);
    ans[0] = x;
    ans[n - 1] = 1;

    auto s = get_prime_factors(n / x);
    int cur = x - 1;
    for (auto p: s) {
        ans[cur] = x * p;
        x *= p;
        cur = x - 1;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_mn(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}