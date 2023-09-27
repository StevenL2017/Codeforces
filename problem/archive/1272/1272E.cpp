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
    int n; cin >> n;
    vi a(n); in(a);

    vi odd, even;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) odd.push_back(i);
        else even.push_back(i);
    }

    vector<vi> e(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            e[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            e[i + a[i]].push_back(i);
        }
    }

    vi ans(n, -1);
    auto bfs = [&] (const vi& start, const vi& end) {
        queue<int> q;
        vi cur(n, INT_MAX);
        for (auto u : start) {
            q.emplace(u);
            cur[u] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : e[u]) {
                if (cur[v] == INT_MAX) {
                    cur[v] = cur[u] + 1;
                    q.emplace(v);
                }
            }
        }
        for (auto v : end) {
            if (cur[v] < INT_MAX) {
                ans[v] = cur[v];
            }
        }
    };
    bfs(odd, even);
    bfs(even, odd);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}