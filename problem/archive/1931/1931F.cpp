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
    int n, k;
    cin >> n >> k;
    vector<vi> a(k, vi(n));
    for (int i = 0; i < k; i++) {
        in(a[i]);
    }

    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < k; i++) {
        for (int j = 2; j < n; j++) {
            e[a[i][j - 1] - 1].push_back(a[i][j] - 1);
            deg[a[i][j] - 1]++;
        }
    }

    queue<int> q;
    vi vis(n);
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v: e[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}