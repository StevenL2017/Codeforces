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
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); in(a);
    vi b(n); in(b);

    vector<vi> graph(n);
    rep(i, n) {
        if (b[i] != -1) {
            graph[b[i] - 1].push_back(i);
        }
    }

    ll ans = 0;
    vector<int> pos, neg, visited(n, 0);
    function<void(int)> dfs = [&] (int node) {
        visited[node] = 1;
        for (auto& nxt: graph[node]) {
            if (visited[nxt]) continue;
            dfs(nxt);
        }

        ans += a[node];
        if (b[node] != -1 && a[node] > 0) {
            a[b[node] - 1] += a[node];
        }

        if (a[node] > 0) pos.push_back(node);
        else neg.push_back(node);
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(neg.begin(), neg.end());

    cout << ans << endl;
    for (auto& i: pos) {
        cout << i + 1 << " ";
    }
    for (auto& i: neg) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}