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
const int MAXN = 1e6 + 3;

int is_prime[MAXN + 1]; // if it is prime
int sign[MAXN + 1];

void eratosthenes(int n) {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= n; j += i) {
                is_prime[j] = i == j;
                if ((j / i) % i == 0) {
                    sign[j] = 0;
                } else {
                    sign[j] *= -1;
                }
            }
        }
    }
}

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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    fill(sign, sign + MAXN, 1);
    eratosthenes(MAXN);

    vi pow2(MAXN, 1);
    for (int i = 1; i < MAXN; i++) {
        pow2[i] = mul(pow2[i - 1], 2);
    }

    vi cnt(MAXN, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = i + i; j < MAXN; j += i) {
            cnt[i] += cnt[j];
        }
    }

    int ans = 0;
    for (int i = 2; i < MAXN; i++) {
        int cur = 0;
        for (int j = i; j < MAXN; j += i) {
            cur = add(cur, sign[j / i] * mul(cnt[j], pow2[cnt[j] - 1]));
        }
        ans = add(ans, mul(cur, i));
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