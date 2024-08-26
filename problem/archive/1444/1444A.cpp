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
    ll p, q;
    cin >> p >> q;

    if (p % q) {
        cout << p << endl;
        return;
    }

    map<int, int> cnt;
    int x = 2, y = q;
    while (x * x <= y) {
        while (y % x == 0) {
            cnt[x]++;
            y /= x;
        }
        x++;
    }
    if (y > 1) cnt[y]++;

    ll ans = p, z = p;
    for (auto [k, v]: cnt) {
        int c = 0;
        while (z % k == 0) {
            z /= k;
            c++;
        }
        c = c - v + 1;
        ll x = 1;
        while (c--) {
            x *= k;
        }
        ans = min(ans, x);
    }

    cout << p / ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}