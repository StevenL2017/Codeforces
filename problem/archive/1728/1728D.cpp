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

int comp(char& a, char& b) {
    return (a < b ? 0 : (a > b ? 2 : 1));
}

void solve() {
    string s; cin >> s;

    int n = ssz(s);
    vector<vi> f(n, vi(n, 1)); // 0 first win, 1 draw, 2 second win
    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            
            if (i + 1 == j) {
                f[i][j] = min(comp(s[i], s[j]), comp(s[j], s[i]));
                continue;
            }

            f[i][j] = 2;

            int cur = 0;
            if (f[i + 1][j - 1] != 1) {
                cur = max(cur, f[i + 1][j - 1]);
            } else {
                cur = max(cur, comp(s[i], s[j]));
            }
            if (f[i + 2][j] != 1) {
                cur = max(cur, f[i + 2][j]);
            } else {
                cur = max(cur, comp(s[i], s[i + 1]));
            }
            f[i][j] = min(f[i][j], cur);

            cur = 0;
            if (f[i + 1][j - 1] != 1) {
                cur = max(cur, f[i + 1][j - 1]);
            } else {
                cur = max(cur, comp(s[j], s[i]));
            }
            if (f[i][j - 2] != 1) {
                cur = max(cur, f[i][j - 2]);
            } else {
                cur = max(cur, comp(s[j], s[j - 1]));
            }
            f[i][j] = min(f[i][j], cur);
        }
    }

    if (f[0][n - 1] == 0) cout << "Alice\n";
    else if (f[0][n - 1] == 2) cout << "Bob\n";
    else cout << "Draw\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}