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
    vi a(n);
    in(a);

    map<int, int> cnt;
    for (auto x: a) {
        cnt[x]++;
    }
    vi b;
    for (auto [_, v]: cnt) {
        b.push_back(v);
    }

    int m = ssz(b);
    vi f(m + 1, 1e9);
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        vi g = f;
        for (int j = 1; j <= i; j++) {
            int s = f[j - 1] + b[i - 1];
            if (s <= i - j) {
                g[j] = min(g[j], s);
            }
        }
        f = g;
    }

    int ans = m;
    while (f[ans] >= 1e9) {
        ans--;
    }

    cout << m - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}