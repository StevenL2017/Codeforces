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

int n;

int add(int x, int y) {
    x += y;
    while (x >= n) x -= n;
    while (x < 0) x += n;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % n;
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

int inv(int x) {
    return binpow(x, n - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}

void solve() {
    cin >> n;

    bool prime = true;
    int x = 2;
    while (x * x <= n) {
        if (n % x == 0) {
            prime = false;
            break;
        }
        x++;
    }

    if (n > 4 && !prime) {
        cout << "NO\n";
        return;
    }

    vi ans(n, 1);
    repa(i, 2, n + 1) {
        ans[i - 1] = divide(i, i - 1);
        if (!ans[i - 1]) ans[i - 1] = n;
    }

    if (n == 4) {
        ans = {1, 3, 2, 4};
    }

    cout << "YES\n";
    rep(i, n) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}