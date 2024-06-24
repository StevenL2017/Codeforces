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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    ll s = 0;
    for (auto [_, h]: a) {
        s += h;
    }

    vector<ll> f(s + 1, -1);
    f[0] = 0;
    for (auto [c, h]: a) {
        for (int i = s; i >= 0; i--) {
            if (f[i] == -1) continue;
            if (f[i] >= c) {
                f[i + h] = max(f[i + h], f[i] + x - c);
            }
            f[i] += x;
        }
    }

    for (int i = s; i >= 0; i--) {
        if (f[i] >= 0) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}