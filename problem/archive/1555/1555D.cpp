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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<vector<vi>> pre(n + 1, vector<vi>(3, vi(3, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                pre[i + 1][j][k] = pre[i][j][k];
            }
        }
        pre[i + 1][s[i] - 'a'][i % 3]++;
    }

    while (m--) {
        int l, r; cin >> l >> r;

        if (l == r) {
            cout << 0 << endl;
            continue;
        } else if (l + 1 == r) {
            if (s[l - 1] == s[r - 1]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }

        int ans = r - l + 1;
        vi p{0, 1, 2};
        do {
            int cur = 0;
            for (int j = 0; j < 3; j++) {
                cur += pre[r][p[j]][(l - 1 + j) % 3] - pre[l - 1][p[j]][(l - 1 + j) % 3];
            }
            ans = min(ans, r - l + 1 - cur);
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}