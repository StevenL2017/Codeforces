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

const int MOD = 998244353;

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

    vi right(n, -1);
    vi st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        if (!st.empty()) right[i] = st.back();
        st.push_back(i);
    }

    vector<ll> f(n + 1, 0);
    int idx = n - 1, mn = a.back();
    for (int i = n - 1; i >= 0; i--) {
        if (right[i] == -1) {
            f[i] = add(f[i + 1], add(f[idx + 1], 1));
        } else {
            f[i] = add(f[i + 1], f[right[i]]);
        }
        if (a[i] < mn) {
            mn = a[i];
            idx = i;
        }
    }

    cout << f[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}