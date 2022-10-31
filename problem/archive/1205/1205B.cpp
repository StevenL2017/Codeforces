#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 1e5 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a;
    rep(i, n) {
        ll x; cin >> x;
        if (x) a.push_back(x);
    }
    
    rep(i, 63) {
        int cnt = 0;
        for (auto& x: a) {
            if (x >> i & 1) cnt++;
            if (cnt >= 3) {
                cout << 3 << endl;
                return;
            }
        }
    }

    n = ssz(a);
    vector<vi> graph(n, vi(n, INF));
    rep(i, n) {
        repa(j, i, n) {
            if (j == i) graph[i][j] = 0;
            else if (a[j] & a[i]) graph[i][j] = graph[j][i] = 1;
        }
    }

    auto dist = graph;
    int ans = INF;
    rep(k, n) {
        rep(i, k) {
            rep(j, i) {
                ans = min(ans, min(INF, dist[i][j] + graph[i][k] + graph[k][j]));
            }
        }
        rep(i, n) {
            rep(j, n) {
                dist[i][j] = min(dist[i][j], min(INF, dist[i][k] + dist[k][j]));
            }
        }
    }

    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}