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

struct State {
    vi* c;
    int mx;
    int sz() {
        return c->size();
    }
    void add(int i, int val) {
        (*c)[i] += val;
        if ((*c)[i] > (*c)[mx] || (*c)[i] == (*c)[mx] && i > mx) {
            mx = i;
        }
    }
};

State merge(State x, State y) {
    if (x.sz() < y.sz()) swap(x, y);
    State z;
    z.c = x.c;
    z.mx = x.mx;
    int xs = z.sz(), ys = y.sz();
    for (int i = 0; i < ys; i++) {
        x.add(xs - i - 1, (*(y.c))[ys - i - 1]);
    }
    return x;
}

State pull(State x) {
    if (x.sz() == 0) {
        State z;
        z.c = new vi(1, 1);
        z.mx = 0;
        return z;
    } else {
        State z;
        z.c = x.c;
        z.mx = x.mx;
        z.c->push_back(0);
        z.add(z.sz() - 1, 1);
        return z;
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vi ans(n);
    vector<State> s(n);
    function<void(int, int)> dfs = [&] (int node, int fa) {
        s[node].c = new vi(0);
        s[node].mx = 0;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs(nxt, node);
            s[node] = merge(s[node], s[nxt]);
        }
        s[node] = pull(s[node]);
        ans[node] = s[node].sz() - s[node].mx - 1;
    };
    dfs(0, -1);

    rep(i, n) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}