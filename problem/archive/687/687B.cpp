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

const int MAXN = 1e6 + 3;

int mn_prime[MAXN + 1]; // min prime factor
int cnt_prime[MAXN + 1]; // count of different prime factors
int cnt[MAXN + 1]; // count of different prime factors

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

void count_prime_factors(int x, bool add) {
    int y = mn_prime[x];
    while (y != 1) {
        int cur = 0;
        while (x % y == 0) {
            cur++;
            x /= y;
        }
        if (add) cnt_prime[y] = max(cnt_prime[y], cur);
        else cnt[y] = cur;
        y = mn_prime[x];
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    int mx = *max_element(begin(a), end(a));
    mx = max(mx, k);

    eratosthenes_mn(mx);

    for (auto x: a) {
        count_prime_factors(x, true);
    }

    count_prime_factors(k, false);

    for (int i = 0; i <= k; i++) {
        if (cnt_prime[i] < cnt[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}