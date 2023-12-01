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
const int N = 10;

struct Matrix {
    long long a[N + 3][N + 3];

    Matrix() { memset(a, 0, sizeof(a)); }

    // i k j could be faster than i j k
    Matrix operator*(const Matrix& b) const {
        Matrix res;
        for (int i = 1; i <= N; ++i)
            for (int k = 1; k <= N; ++k)
                for (int j = 1; j <= N; ++j)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j] + MOD) % MOD;
        return res;
    }
} ans, base;

// f[n] = f[n - 1] - f[n - 2]
// answer is ans.a[1][1]
void init(int x, int y) {
    base.a[1][1] = base.a[1][2] = 1;
    base.a[2][1] = -1;
    ans.a[1][1] = y;
    ans.a[1][2] = x;
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
    int x, y, n;
    cin >> x >> y >> n;

    init(x, y);
    if (n > 1) qpow(n - 2);

    if (n == 1) cout << (ans.a[1][2] + MOD) % MOD << endl;
    else cout << (ans.a[1][1] + MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}