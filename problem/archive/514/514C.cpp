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

const int N = 6e5;
const ll BASE = 5, MOD = 1e12 + 39;
ll mul[N + 1];

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n); in(a);

    mul[0] = 1;
    for (int i = 1; i <= N; i++) {
        mul[i] = mul[i - 1] * BASE % MOD;
    }

    vector<ll> h;
    for (auto s: a) {
        ll x = 0;
        for (int i = 0; i < ssz(s); i++) {
            x = (x * BASE + s[i] - 'a' + 1) % MOD;
        }
        h.push_back(x);
    }
    sort(h.begin(), h.end());

    while (m--) {
        string s; cin >> s;

        ll x = 0;
        for (int i = 0; i < ssz(s); i++) {
            x = (x * BASE + s[i] - 'a' + 1) % MOD;
        }

        bool ok = false;
        for (int i = 0; i < ssz(s); i++) {
            for (int c = 'a'; c <= 'c'; c++) {
                if (c == s[i]) continue;
                auto nx = (x + (c - s[i]) * mul[ssz(s) - i - 1] % MOD + MOD) % MOD;
                if (*lower_bound(h.begin(), h.end(), nx) == nx) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}