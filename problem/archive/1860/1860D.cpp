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
    string s; cin >> s;

    int n = ssz(s);
    int c1 = count(s.begin(), s.end(), '1'), c0 = n - c1;
    int need = (n * (n - 1) / 2 - c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2) / 2;

    vector<vi> f(c1 + 1, vi(need + 1, 1e9));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = c1 - 1; j >= 0; j--) {
            for (int k = 0; k + i <= need; k++) {
                f[j + 1][k + i] = min(f[j + 1][k + i], f[j][k] + (s[i] == '0'));
            }
        }
    }

    cout << f[c1][need] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}