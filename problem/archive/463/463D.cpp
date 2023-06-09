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
    int n, k; cin >> n >> k;
    vector<vi> a(k, vi(n + 1)), pos(k, vi(n + 1));
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }

    int ans = 0;
    vi f(n, 0);
    for (int j = 1; j <= n; j++) {
        int cur = 0;
        for (int p = 1; p < j; p++) {
            bool ok = true;
            for (int i = 1; i < k; i++) {
                if (pos[i][a[0][p]] > pos[i][a[0][j]]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cur = max(cur, f[p]);
            }
        }
        f[j] = cur + 1;
        ans = max(ans, f[j]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}