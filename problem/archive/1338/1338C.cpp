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

constexpr ll A[] = {0, 2, 3, 1};

void solve() {
    ll n; cin >> n;

    ll c = (n - 1) / 3, s = 1;
    while (c >= s) {
        c -= s;
        s *= 4;
    }

    ll x = s + c, y = s * 2;
    for (int i = 0; (1ll << i) < s; i += 2) {
        y += A[c >> i & 3] << i;
    }

    if (n % 3 == 0) cout << (x ^ y) << endl;
    else if (n % 3 == 1) cout << x << endl;
    else cout << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}