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

const int MAXN = 5e6 + 3;

// int primes[MAXN];
// int is_prime[MAXN];
int mn_prime[MAXN];

// int eratosthenes(int n) {
//     int p = 0; // count of primes for less or equal than n
//     is_prime[0] = is_prime[1] = 0; // if is prime
//     for (int i = 2; i <= n; i++) {
//         is_prime[i] = 1;
//     }
//     for (int i = 2; i <= n; i++) {
//         if (is_prime[i]) {
//             primes[p++] = i;
//             if ((long long)i * i <= n) {
//                 for (int j = i * i; j <= n; j += i) {
//                     is_prime[i] = 0;
//                 }
//             }
//         }
//     }
//     return p;
// }

void eratosthenes(int n) {
    mn_prime[0] = mn_prime[1] = 1; // min prime factor
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = 1;
            for (int j = i + i; j <= n; j += i) {
                mn_prime[j] = min(mn_prime[j], i);
            }
        }
    }
}

long long count_prime_factors(int x) {
    long long ans = 1, y = mn_prime[x];
    while (y != 1) {
        x /= y;
        y = mn_prime[x];
        ans++;
    }
    return ans;
}

ll pre[MAXN];

void pre_calc() {
    eratosthenes(MAXN);
    repa(i, 1, MAXN) {
        pre[i] = pre[i - 1] + count_prime_factors(i);
    }
}

void solve() {
    int a, b; cin >> a >> b;
    cout << pre[a] - pre[b] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}