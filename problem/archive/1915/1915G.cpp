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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    vi s(n);
    in(s);

    int mx = *max_element(s.begin(), s.end());
    vector<vector<ll>> f(n, vector<ll>(mx + 1, 1e18));
    f[0][s[0]] = 0ll;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0ll, s[0]);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        ll cost = t.first;
        int u = t.second / (mx + 1), mn = t.second % (mx + 1);
        if (f[u][mn] < cost) continue;
        for (auto& [v, w]: e[u]) {
            ll d = f[u][mn] + w * 1ll * mn;
            int nxt = min(mn, s[v]);
            if (d < f[v][nxt]) {
                f[v][nxt] = d;
                pq.emplace(d, v * (mx + 1) + nxt);
            }
        }
    }
    cout << *min_element(f[n - 1].begin(), f[n - 1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}