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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    int ans = 1, cnt = 0;
    map<int, int> primes, masks;
    vi t(19);
    for (int i = 0; i < n; i++) {
        int x = a[i], mask = 0;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                if (primes.find(j) == primes.end()) {
                    primes[j] = cnt++;
                }
                while (x % j == 0) {
                    mask ^= 1 << primes[j];
                    x /= j;
                }
            }
        }
        if (x > 1) {
            if (primes.find(x) == primes.end()) {
                primes[x] = cnt++;
            }
            mask ^= 1 << primes[x];
        }
        
        for (int j = 0; j < 19; j++) {
            if (mask >> j & 1) {
                if (t[j]) {
                    mask ^= t[j];
                } else {
                    t[j] = mask;
                    break;
                }
            }
        }
        if (mask == 0) {
            ans = mul(ans, 2);
        }
    }

    cout << sub(ans, 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}