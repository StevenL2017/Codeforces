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

const int MOD = 1e9 + 7;
const int N = 100;

struct Matrix {
    long long a[N + 3][N + 3];

    Matrix() { memset(a, 0, sizeof(a)); }

    // i k j could be faster than i j k
    Matrix operator*(const Matrix& b) const {
        Matrix res;
        for (int i = 1; i <= N; ++i)
            for (int k = 1; k <= N; ++k)
                for (int j = 1; j <= N; ++j)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return res;
    }
} ans, base;

// this is an example of f[n] = f[n - 1] + f[n - m]
// answer is sum(ans.a[1][i])
void init(int m) {
    base.a[1][1] = base.a[m][1] = 1;
    ans.a[1][1] = ans.a[m][1] = 1;
    for (int i = 2; i <= m; i++) {
        base.a[i - 1][i] = 1;
        ans.a[i - 1][i] = 1;
    }
}

// n is count of matrix multiplications
void qpow(long long n) {
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
}

void solve() {
    ll n, m; cin >> n >> m;

    if (n < m) {
        cout << 1 << endl;
        return;
    }

    init(m);
    qpow(n - m);

    ll tot = 0;
    repa(i, 1, m + 1) {
        tot += ans.a[1][i];
        tot %= MOD;
    }
    cout << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}