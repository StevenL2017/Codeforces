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

const int MAXN = 200 + 10;
const int INF = 1 << 30;

template <typename T> class Dinic {
    private:
        int n, s, t, cnt, level[MAXN];
        T w[MAXN][MAXN];
        bool bfs() {
            memset(level, -1, sizeof(level));
            queue<int> que; que.push(s);
            level[s] = 0;
            while (que.size()) {
                int tmp = que.front(); que.pop();
                for (int i = 0; i < n; ++i) if (w[tmp][i] > 0) {
                    if (level[i] == -1) {
                        level[i] = level[tmp] + 1;
                        que.push(i);
                    }
                }
            }
            return level[t] != -1;
        }
        T flow(int now, T low) {
            T res = 0;
            if (now == t) return low;
            for (int i = 0; i < n && res < low; ++i) if (w[now][i] > 0) {
                if (level[i] == level[now] + 1) {
                    T tmp = flow(i, min(w[now][i], low - res));
                    w[now][i] -= tmp; w[i][now] += tmp;
                    res += tmp;
                }
            }
            if (!res) level[now] = -1;
            return res;
        }
    public:
        Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
            memset(w, 0, sizeof(w));
        }
        void add_edge(int a, int b, T flow) {
            w[a][b] = flow;
        }
        T max_flow() {
            long long ans = 0;
            while (bfs()) ans += flow(s, INF);
            return ans;
        }
        vector<vector<T>> get_w() {
            vector<vector<T>> ret;
            for (int i = 0; i < n; ++i) {
                ret.push_back(vector<T>());
                for (int j = 0; j < n; ++j) ret[i].push_back(w[i][j]);
            }
            return ret;
        }
};

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(n); in(a); in(b);

    int s = n * 2, t = s + 1;
    Dinic<int> dinic(n * 2 + 2, s, t);
    int tot_a = 0, tot_b = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) dinic.add_edge(s, i, a[i]);
        tot_a += a[i];
        if (b[i]) dinic.add_edge(i + n, t, b[i]);
        tot_b += b[i];
        dinic.add_edge(i, i + n, INF);
    }

    if (tot_a != tot_b) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        dinic.add_edge(u, v + n, INF);
        dinic.add_edge(v, u + n, INF);
    }

    auto flow = dinic.max_flow();
    if (flow != tot_b) {
        cout << "NO\n";
        return;
    }

    auto w = dinic.get_w();

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (w[i][j + n] == 0 ? 0 : INF - w[i][j + n]) << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}