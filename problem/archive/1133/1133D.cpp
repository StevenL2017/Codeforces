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
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a);
    in(b);

    // c = d * a + b
    // d = -b / a
    int zero = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] != 0) {
            continue;
        }
        int sign = 1;
        if (a[i] > 0 && b[i] > 0 || a[i] < 0 && b[i] < 0) {
            sign = -1;
        }
        int x = abs(a[i]), y = abs(b[i]);
        int g = gcd(x, y);
        if (g != 0) {
            cnt[make_pair(sign * x / g, y / g)]++;
        } else {
            zero++;
        }
    }

    int ans = 0;
    for (auto [_, v]: cnt) {
        ans = max(ans, v);
    }
    cout << ans + zero << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}