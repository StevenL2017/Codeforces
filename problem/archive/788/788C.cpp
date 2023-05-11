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

void solve() {
    int n, k; cin >> n >> k;
    vi a(k); in(a);

    sorta(a);
    a.erase(unique(a.begin(), a.end()), a.end());

    if (n < a.front() || n > a.back()) {
        cout << -1 << endl;
        return;
    }

    queue<int> q;
    vi f(1000 + 10, -1);
    rep(i, ssz(a)) {
        if (a[i] == n) {
            cout << 1 << endl;
            return;
        }
        q.push(a[i]);
        f[a[i]] = 1;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& x: a) {
            int v = u + x - n;
            if (0 <= v && v <= 1000 && f[v] == -1) {
                f[v] = f[u] + 1;
                q.push(v);
            }
        }
    }

    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}