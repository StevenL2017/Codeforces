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

const int MAXN = 1e7 + 3;

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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    eratosthenes_mn(MAXN);

    map<int, int> cnt;
    for (auto x: a) {
        cnt[x]++;
    }

    map<int, int> primes_cnt;
    for (auto [k, v]: cnt) {
        int x = k;
        set<int> p;
        while (x > 1) {
            auto y = mn_prime[x];
            x /= y;
            p.insert(y);
        }
        for (auto x: p) {
            primes_cnt[x] += v;
        }
    }

    vi primes;
    vector<ll> pre(1, 0);
    for (auto [k, v]: primes_cnt) {
        primes.push_back(k);
        pre.push_back(pre.back() + v);
    }

    int m; cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        int left = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
        int right = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
        cout << pre[right] - pre[left] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}