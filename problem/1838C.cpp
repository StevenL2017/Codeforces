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

const int MAXN = 1e3 + 3;

int primes[MAXN + 1]; // list of primes
int is_prime[MAXN + 1]; // if it is prime

int eratosthenes(int n) {
    int p = 0; // count of primes for less or equal than n
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[p++] = i;
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
    return p;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vi> ans(n, vi(m, 0));
    if (!is_prime[n]) {
        int k = 1;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = k++;
            }
        }
    }
    else if (!is_prime[m]) {
        int k = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = k++;
            }
        }
    }
    else {
        if (n <= m) {
            int k = 1;
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i][j] = k++;
                }
                if (k > m * n) {
                    k = n + 1;
                } else {
                    k += n;
                }
            }
        } else {
            int k = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = k++;
                }
                if (k > m * n) {
                    k = m + 1;
                } else {
                    k += m;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        out(ans[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}