#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<char> ans(n);
    bool valid = true;
    function<pair<char, char>(int, int)> dfs = [&] (int node, int fa) -> pair<char, char> {
        vi cnt(26, 0);
        char top = 'Z', bot = 'A';
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            auto [mx, mn] = dfs(nxt, node);
            cnt[mx - 'A']++;
            top = min(top, mx);
            bot = max(bot, mn);
        }
        if (cnt[0] > 1) {
            valid = false;
            return {'A', 'A'};
        }
        if (cnt[top - 'A'] > 1 || bot == 'Z') {
            ans[node] = (char)(top - 1);
            return {ans[node], ans[node]};
        } else if (cnt[top - 'A'] > 0) {
            ans[node] = (char)(bot + 1);
            return {top, ans[node]};
        } else {
            ans[node] = 'Z';
            return {ans[node], ans[node]};
        }
    };
    dfs(0, -1);

    if (!valid) {
        cout << "Impossible!" << endl;
        return;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}