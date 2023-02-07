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

const int N = 5e5 + 3;
const int K = 18;

int nxt[N];
int f[N][K];

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n), q(m);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }
    rep(i, m) {
        cin >> q[i].first >> q[i].second;
    }

    sorta(a);
    pair<int, int> mx(0, -1);
    for (int i = 0, j = 0; i < N; i++) {
        while (j < n && a[j].first == i) {
            mx = max(mx, make_pair(a[j].second, j));
            j++;
        }
        nxt[i] = (mx.first <= i ? -1 : mx.second);
    }

    rep(i, n) {
        f[i][0] = nxt[a[i].second];
    }
    repa(j, 1, K) {
        rep(i, n) {
            if (f[i][j - 1] == -1) {
                f[i][j] = -1;
            } else {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }
    }

    rep(i, m) {
        int x = nxt[q[i].first];

        if (x == -1) {
            cout << -1 << endl;
            continue;
        }

        int ans = 1;
        repd(j, K - 1, -1) {
            int y = f[x][j];
            if (y == -1) continue;
            if (a[y].second < q[i].second) {
                ans += 1 << j;
                x = y;
            }
        }

        if (a[x].second >= q[i].second) {
            cout << ans << endl;
        }
        else if (f[x][0] == -1) {
            cout << -1 << endl;
        }
        else {
            cout << ans + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}