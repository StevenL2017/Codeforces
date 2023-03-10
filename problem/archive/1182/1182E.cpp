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
const int N = 5;

struct Matrix {
    long long a[N][N];

    Matrix() { memset(a, 0, sizeof(a)); }

    // i k j could be faster than i j k
    Matrix operator*(const Matrix& b) const {
        Matrix res;
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                for (int j = 0; j < N; ++j)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % (MOD - 1);
        return res;
    }
} base;

void init() {
    base.a[0][0] = base.a[0][1] = base.a[0][2] = 1;
    base.a[1][0] = base.a[2][1] = 1;
    base.a[0][3] = 2;
    base.a[3][3] = base.a[3][4] = base.a[4][4] = 1;
}

// n is count of matrix multiplications
Matrix qpow(long long n) {
    Matrix z;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            z.a[i][j] = i == j;

    while (n) {
        if (n & 1) z = z * base;
        base = base * base;
        n >>= 1;
    }
    return z;
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
    ll n; int f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    int res = 1;

    init();
    auto ans = qpow(n - 1);
    res = mul(res, binpow(f1, ans.a[2][2]));
    res = mul(res, binpow(f2, ans.a[2][1]));
    res = mul(res, binpow(f3, ans.a[2][0]));
    res = mul(res, binpow(c, ans.a[1][4]));

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}