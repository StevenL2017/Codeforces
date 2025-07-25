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

const int MAXN = 1e5 + 3;

vi primes;
int is_prime[MAXN + 1];

int eratosthenes(int n) {
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
    int n;
    cin >> n;

    vi ans(n);
    for (int i = ssz(primes) - 1; i >= 0; i--) {
        vi cycle;
        for (int j = primes[i]; j <= n; j += primes[i]) {
            if (ans[j - 1]) {
                continue;
            }
            cycle.push_back(j);
        }
        for (int j = 0; j < ssz(cycle); j++) {
            ans[cycle[j] - 1] = cycle[(j + 1) % ssz(cycle)];
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            continue;
        }
        ans[i] = i + 1;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}