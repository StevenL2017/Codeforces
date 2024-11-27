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
    int s, t;
    cin >> s >> t;
    s--; t--;

    int m = *max_element(a.begin(), a.end());
    vi minp(m + 1), primes;
    for (int i = 2; i <= m; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > m) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }

    vector<vi> e(m + 1);
    for (int i = 0; i < n; i++) {
        for (int x = a[i]; x > 1; x /= minp[x]) {
            e[minp[x]].push_back(i);
        }
    }

    queue<tuple<int, int, int>> q;
    q.emplace(s, 0, -1);
    vi dist(n + m + 1, -1), prev(n + m + 1);
    while (!q.empty()) {
        auto [u, d, pre] = q.front();
        q.pop();
        if (dist[u] != -1) continue;
        dist[u] = d;
        prev[u] = pre;
        if (u < n) {
            for (int x = a[u]; x > 1; x /= minp[x]) {
                q.emplace(n + minp[x], d + 1, u);
            }
        } else {
            for (auto v: e[u - n]) {
                q.emplace(v, d + 1, u);
            }
        }
    }

    if (dist[t] == -1) {
        cout << -1 << endl;
        return;
    }

    vi ans;
    for (int i = t; i != -1; i = prev[i]) {
        if (i < n) {
            ans.push_back(i + 1);
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}