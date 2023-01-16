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

void solve() {
    string s; cin >> s;

    int n = ssz(s);
    vector<ll> f(n + 1, 0);
    f[0] = 1;
    rep(i, n) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << endl;
            return;
        }
        f[i + 1] += f[i];
        if (i > 0 && s[i - 1] == 'u' && s[i] == 'u') f[i + 1] += f[i - 1];
        if (i > 0 && s[i - 1] == 'n' && s[i] == 'n') f[i + 1] += f[i - 1];
        f[i + 1] %= MOD;
    }

    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}