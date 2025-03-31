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

int m;
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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    set<int> s;
    for (auto x: a) {
        for (int i = 0; i < m; i++) {
            int p = primes[i];
            if (x == 1 || p * p > x) {
                break;
            }
            if (x % p == 0) {
                if (s.count(p)) {
                    cout << "YES" << endl;
                    return;
                }
                s.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            if (s.count(x)) {
                cout << "YES" << endl;
                return;
            }
            s.insert(x);
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    m = eratosthenes(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}