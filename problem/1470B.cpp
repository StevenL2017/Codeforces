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

const int MAXN = 1e6 + 3;

int mn_prime[MAXN]; // min prime factor

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

int calc(int x) {
    map<int, int> cnt;
    while (x > 1) {
        auto y = mn_prime[x]; // auto y = nxt_prime[x];
        x /= y;
        cnt[y]++;
    }

    int ans = 1;
    for (auto& [k, v]: cnt) {
        if (v & 1) ans *= k;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    map<int, int> cnt;
    for (auto& x: a) {
        cnt[calc(x)]++;
    }

    int mx = 0, c = 0;
    for (auto& [k, v]: cnt) {
        mx = max(mx, v);
        if (k == 1 || v % 2 == 0) c += v;
    }

    int q; cin >> q;
    while (q--) {
        int w; cin >> w;

        if (w == 0) {
            cout << mx << endl;
        } else {
            cout << max(mx, c) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_mn(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}